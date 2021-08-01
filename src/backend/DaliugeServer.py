#!/usr/bin/env python3

import asyncio
import websockets

class DaliugeServer:

    def __init__(self):
        pass

    def host(self):
        async def _host(websocket, port):
            name = await websocket.recv()
            print(f"< {name}")

            greeting = f"Hello {name}!"

            await websocket.send(greeting)
            print(f"> {greeting}")

        
        start_server = websockets.serve(_host, "localhost", 9001)
        asyncio.get_event_loop().run_until_complete(start_server)
        asyncio.get_event_loop().run_forever()

if __name__ == "__main__":

    server = DaliugeServer()
    server.host()
    # start_server = websockets.serve(server.host, "localhost", 9001)
    # asyncio.get_event_loop().run_until_complete(start_server)
    # asyncio.get_event_loop().run_forever()