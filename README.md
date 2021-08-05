# CompDaF

## Clone repository 
```git clone https://github.com/CARTAvis/carta-backend.git```

## Build submodules
```git submodule update --init --recursive ```

## Build C++ files
``` mkdir build ``` <br /> 
``` cd build ``` <br />
``` cmake .. ``` <br /> 
``` make ``` 

## Starting a server
You can only run one server at a time for now.<br />
```cd ..``` into the main directory. <br /><br />
Either the RaftLib backend:<br />
``` ./build/raftlib-server ``` <br />
Or the DALiuGE backend:<br />
``` ./src/mainServer.py ``` 

## Run client
``` ./src/main.py ```

