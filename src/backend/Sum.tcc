#ifndef SUM_TCC
#define SUM_TCC

/*
    Constructor for Sum - It will define the number
    of input ports depending on NUM_THREADS that was set
    in the raftlib class
*/
template <typename T>
Sum<T>::Sum(const std::size_t n_input_ports) : raft::parallel_k()
{
    //will store the sum and sum square total
    this->total = 0;
    this->sumSquaresTotal = 0;

    //creating no of inputs
    for (auto i(0); i < n_input_ports; i++)
    {
        addPortTo<std::vector<T>>(input);
    }
};

/*
    Run method will loop through the number of inputs and add the data in the ports
    to the sum and sumsquares variables
*/
template <typename T>
raft::kstatus Sum<T>::run()
{
    //looping through number of inputs
    for (auto &port : input)
    {
        //size returns current size of fifo
        //basically checks if the port has any data on it
        if (port.size() > 0)
        {
            //see previous kernel comments
            auto &a(port.template peek<std::vector<T>>());
            total += a[0];
            sumSquaresTotal+=a[1];
            port.unpeek();
            port.recycle();
        }
    }
    //see previous kernel comments
    return (raft::proceed);
};

#endif