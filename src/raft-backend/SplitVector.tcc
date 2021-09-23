#ifndef SPLITVECTOR_TCC
#define SPLITVECTOR_TCC

/*
    Constructor for split vector - It will define the number
    of output ports depending on NUM_THREADS that was set
    in the raftlib class
*/
template <typename T>
SplitVector<T>::SplitVector(const std::size_t n_output_ports, const std::size_t n_input_ports) : raft::parallel_k()
{
    //input.addPort<T>("a");
    //creating no of inputs
    this->input_ports=n_input_ports;
    for (auto i(0); i < n_input_ports; i++)
    {
        input.addPort<T>("in"+std::to_string(i));
    }
    for (auto i(0); i < n_output_ports; i++)
    {
        output.addPort<std::vector<std::pair<T, raft::signal>>>(std::to_string(i));
    }
}

/*
    The run method for this kernel will pop a specified number of
    vectors (NUM_VECTORS) from the buffer and pass it on to the 
    next kernel.
*/
template <typename T>
raft::kstatus SplitVector<T>::run()
{
    //Neccessary to allocate a vector with the allocated size
    std::vector<std::pair<T, raft::signal>> r(NUM_VECTORS);
    std::vector<std::pair<T, raft::signal>> &t = r;

    //Looping through the multiple outputs
    long count=0;
    for (auto &port : output)
    {
        count+=1;
        if (input["in"+std::to_string(count%input_ports)].size() > 0)
        {
            //Pop a number of vectors into t
            input["in"+std::to_string(count%input_ports)].template pop_range(t, NUM_VECTORS);

            //allocate_s returns an object of the allocated memory
            //which will be released to the downstream port. pushing the memory allocated
            //to the consumer is handled by the returned object
            //exiting the calling stack frame.
            auto c(port.template allocate_s<std::vector<std::pair<T, raft::signal>>>());
            (*c) = t;

            //in order to release this object to the FIFO once it is written
            port.send();
        }
    }

    //Not a producer kernel - has input and outputs
    return (raft::proceed);
}

#endif