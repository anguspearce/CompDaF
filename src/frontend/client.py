#!/usr/bin/env python3

import websockets
import asyncio

#Protobuf imports
import uuid
import numpy as np
from protobufs.python import defs_pb2
from protobufs.python import enums_pb2
from protobufs.python import register_viewer_pb2


class Client:
    global websocket
    
    def __init__(self):
        self.url = "ws://localhost:9001"

    
    def connectToServer(self):
        async def connect(self):
            try:
                websocket = await websockets.connect(self.url)
            except:
                print("Failed to connect.")
                exit(0)
            finally:
                message, type = self.registerViewer()
                #await websocket.send()
                
            
            

        
        asyncio.get_event_loop().run_until_complete(connect(self))


        

    # async def consumer_handler(websocket, path):
    #     async for message in websocket:
    #         await consumer(message)

    # async def producer_handler(websocket, path):
    #     while True:
    #         message = await producer()
    #         await websocket.send(message)

    # async def handler(websocket, path):
    #     consumer_task = asyncio.ensure_future(consumer_handler(websocket, path))
    #     producer_task = asyncio.ensure_future(producer_handler(websocket, path))
    #     done, pending = await asyncio.wait(
    #         [consumer_task, producer_task],
    #         return_when = asyncio.FIRST_COMPLETED,
    #     )
    #     for task in pending:
    #         task.cancel()

    def registerViewer():
        message_type = enums_pb2.EventType.REGISTER_VIEWER
        message = register_viewer_pb2.RegisterViewer()
        message.session_id = np.uint32(uuid.uuid4().int % np.iinfo(np.uint32()).max)
        
        return (message,message_type)
           

