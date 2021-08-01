#!/usr/bin/env python3
#import backend.daliuge
from frontend.Client import *


def main():
    menu = "1. File Info \n2. File Load"
    client = Client()
    client.connectToServer()

    while True:

        option = input(menu)

        if(option == 1):

            directory = input("Enter directory name")
            file = input("Enter file name")
            

if __name__ == "__main__":
    main()
