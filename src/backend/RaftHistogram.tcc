#ifndef RAFTHISTOGRAM_TCC
#define RAFTHISTOGRAM_TCC

template <typename T, typename F>
RaftHistogram<T, F>::RaftHistogram(F mean, F min, double binWidth, int noOfBins) : raft::kernel(), mean(mean), min(min), binWidth(binWidth), noOfBins(noOfBins)
{
    std::vector<int> lbins(this->noOfBins, 0);
    this->bins = lbins;
    input.addPort<T>("stdvvec");
    output.addPort<std::vector<int>>("total");
}
template <typename T, typename F>
RaftHistogram<T, F>::RaftHistogram(const RaftHistogram &other) : raft::kernel(), mean(other.mean), min(other.min), binWidth(other.binWidth), noOfBins(other.noOfBins)
{
    std::vector<int> lbins(noOfBins, 0);
    bins = lbins;
    input.addPort<T>("stdvvec");
    output.addPort<std::vector<int>>("total");
}
template <typename T, typename F>
raft::kstatus RaftHistogram<T, F>::run()
{
    //T t;

    //input["meanvec"].template pop(t);
    auto &t(input["stdvvec"].template peek<T>());
    F meanVecTot = 0;
    //std::map<int, int> m;
    for (int i = 0; i < t.size(); i++)
    {
        for (int j = 0; j < t[i].first.size(); j++)
        {

            //meanVecTot += pow((t[i].first[j] - mean), 2);

            //adding to bins
            float scaledVal = (t[i].first[j] - min) / binWidth;
            int index = floor(scaledVal);
            bins[index]++;
            // m.insert({index, 0});
            // m[index] += 1;
            //bins[index]++;
        }
    }
    input["stdvvec"].unpeek();

    auto c(output["total"].template allocate_s<std::vector<int>>());
    (*c) = bins;
    //output["total"].deallocate();
    output["total"].send();
    input["stdvvec"].recycle(1);
    std::fill(bins.begin(), bins.end(), 0);
    return (raft::proceed);
}

#endif