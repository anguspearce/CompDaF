#!/usr/bin/env python3

from daliuge_backend.DaliugeServer import *
from sys import argv

def main(args):
    # Creates instance of DaliugeServer class
    server = DaliugeServer(args[0], args[1])


if __name__ == "__main__":
    args = argv[1:]
    # Check if one argument was provided
    if len(args) != 2:
        raise Exception("Argument 'graphSpec' and 'port' required.")
    main(args)

    