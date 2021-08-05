#!/usr/bin/env python3

import websockets
import asyncio

#Protobuf imports
import uuid
import numpy as np

from protobufs.python import defs_pb2
from protobufs.python import enums_pb2
from protobufs.python import register_viewer_pb2

#util
from util.message_header import *
from util.message_provider import *

class Client:
    
    def __init__(self):
        self.url = "ws://localhost:9000"

    
    def connectToServer(self):
        async def connect(self):
            try:
                self.websocket = await websockets.connect(self.url, ping_interval = None)
            except:
                print("Failed to connect.")
                exit(0)
            finally:
                message, type = construct_register_viewer()
                
                #Sending Session Id from register viewer
                await self.websocket.send(add_message_header(message,type))
                regAck = await self.websocket.recv()
                messageType, messageId, messagePayload = strip_message_header(regAck)
                if(messagePayload.success == True):
                    print("Register viewer acknowledged by server")
                else:
                    print("Server failed to acknowledge session ID")
                    exit(0)
                
        asyncio.get_event_loop().run_until_complete(connect(self))

    def listen(self):
        asyncio.get_event_loop().run_until_complete(self.producer_handler(self.websocket,"yeeet"))

    def consumer(self, message):
        print(message)

    async def producer(self):
        menu = "1. File Info \n2. File Load\n"

        option = input(menu)

        if(option == "1"):
            return "1"
        else:
            return "2"
            
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
            print(message)


    
    def registerViewer(self):
        message_type = enums_pb2.EventType.REGISTER_VIEWER
        message = register_viewer_pb2.RegisterViewer()
        message.session_id = np.uint32(uuid.uuid4().int % np.iinfo(np.uint32()).max)
        
        return (message,message_type)
           

