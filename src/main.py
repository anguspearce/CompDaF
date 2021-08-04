#!/usr/bin/env python3
#import backend.daliuge
from frontend.Client import *


def main():
    menu = "1. File Info \n2. File Load"
    client = Client()
    client.connectToServer()
    client.listen()
            

if __name__ == "__main__":
    main()
