#!/usr/bin/env python3
#import backend.daliuge
from frontend.Client import *

# Simple main method to create a client object, connect to a server 
def main():
    client = Client()
    client.connectToServer()
    client.menu()
            

if __name__ == "__main__":
    main()
