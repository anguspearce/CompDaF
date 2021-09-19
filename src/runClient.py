#!/usr/bin/env python3

from frontend.Client import *
from sys import argv

# Simple main method to create a client object, connect to a server 
def main(arg):
    client = Client(arg)
    client.connectToServer()
    client.menu()
            

if __name__ == "__main__":
    args = argv[1:]
    # Check if one argument was provided
    if len(args) != 1:
        raise Exception("Argument 'port number' is required.")
    main(args[0])
