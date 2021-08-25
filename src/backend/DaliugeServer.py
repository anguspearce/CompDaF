#!/usr/bin/env python3

import asyncio
import websockets
import os

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


# Simple server using python websockets library
# Handles and calls relevant functions using DALiuGE
class DaliugeServer:
    # Initialise server by calling the host function and running the event loop forever.
    def __init__(self):
        try:
            print("Waiting for connection.")
            self.start_server = websockets.serve(self.host, "localhost", 9004, ping_interval = None)
            asyncio.get_event_loop().run_until_complete(self.start_server)
            asyncio.get_event_loop().run_forever()
        except Exception as e:
            print("Failed to start server. Exception:")
            print(e)
            exit(0)

    # Host function which awaits incoming connection, registers viewer and creates a session per client.
    async def host(self, websocket, port):
        message = await websocket.recv()
        messageType, messageId, messagePayload = strip_message_header(message)

        # Using received session ID to get register viewer acknowledge 
        ack, ack_type = construct_register_viewer_ack(int(messageId))
        if(ack.success == True):

            print("Successfully connected with session:", messageId)
        else:
            print("Failed to connect with session:", messageId)

        # Sending register viewer ack
        await websocket.send(add_message_header(ack,ack_type))
        # Running receiver event loop to receive messages and pass to the consumer
        await self.receiver(websocket, message)

    # Receiver function to wait for messages and pass to the consumer
    async def receiver(self, websocket, message):
        try:
            # Loop to receive and handle messages after initial setup
            async for message in websocket:
                await self.consumer(websocket, message)
        except Exception as e:
            print("Exception raised:")
            print(e)
            websocket.close()
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
            print("Unable to process message from client. Exception:")
            print(e)
            await websocket.send("Failed")
            await self.receiver(websocket, message)

    ### Handling Protocol Buffers ###
    #    Author: Dylan Fouche
    #    Date: 09/08/2021
    #    Availability: https://github.com/DylanFouche/CADaFloP.git
    async def on_open_file(self, ws, msg):
        """Handle the OPEN_FILE message.

        :param ws: the client websocket object
        :param msg: the client message recieved

        """
        file = msg.directory + msg.file
        ack, ack_type = construct_open_file_ack()
        try:
            with fits.open(file, memmap=True) as hdu:
                print("in")
                if "data" not in dir(hdu[0]):
                    raise Exception("Unexpected format in fits file.")
                # Seems to be an embedded list (12200 length, assume 8600 in each)
                d = hdu[0].data
                self.shape = d.shape
                self.dimensions = len(self.shape)
                chunk_size = 'auto' if self.shape[0] * self.shape[1] > 25000000 else (1000, 1000)
                ack.success = True
        except:
            print("out")
            ack.success = False
        await ws.send(add_message_header(ack, ack_type))

    #    Author: Dylan Fouche
    #    Date: 09/08/2021
    #    Availability: https://github.com/DylanFouche/CADaFloP.git
    async def on_file_info_request(self, ws, msg):
        """Handle the FILE_INFO_REQUEST message.
        :param ws: the client websocket object
        :param msg: the client message recieved
        """
        file = msg.directory + msg.file
        fileInfo = []
        try:
            with fits.open(file, memmap = True) as hdu:
                fileInfo.append(hdu.filename())
                fileInfo.append(os.path.getsize(file))

                hdu.info()
                date = (hdu[0].header['DATE'])
                fileInfo.append(str(date))
                
        except IOError as e:
            print( e)
        ack, ack_type = construct_file_info_response(fileInfo)
        await ws.send(add_message_header(ack, ack_type))
    
#    Author: Dylan Fouche
#    Date: 09/08/2021
#    Availability: https://github.com/DylanFouche/CADaFloP.git
    MESSAGE_TYPE_CODE_TO_EVENT_HANDLER = {
        
        enums_pb2.EventType.FILE_INFO_REQUEST : on_file_info_request,
        enums_pb2.EventType.OPEN_FILE : on_open_file,
        
        
    }
