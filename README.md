# CompDaF

## Clone repository 
```git clone https://github.com/CARTAvis/carta-backend.git```

## Build submodules
```git submodule update --init --recursive ```

## Build C++ files
``` mkdir build ``` <br /> 
``` cmake .. ``` <br /> 
``` make ``` 

## Starting a server
You can only run one server at a time for now:
## Run RaftLib backend
``` ./raftlib-server ```

## Run DALiuGE backend
``` cd .. ``` <br />
``` cd src ``` <br />
``` ./mainServer.py ``` 

## Run client
``` ./main.py ```

