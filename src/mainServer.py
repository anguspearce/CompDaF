#!/usr/bin/env python3

from backend.DaliugeServer import *

if __name__ == "__main__":

    server = DaliugeServer()
    server.host()
    # start_server = websockets.serve(server.host, "localhost", 9001)
    # asyncio.get_event_loop().run_until_complete(start_server)
    # asyncio.get_event_loop().run_forever()