#ifndef RAFTHISTOGRAM_TCC
#define RAFTHISTOGRAM_TCC

/*
    Constructor for middle kernel - will have one input and one output
    Will act as a sequetial kernel, also sets the mean, min, binWidth and noOfBins from
    raftlib class
*/
template <typename T, typename F>
RaftHistogram<T, F>::RaftHistogram(F mean, F min, double binWidth, int noOfBins) : raft::kernel(), mean(mean), min(min), binWidth(binWidth), noOfBins(noOfBins)
{
    //allocates memory for vector bins
    std::vector<int> lbins(this->noOfBins, 0);
    this->bins = lbins;
    input.addPort<T>("stdvvec");
    output.addPort<std::vector<int>>("total");
}

/*
    Copy Constructor for middle kernel, will be duplicated number of times that there is output
    ports for previous kernel. the bins will be duplicated aswell, but each duplicated bin will be
    initialised with 0s so that they can be added up in the final kernel
*/
template <typename T, typename F>
RaftHistogram<T, F>::RaftHistogram(const RaftHistogram &other) : raft::kernel(), mean(other.mean), min(other.min), binWidth(other.binWidth), noOfBins(other.noOfBins)
{
    std::vector<int> lbins(noOfBins, 0);
    bins = lbins;
    input.addPort<T>("stdvvec");
    output.addPort<std::vector<int>>("total");
}

/*
    The run method will go through the NUM_VECTORS from the previous kernel
    and calculate the histogram for the vecots provided.
*/
template <typename T, typename F>
raft::kstatus RaftHistogram<T, F>::run()
{
    //data from input port returns a reference to the head of queue
    auto &t(input["stdvvec"].template peek<T>());
    
    //loop through NUM_VECTORS
    for (int i = 0; i < t.size(); i++)
    {
        //loop through vector in NUM_VECTORS        
        for (int j = 0; j < t[i].first.size(); j++)
        {
            //finding the correct bin position to increment
            float scaledVal = (t[i].first[j] - min) / binWidth;
            int index = floor(scaledVal);
            bins[index]++;

        }
    }

    //tells runtime that the refeence is no longer being used
    input["stdvvec"].unpeek();

    //see previous kernel comments
    auto c(output["total"].template allocate_s<std::vector<int>>());
    (*c) = bins;
    output["total"].send();

    //totally safe - multiple purposes
    input["stdvvec"].recycle(1);

    //needed to reset the global bins back to 0s otherwise the bins will be cummulative from previous values
    std::fill(bins.begin(), bins.end(), 0);
    
    //see previous kernel comments  
    return (raft::proceed);
}

#endif