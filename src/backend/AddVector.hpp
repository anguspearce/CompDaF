#include <iostream>
#include <cstdint>
#include <cstdlib>
#include <raft>
#include <raftio>
#include <raftrandom>

#include "Raftlib.h"

template <typename T>
class AddVector : public raft::parallel_k
{
public:
    AddVector() : raft::parallel_k()
    {
        input.addPort<T>("addvec");
        output.addPort<double>("total");
    }

    virtual raft::kstatus run()
    {
        T t;

        input["addvec"].template pop(t);
        double addVecTot = 0;
        for (int i = 0; i < t.size(); i++)
        {
            for (int j = 0; j < t[i].first.size(); j++)
            {
                addVecTot += t[i].first[j];
            }
        }

        auto c(output["total"].template allocate_s<double>());
        (*c) = addVecTot;

        return (raft::proceed);
    }
};