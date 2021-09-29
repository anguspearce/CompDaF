#ifndef RAFTSTATISTICS_TCC
#define RAFTSTATISTICS_TCC

/*
    Constructor for middle kernel - will have one input and one output
    Will act as a sequetial kernel
*/
template <typename T, typename F>
RaftStatistics<T, F>::RaftStatistics() : raft::kernel()
{
    min = INT_MAX;
    max = INT_MIN;
    input.addPort<T>("addvec");
    output.addPort<std::vector<F>>("total");
}

/*
    Copy Constructor for middle kernel, will be duplicated number of times that there is output
    ports for previous kernel
*/
template <typename T, typename F>
RaftStatistics<T, F>::RaftStatistics(const RaftStatistics &other) : raft::kernel()
{
    min = INT_MAX;
    max = INT_MIN;
    input.addPort<T>("addvec");
    output.addPort<std::vector<F>>("total");
}

/*
    The run method will go through the NUM_VECTORS from the previous kernel
    and calculate the sum and sum square, it will also calculate the min and max
    since we go through every value it is safe to do min and max here
*/
template <typename T, typename F>
raft::kstatus RaftStatistics<T, F>::run()
{
    //data from input port returns a reference to the head of queue
    auto &t(input["addvec"].template peek<T>());

    //vector to hold the sum and sumsquare which is passed to the next kernel
    std::vector<F> totals = {0, 0, 0, 0};

    //loop through NUM_VECTORS
    for (int i = 0; i < t.size(); i++)
    {
        //loop through vector in NUM_VECTORS
        for (int j = 0; j < t[i].first.size(); j++)
        {
            //min
            if (t[i].first[j] < min)
            {
                min = t[i].first[j];
            }

            //max
            if (t[i].first[j] > max)
            {
                max = t[i].first[j];
            }

            //adding sum and sum square to vector to be sent
            totals[0] += t[i].first[j];
            totals[1] += (t[i].first[j] * t[i].first[j]);
        }
    }
    //adding the min and max values to downstreamed vector
    totals[2] = min;
    totals[3] = max;
    //tells runtime that the refeence is no longer being used
    input["addvec"].unpeek();

    //see previous kernel comments
    auto c(output["total"].template allocate_s<std::vector<F>>());
    (*c) = totals;

    output["total"].send();

    //totally safe - multiple purposes
    input["addvec"].recycle(1);

    //see previous kernel comments
    return (raft::proceed);
}

#endif