#!/usr/bin/env python3

import asyncio
import websockets


from protobufs.python import defs_pb2
from protobufs.python import enums_pb2
from protobufs.python import register_viewer_pb2

class DaliugeServer:

    def __init__(self):
        pass

    def host(self):
        async def _host(websocket, port):
            sessionId = await websocket.recv()
            print(f"< {sessionId}")

            # Using received session ID to get register viewer acknowledge 
            ack, ack_type = self.registerViewerAck(int(sessionId))
            if(ack.success == True):

                print("Successfully connected with session:", sessionId)
            else:
                print("Failed to connect with session:", sessionId)

            await websocket.send(str(ack.success))

        
        start_server = websockets.serve(_host, "localhost", 9001)
        asyncio.get_event_loop().run_until_complete(start_server)
        asyncio.get_event_loop().run_forever()

    def registerViewerAck(self,client_session_id):
        
        message_type = enums_pb2.EventType.REGISTER_VIEWER_ACK
        message = register_viewer_pb2.RegisterViewerAck()
        message.session_id = client_session_id
        message.success = True
        return (message, message_type)

# if __name__ == "__main__":

#     server = DaliugeServer()
#     server.host()
#     # start_server = websockets.serve(server.host, "localhost", 9001)
#     # asyncio.get_event_loop().run_until_complete(start_server)
#     # asyncio.get_event_loop().run_forever()