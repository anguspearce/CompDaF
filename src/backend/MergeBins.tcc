#ifndef MERGEBINS_TCC
#define MERGEBINS_TCC

/*
    Constructor for MergeBins - It will define the number
    of input ports depending on NUM_THREADS that was set
    in the raftlib class
*/
template <typename T>
MergeBins<T>::MergeBins(std::vector<int> &bins, const std::size_t n_input_ports) : raft::parallel_k(), bins(bins)
{
    //creating no of inputs
    for (auto i(0); i < n_input_ports; i++)
    {
        addPortTo<std::vector<int>>(input);
    }
};

/*
    Run method will loop through the number of inputs and add the bins to the 
    global bins vector
*/
template <typename T>
raft::kstatus MergeBins<T>::run()
{
    //looping through number of inputs
    for (auto &port : input)
    {
        //size returns current size of fifo
        //basically checks if the port has any data on it
        if (port.size() > 0)
        {
            //see previous kernel comments
            auto &a(port.template peek<std::vector<int>>());
            
            //adding the bin values to the global bin vector
            for(int i=0;i<a.size();i++){
                bins[i]+=a[i];
            }
            port.unpeek();

            port.recycle();
        }
    }
    //see previous kernel comments
    return (raft::proceed);
};

#endif