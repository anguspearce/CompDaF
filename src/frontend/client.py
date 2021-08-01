#!/usr/bin/env python3

import websockets
import asyncio


class Client:
    global websocket
    
    def __init__(self):
        self.url = "ws://localhost:9001"

    
    def connectToServer(self):
        async def connect(self):
            websocket = await websockets.connect(self.url)
            name = input()
            await websocket.send(name)
            print(f"> {name}")

            greeting = await websocket.recv()
            print(f"< {greeting}")
        
        asyncio.get_event_loop().run_until_complete(connect(self))
    
    async def consumer_handler(websocket, path):
        async for message in websocket:
            await consumer(message)

    async def producer_handler(websocket, path):
        while True:
            message = await producer()
            await websocket.send(message)

    async def handler(websocket, path):
        consumer_task = asyncio.ensure_future(consumer_handler(websocket, path))
        producer_task = asyncio.ensure_future(producer_handler(websocket, path))
        done, pending = await asyncio.wait(
            [consumer_task, producer_task],
            return_when = asyncio.FIRST_COMPLETED,
        )
        for task in pending:
            task.cancel()



