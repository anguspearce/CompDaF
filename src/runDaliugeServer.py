#!/usr/bin/env python3

from daliuge_backend.DaliugeServer import *
from sys import argv

def main(arg):
    # Creates instance of DaliugeServer class
    server = DaliugeServer(arg)


if __name__ == "__main__":
    args = argv[1:]
    # Check if one argument was provided
    if len(args) != 1:
        raise Exception("Argument 'graphSpec' required.")
    main(args[0])

    