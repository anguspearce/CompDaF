# CompDaF

## Clone repository 
```git clone https://github.com/anguspearce/CompDaF.git```

## Build submodules
```git submodule update --init --recursive ```

# C++ raft-backend

## External Dependencies
The C++ raft-backend depends on the following libraries:
* [Raftlib] (https://github.com/RaftLib/RaftLib); Follow the build instructions, then copy the raftlib.pc folder from the build folder into /usr/lib/x86_64-linux-gnu/pkgconfig

* [TBB] (https://www.threadingbuildingblocks.org) Threading Building Blocks for task parallelization. Debian package `libtbb-dev`.

* [CFITSIO] (https://heasarc.gsfc.nasa.gov/docs/software/fitsio/fitsio.html); CFITSIO is a library of C and Fortran subroutines for reading and writing data files in FITS (Flexible Image Transport System) data format. Debian package `libcfitsio-dev`.

* [GTEST] (https://github.com/google/googletest); Google Test is a unit testing library for the C++ programming language, based on the xUnit architecture. Debian package ` libgtest-dev`. `cd /usr/src/gtest` , `sudo cmake CMakeLists.txt`, ` sudo make`, `sudo cp lib/*.a /usr/lib`

## Build C++ files
``` mkdir build ``` <br /> 
``` cd build ``` <br />
``` cmake .. ``` <br /> 
``` make ``` 

To compile in release mode you can run the command:
``` cmake .. -DCMAKE_BUILD_TYPE=release ``` <br /> 
``` make ``` 

## Run Server
To run the raft-backend server, from the build folder:

``` ./raftlib-server PORT NUM_THREADS``` <br />
Example:
``` ./raftlib-server 9001 5```
Will run the server on port 9001 and raftlib will use 5 output ports.

# Daliuge Backend
## Starting a server
You can only run one server at a time for now.<br />
```cd ..``` into the main directory. <br /><br />
Or the DALiuGE backend:<br />
``` ./src/mainServer.py ``` 

# Frontend
## Frontend Dependencies
pip3 install:
* numpy
* astropy
* websockets
* protobuf

## Run client
``` ./src/runClient.py PORT```
Example:
``` ./src/runClient.py 9001 ```

