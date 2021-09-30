#!/usr/bin/env python3

import asyncio
from time import sleep
import pickle
import websockets
import os
import logging

# Protocol buffers
from protobufs.python import defs_pb2
from protobufs.python import enums_pb2
from protobufs.python import register_viewer_pb2
from protobufs.python import file_info_pb2

# Util
from util.message_header import *
from util.message_provider import *

# Fits file reader
from astropy.io import fits

# GraphLoader python file
from daliuge_backend.GraphLoader import *


""" A server class that uses websockets to accept an incoming connection """
class DaliugeServer:

    def __init__(self, graphSpec, ramSplit, port):
        self.graphSpec = os.path.normpath("src/graphs/" + str(graphSpec)) # Path to the graph file
        self.statsPath = os.path.normpath("../../workspace/Statistics") # Path to the Statistics output file
        self.histPath = os.path.normpath("../../workspace/Histogram") # Path to the Statistics output file
        self.dataDir = "../../testdata/" # Directory where to look for the specified FITS file
        self.ramSplit = ramSplit # Split of data to be in memory at a given time (excluding memmapping)
        self.stats = None
        self.hist = None
        
        # Checking if the graph specification file exists
        if not os.path.exists(self.graphSpec):
            raise FileNotFoundError("Graph specification not found.")

        # Attempt to start to the server
        try:
            print("Waiting for connection.")
            self.start_server = websockets.serve(self.host, "localhost", port, ping_interval = None)
            asyncio.get_event_loop().run_until_complete(self.start_server)
            asyncio.get_event_loop().run_forever()
        except Exception as e:
            print("Failed to start server. Exception:", e)
            exit(0)

    # Host function which awaits incoming connection, registers viewer and creates a session per client.
    async def host(self, websocket, port):
        try:
            message = await websocket.recv()
            messageType, messageId, messagePayload = strip_message_header(message)
            self.sessionId = messageId

            # Using received session ID to get register viewer acknowledge 
            ack, ack_type = construct_register_viewer_ack(int(self.sessionId))
            if(ack.success):
                print("Successfully connected with session:", self.sessionId)
                # Initialise GraphLoader class with clients session ID and the chosen graph file
                self.graphLoader = GraphLoader(self.sessionId, self.graphSpec, self.ramSplit)
            else:
                print("Failed to connect with session:", self.sessionId)

            # Sending register viewer ack
            await websocket.send(add_message_header(ack,ack_type))
            # Running receiver event loop to receive messages and pass to the consumer
            await self.receiver(websocket, message)
        except:
            print("Client connection interrupted.")

    # Receiver function to wait for messages and pass to the consumer
    async def receiver(self, websocket, message):
        try:
            # Loop to receive and handle messages after initial setup
            async for message in websocket:
                await self.consumer(websocket, message)
        except Exception as e:
            print("Error receiving messages from client.")
            await websocket.close()
            exit(0)

    # Consumer function that will receive every message from the receiver and handle it.
    async def consumer(self, websocket, message):
        try:
            messageType, messageId, messagePayload = strip_message_header(message)
            # Getting the protobuffer type for response
            handler = self.MESSAGE_TYPE_CODE_TO_EVENT_HANDLER.get(messageType)
            # Await response
            await handler(self, websocket, messagePayload)
        except Exception as e:
            print("Unable to process message from client. Exception:", e)
            await websocket.send("Failed")
            await self.receiver(websocket, message)


    def executeGraph(self, file):
        """ 
        Method to handle the execution of the graph using the GraphLoader file
        Also checks if the output files exist before executing a new session
        """
        # If a previous output file exists, delete it 
        if os.path.exists(self.statsPath):
            os.remove(self.statsPath)
        if os.path.exists(self.histPath):
            os.remove(self.histPath)

        # Begin the execution of the session graph
        result = self.graphLoader.createSession(file)

        # If graphLoader fails in any way, return code 0 
        if result == 0:
            return 0
        # Wait until the daliuge-engine has finished executing the graph
        while (os.path.exists(self.statsPath) == False) or (os.path.exists(self.histPath) == False):
            sleep(1)
        
        try:
            # Load and unpickle the data from file
            with open(self.statsPath, "rb") as pkl:
                self.stats = pickle.load(pkl)
            with open(self.histPath, "rb") as pkl:
                self.hist = pickle.load(pkl)
            return 1
        except:
            print("Failed to open one or more output files.")
            return 0


    ### Handling Protocol Buffers ###
    #    Author: Dylan Fouche
    #    Date: 09/08/2021
    #    Availability: https://github.com/DylanFouche/CADaFloP.git
    async def on_open_file(self, ws, msg):
        """Handle the OPEN_FILE message.

        :param ws: the client websocket object
        :param msg: the client message recieved

        """
        file = os.path.normpath(self.dataDir + msg.file)
        
        ack, ack_type = construct_open_file_ack()
        try:
            with fits.open(file, memmap=True) as f:
                # FILE INFO
                ack.file_info.name = msg.file
                ack.file_info.type = enums_pb2.FileType.FITS
                ack.file_info.size = os.path.getsize(file)
                # FILE INFO EXTENDED
                ack.file_info_extended.dimensions = f[0].header['NAXIS']
                ack.file_info_extended.width = f[0].header['NAXIS1']
                ack.file_info_extended.height = f[0].header['NAXIS2']
                ack.file_info_extended.depth = 1

            # Call method to execute and wait till the graph finishes, passing in file name
            code = self.executeGraph(msg.file)
            if code == 0:
                print("The graph failed to be executed.")
                ack.success = False
                await ws.send(add_message_header(ack, ack_type))
                await ws.close()
                exit(0)
        except:
            ack.success = False
        
        try:
            # Send protocol buffer ack
            await ws.send(add_message_header(ack, ack_type))

            # If the full on_open_file was a success, send the histogram immediately
            if ack.success:
                histo, histo_type = construct_region_histogram_data(
                        self.hist.get("numBins"), self.hist.get("hist"), self.hist.get("binWidth"), self.stats.get("mean"), self.stats.get("stddev"))
                await ws.send(add_message_header(histo, histo_type))
        except:
            print("Error sending data to client.")

    #    Author: Dylan Fouche
    #    Date: 09/08/2021
    #    Availability: https://github.com/DylanFouche/CADaFloP.git
    async def on_set_histogram_requirements(self, ws, msg):
        """Handle the SET_HISTOGRAM_REQUIREMENTS message.

        :param ws: the client websocket object
        :param msg: the client message recieved

        """
        logging.info("\t[Server]\tGot SET_HISTOGRAM_REQUIREMENTS.")
        try:
            histo, histo_type = construct_region_histogram_data(
                    self.hist.get("numBins"), self.hist.get("hist"), self.hist.get("binWidth"), self.stats.get("mean"), self.stats.get("stddev"))
            await ws.send(add_message_header(histo, histo_type))
            logging.info("\t[Server]\tSent REGION_HISTOGRAM_DATA.")
        except:
            logging.error("\t[Server]\tUnable to compute region histogram")
            traceback.print_exc()
        
    #    Author: Dylan Fouche
    #    Date: 09/08/2021
    #    Availability: https://github.com/DylanFouche/CADaFloP.git
    async def on_region_statistics(self, ws, msg):
        """Handle the SET_STATS_REQUIREMENTS message.

        :param ws: the client websocket object
        :param msg: the client message recieved

        """
        logging.info("\t[Server]\tGot SET_STATS_REQUIREMENTS.")
        try:
            stats, stats_type = construct_region_stats_data(
                [self.stats.get("sum"), self.stats.get("mean"), self.stats.get("stddev"),self.stats.get("min"),self.stats.get("max")])
            await ws.send(add_message_header(stats, stats_type))
            logging.info("\t[Server]\tSent REGION_STATS_DATA.")
        except:
            logging.error("\t[Server]\tUnable to compute region statistics")
            traceback.print_exc()
    
#    Author: Dylan Fouche
#    Date: 09/08/2021
#    Availability: https://github.com/DylanFouche/CADaFloP.git
    MESSAGE_TYPE_CODE_TO_EVENT_HANDLER = {
        enums_pb2.EventType.OPEN_FILE : on_open_file,
        enums_pb2.EventType.SET_STATS_REQUIREMENTS : on_region_statistics,
        enums_pb2.EventType.SET_HISTOGRAM_REQUIREMENTS: on_set_histogram_requirements,
    }