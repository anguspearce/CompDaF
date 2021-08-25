#include <iostream>
#include <cstdint>
#include <cstdlib>
#include <raft>
#include <raftio>
#include <raftrandom>
#include <cmath>
#include <math.h>
#include "Raftlib.tcc"

template <typename T, typename F>
class StdvVector : public raft::parallel_k
{
public:
    F mean, min;
    double binWidth;
    std::vector<int> &bins;
    StdvVector(F mean, std::vector<int> &bins, F min, double binWidth) : raft::parallel_k(), mean(mean), bins(bins), min(min), binWidth(binWidth)
    {
        input.addPort<T>("stdvvec");
        output.addPort<F>("total");
    }
    StdvVector(const StdvVector &other) : raft::parallel_k(), mean(other.mean), bins(other.bins), min(other.min), binWidth(other.binWidth)
    {
        input.addPort<T>("stdvvec");
        output.addPort<F>("total");
    }
    virtual raft::kstatus run()
    {
        //T t;

        //input["meanvec"].template pop(t);
        auto &t(input["stdvvec"].template peek<T>());
        F meanVecTot = 0;
        for (int i = 0; i < t.size(); i++)
        {
            for (int j = 0; j < t[i].first.size(); j++)
            {
                meanVecTot += pow((t[i].first[j] - mean), 2);

                //adding to bins
                float scaledVal = (t[i].first[j] - min) / binWidth;
                int index = floor(scaledVal);
                bins[index]++;
            }
        }
        input["stdvvec"].unpeek();

        auto c(output["total"].template allocate_s<F>());
        (*c) = meanVecTot;

        output["total"].send();
        input["stdvvec"].recycle(1);

        return (raft::proceed);
    }
    CLONE();
};