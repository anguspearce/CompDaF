#!/usr/bin/env python3

import websockets
import asyncio

#Protobuf imports
import uuid
import numpy as np

from protobufs.python import defs_pb2
from protobufs.python import enums_pb2
from protobufs.python import register_viewer_pb2
from protobufs.python import file_info_pb2

#util
from util.message_header import *
from util.message_provider import *

# Class that represents a client
# Connects to a backend and gives options for the client to take.
class Client:
    # Init on object creation: Creates the url to connect the websocket to.
    def __init__(self):
        self.url = "ws://localhost:9001"

    # Attempts to connect to specified backend and tries to register with the server.
    # Receives REGISTER_VIEWER_ACK and session creation success.
    def connectToServer(self):
        async def connect(self):
            try:
                self.websocket = await websockets.connect(self.url, ping_interval = None)
            except:
                print("Failed to connect.")
                exit(0)
            
            message, type = construct_register_viewer()
    
            #Sending Session Id from register viewer
            await self.websocket.send(add_message_header(message,type))
            regAck = await self.websocket.recv()

            try:
                messageType, messageId, messagePayload = strip_message_header(regAck)
                if(messagePayload.success == True):
                    print("Register viewer acknowledged by server\n")
                else:
                    print("Server failed to acknowledge session ID")
                    exit(0)
            except:
                print("Server failed to acknowledge session ID")
                exit(0)
                
        asyncio.get_event_loop().run_until_complete(connect(self))

    # Runs the async producer_handler method
    def menu(self):
        asyncio.get_event_loop().run_until_complete(self.producer_handler(self.websocket,""))

    # Supplies user with options list and calls relevant handler methods.
    async def producer(self):
        menu = "Choose an option:\n1. Open File\n\nSelection: "
        option = input(menu)
        try:
            if (option == "-1"):
                directory = input("Please enter the directory name: ")
                fileName = input("Please enter the file name: ")

                message, type = construct_file_info_request(directory, fileName)

                return add_message_header(message,type)
            elif (option == "1"):
                directory = input("Please enter the directory name: ")
                fileName = input("Please enter the file name: ")
                message, type = construct_open_file(directory,fileName)
                
                return add_message_header(message,type)
        except:
            print("There seems to be an issue finding or opening that file, please try again.")
            
            
    # Waits for input from client, sends message to server based on input and waits for required response.
    async def producer_handler(self, websocket, path):
        while True:
            message = await self.producer()
            await websocket.send(message)
            message = await websocket.recv()
            messageType, messageId, messagePayload = strip_message_header(message)
            handler = self.MESSAGE_TYPE_CODE_TO_EVENT_HANDLER.get(messageType)
            await handler(self, websocket, messagePayload)

    # COMMENT
    async def __on_file_info_response(self, ws, msg):
        print("")
        if(msg.success == True):
            print("File name: ",msg.file_info.name)
            print("File type: ",msg.file_info.type)
            print("File size: ",msg.file_info.size)
        else:
            print("Failed to find file.")
        print("")
    # COMMENT
    async def __on_open_file_ack_response(self, ws, msg):
        print("")
        if(msg.success == True):
            print("File name: ",msg.file_info.name)
            print("File type: ",msg.file_info.type)
            print("File size: ",msg.file_info.size)
            print("Img Dimensions: ",msg.file_info_extended.dimensions)
            print("Image Width: ",msg.file_info_extended.width)
            print("Image Height: ",msg.file_info_extended.height)
            print("Image Depth: ",msg.file_info_extended.depth)
            print("No of Header entries: ",len(msg.file_info_extended.header_entries))
        else:
            print("Failed to find file.")
        print("")
        
#    Author: Dylan Fouche
#    Date: 09/08/2021
#    Availability: https://github.com/DylanFouche/CADaFloP.git
    MESSAGE_TYPE_CODE_TO_EVENT_HANDLER = {
        
        enums_pb2.EventType.FILE_INFO_RESPONSE:
            __on_file_info_response,
        enums_pb2.EventType.OPEN_FILE_ACK:
            __on_open_file_ack_response,
        
    }
    
           

