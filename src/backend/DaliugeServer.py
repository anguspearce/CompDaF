#!/usr/bin/env python3

import asyncio
import websockets


from protobufs.python import defs_pb2
from protobufs.python import enums_pb2
from protobufs.python import register_viewer_pb2

#util
from util.message_header import *
from util.message_provider import *

class DaliugeServer:

    def __init__(self):
        start_server = websockets.serve(self._host, "localhost", 9001, ping_interval = None)
        asyncio.get_event_loop().run_until_complete(start_server)
        asyncio.get_event_loop().run_forever()


    async def _host(self, websocket, port):
        message = await websocket.recv()
        messageType, messageId, messagePayload = strip_message_header(message)
        print(f"< {messageId}")

        # Using received session ID to get register viewer acknowledge 
        ack, ack_type = self.registerViewerAck(int(messageId))
        if(ack.success == True):

            print("Successfully connected with session:", messageId)
        else:
            print("Failed to connect with session:", messageId)

        await websocket.send(add_message_header(ack,ack_type))

        async for message in websocket:
            await self.consumer(websocket, message)

    async def consumer(self, websocket, message):
        print(message)
        await websocket.send("hi")
        print("sent hi")
        


    def registerViewerAck(self,client_session_id):
        
        message_type = enums_pb2.EventType.REGISTER_VIEWER_ACK
        message = register_viewer_pb2.RegisterViewerAck()
        message.session_id = client_session_id
        message.success = True
        return (message, message_type)
