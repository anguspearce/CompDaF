#!/usr/bin/env python3

import websockets
from websockets.exceptions import ConnectionClosedError
import asyncio

# Protobuf imports
from protobufs.python import enums_pb2

# Util
from util.message_header import *
from util.message_provider import *


class Client:
    """ Client class that uses websockets and protocol buffers set up a consistent connection to a server """
    def __init__(self, port):
        """
        Creates the url to connect the websocket to on initialisation.
        :param port: Port number to connect to on localhost
        """
        self.url = "ws://localhost:" + str(port)
        self.file_open = False
        self.cube = False


    def connectToServer(self):
        """
        Attempts to connect to specified backend and tries to register with the server.
        Receives REGISTER_VIEWER_ACK and session creation success.
        """
        async def connect(self):
            try:
                self.websocket = await websockets.connect(self.url, ping_interval=None)
            except:
                print("Failed to connect.")
                exit(0)

            message, type = construct_register_viewer()

            # Sending Session Id from register viewer
            await self.websocket.send(add_message_header(message, type))
            regAck = await self.websocket.recv()

            try:
                messageType, messageId, messagePayload = strip_message_header(
                    regAck)
                print()
                if(messagePayload.success == True):
                    print("Register viewer acknowledged by server\n")
                else:
                    print("Server failed to acknowledge session ID")
                    exit(0)
            except:
                print("Server failed to acknowledge session ID")
                exit(0)

        asyncio.get_event_loop().run_until_complete(connect(self))

    def menu(self):
        """
        Runs the async producer_handler method
        """
        asyncio.get_event_loop().run_until_complete(
            self.producer_handler(self.websocket, ""))

    
    async def producer(self):
        """ Supplies user with input options based on whether a file is open or not.
        """
        if self.file_open:
            menu = "Choose an option:\n1. Region Histogram\n2. Region Statistics\n3. Back\n\nSelection: "
            option = input(menu)
            while(self.file_open):
                try: 
                    if (option == "1"):
                        message, type = construct_set_histogram_requirements()
                        if(self.cube):
                            message.region_id = -2
                        return add_message_header(message, type)
                    elif (option == "2"):
                        message, type = construct_set_stats_requirements()
                        return add_message_header(message, type)
                    elif (option == "3"):
                        self.file_open = False
                        break
                    else:
                        print("\nThere seems to be an issue with your input. Please try again.\n")
                    option = input(menu)
                except:
                    print("\nThere seems to be an issue with your input. Please try again.\n")
                    continue
        
        menu = "Choose an option:\n1. Open File\nq. Quit Application\n\nSelection: "
        option = input(menu)
        try:
            if (option == "1"):
                directory = input("Please enter the directory name: ")
                fileName = input("Please enter the file name: ")
                message, type = construct_open_file(directory, fileName)

                return add_message_header(message, type)
            elif (option == "q"):
                await self.websocket.close()
                return None
            else:
                return 0
        except:
            print("There seems to be an issue finding or opening that file, please try again.")


    async def producer_handler(self, websocket, path):
        """ Waits for input from client, sends message to server based on input and awaits a response. 
        :param websocket: websocket
        """
        while True:
            try:
                message = await self.producer()
                if message == None:
                    await websocket.close()
                    exit(0)
                elif message == 0:
                    print("\nThat is not an option, please try again.\n")
                    continue
                await websocket.send(message)
                message = await websocket.recv()
                messageType, messageId, messagePayload = strip_message_header(
                    message)
                handler = self.MESSAGE_TYPE_CODE_TO_EVENT_HANDLER.get(messageType)
                await handler(self, websocket, messagePayload)
            except (ConnectionClosedError, ConnectionAbortedError, asyncio.exceptions.IncompleteReadError):
                print("Server closed unexpectedly, closing connection.")
                exit(0)

    async def __on_open_file_ack_response(self, ws, msg):
        """ Called when there is a open file acknowledgement response from the server 
        :param ws: websocket
        :param msg: message received from the server
        """
        if(msg.success == True):
            # Set open file to true
            self.file_open = True

            print("\nFile name: ", msg.file_info.name)
            print("File type: ", msg.file_info.type)
            print("File size: ", msg.file_info.size)
            print("Img Dimensions: ", msg.file_info_extended.dimensions)
            print("Image Width: ", msg.file_info_extended.width)
            print("Image Height: ", msg.file_info_extended.height)
            print("Image Depth: ", msg.file_info_extended.depth)
            print("No of Header entries: ", len(
                msg.file_info_extended.header_entries),"\n")

            if msg.file_info_extended.depth > 1:
                self.cube = True

            # Awaiting region histogram data
            message = await ws.recv()
            messageType, messageId, messagePayload = strip_message_header(message)
            handler = self.MESSAGE_TYPE_CODE_TO_EVENT_HANDLER.get(messageType)
            await handler(self, ws, messagePayload)
        else:
            print("Failed to find file.\n")
        

    async def __on_region_histogram_data(self, ws, msg):
        """ Called when histogram data is received from the server. 
        :param ws: websocket
        :param msg: message received from the server
        """
        print("\nRegion Histogram Data")
        print("No of Bins: ", msg.histograms[0].num_bins)
        print("Bin Width: ", msg.histograms[0].bin_width)
        print("First Bin Centre: ", msg.histograms[0].first_bin_center)
        print("Mean: ", msg.histograms[0].mean)
        print("StdDev: ", msg.histograms[0].std_dev)
        print("Bins: ", len(msg.histograms[0].bins),"\n")
    
    async def __on_region_stats_data(self, ws, msg):
        """ Called when region statistics data is received from the server 
        :param ws: websocket
        :param msg: message received from the server
        """
        print("\nRegion Statistics Data")
        for x in msg.statistics:
            print(self.STATS_TYPE_CODE_TO_NAME.get(x.stats_type),x.value)
        print()


#    Author: Dylan Fouche
#    Date: 09/08/2021
#    Availability: https://github.com/DylanFouche/CADaFloP.git
    MESSAGE_TYPE_CODE_TO_EVENT_HANDLER = {
        enums_pb2.EventType.OPEN_FILE_ACK:
            __on_open_file_ack_response,
        enums_pb2.EventType.REGION_HISTOGRAM_DATA:
            __on_region_histogram_data,
        enums_pb2.EventType.REGION_STATS_DATA:
            __on_region_stats_data,
    }
    
    STATS_TYPE_CODE_TO_NAME = {
        0 : "NumPixels",
        1 : "NanCount",
        2 : "Sum",
        4 : "Mean",
        6 : "StdDev",
        7 : "SumSq",
        8 : "Min",
        9 : "Max"
    }
