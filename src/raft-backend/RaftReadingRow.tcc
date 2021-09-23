#ifndef RAFTREADINGROW_TCC
#define RAFTREADINGROW_TCC

/*
    Constructor for split vector - It will define the number
    of output ports depending on NUM_THREADS that was set
    in the raftlib class
*/
template <typename T>
RaftReadingRow<T>::RaftReadingRow(T numRows,const std::size_t n_output_ports) : raft::parallel_k()
{
    numR=numRows;
    output_ports=n_output_ports;
    //input.addPort<T>("a");
    for (auto i(0); i < n_output_ports; i++)
    {
        output.addPort<std::vector<long long>>(std::to_string(i));
    }
}

/*
    The run method for this kernel will pop a specified number of
    vectors (NUM_VECTORS) from the buffer and pass it on to the 
    next kernel.
*/
template <typename T>
raft::kstatus RaftReadingRow<T>::run()
{
    //Neccessary to allocate a vector with the allocated size
    //std::vector<std::pair<T, raft::signal>> r(NUM_VECTORS);
    //std::vector<std::pair<T, raft::signal>> &t = r;

    long start=1;
    long interval=ceil(numR/output_ports);
    long end=0;
    std::vector< std::vector<long long>> ranges;
    for (int i=0;i<output_ports;i++){
        if (end>numR){
            end=numR;
        }
        else if((i==output_ports-1)&&(end<numR)){
            end=numR;
        }
        else{
            end+=interval;
        }
        std::vector<long long> t={start,end};
        ranges.push_back(t);
        start=end+1;
    }

    //Looping through the multiple outputs
    int range=0;
    for (auto &port : output)
    {
        // if (input["a"].size() > 0)
        // {
        //     //Pop a number of vectors into t
        //     input["a"].template pop_range(t, NUM_VECTORS);

        //     //allocate_s returns an object of the allocated memory
        //     //which will be released to the downstream port. pushing the memory allocated
        //     //to the consumer is handled by the returned object
        //     //exiting the calling stack frame.
        //     auto c(port.template allocate_s<std::vector<std::pair<T, raft::signal>>>());
        //     (*c) = t;

        //     //in order to release this object to the FIFO once it is written
        //     port.send();
        // }
            auto c(port.template allocate_s<std::vector<long long>>());
            (*c) = ranges[range];
            range+=1;
            //in order to release this object to the FIFO once it is written
            port.send();

    }

    //Not a producer kernel - has input and outputs
    return (raft::stop);
}

#endif