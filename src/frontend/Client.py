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

class Client:
    
    def __init__(self):
        self.url = "ws://localhost:9001"

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
                    print("Register viewer acknowledged by server")
                else:
                    print("Server failed to acknowledge session ID")
                    exit(0)
            except:
                print("Server failed to acknowledge session ID")
                exit(0)
                
        asyncio.get_event_loop().run_until_complete(connect(self))

    def listen(self):
        asyncio.get_event_loop().run_until_complete(self.producer_handler(self.websocket,"yeeet"))

    def consumer(self, message):
        print(message)

    async def producer(self):
        menu = "1. File Info \n2. Open File\n"

        option = input(menu)

        if(option == "1"):
            directory = input("Please enter the directory name: ")
            fileName = input("Please enter the file name: ")

            message, type = construct_file_info_request(directory,fileName)


            return add_message_header(message,type)
        else:
            directory = input("Please enter the directory name: ")
            fileName = input("Please enter the file name: ")
            message, type = construct_open_file(directory,fileName)
            
            return add_message_header(message,type)
            
    async def consumer_handler(self, websocket, path):
        print("lol")
        while True:
            message = await websocket.recv()
            self.consumer(message)
        # async for message self.in websocket:
        #     await self.consumer(message)

    async def producer_handler(self, websocket, path):
        while True:
            message = await self.producer()
            await websocket.send(message)
            message = await websocket.recv()
            messageType, messageId, messagePayload = strip_message_header(message)
            handler = self.MESSAGE_TYPE_CODE_TO_EVENT_HANDLER.get(messageType)
            await handler(self, websocket, messagePayload)

    async def __on_file_info_response(self, ws, msg):
        if(msg.success == True):
            print("File name: ",msg.file_info.name)
            print("File type: ",msg.file_info.type)
            print("File size: ",msg.file_info.size)
        else:
            print("Failed to find file.")

    async def __on_open_file_ack_response(self, ws, msg):
        if(msg.success == True):
            print("File name: ",msg.file_info.name)
            print("File type: ",msg.file_info.type)
            print("File size: ",msg.file_info.size)
        else:
            print("Failed to find file.")
        
#    Author: Dylan Fouche
#    Date: 09/08/2021
#    Availability: https://github.com/DylanFouche/CADaFloP.git
    MESSAGE_TYPE_CODE_TO_EVENT_HANDLER = {
        
        enums_pb2.EventType.FILE_INFO_RESPONSE:
            __on_file_info_response,
        enums_pb2.EventType.OPEN_FILE_ACK:
            __on_open_file_ack_response,
        
    }
           

