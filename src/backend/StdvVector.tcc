#include <iostream>
#include <cstdint>
#include <cstdlib>
#include <raft>
#include <raftio>
#include <raftrandom>
#include <cmath>

#include "Raftlib.tcc"

template <typename T, typename F>
class StdvVector : public raft::parallel_k
{
public:
    F mean;
    StdvVector(F mean) : raft::parallel_k(), mean(mean)
    {
        input.addPort<T>("stdvvec");
        output.addPort<F>("total");
    }
    StdvVector(const StdvVector &other) : raft::parallel_k(), mean(other.mean)
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