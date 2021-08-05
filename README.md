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
You can only run one server at a time for now.<br />
Either the RaftLib backend:<br />
``` ./raftlib-server ```
Or the DALiuGE backend:<br />
``` cd .. ``` <br />
``` cd src ``` <br />
``` ./mainServer.py ``` 

## Run client
``` ./main.py ```

