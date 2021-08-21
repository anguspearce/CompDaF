#include <iostream>
#include <cstdint>
#include <cstdlib>
#include <raft>
#include <raftio>
#include <raftrandom>

#include "Raftlib.h"

template <typename T, typename F>
class AddVector : public raft::kernel
{
public:
    AddVector() : raft::kernel()
    {
        input.addPort<T>("addvec");
        output.addPort<F>("total");
    }
    AddVector(const AddVector &other) : raft::kernel()
    {
        input.addPort<T>("addvec");
        output.addPort<F>("total");
    }
    virtual raft::kstatus run()
    {
        //T t;

        //input["addvec"].template pop(t);
        auto &t(input["addvec"].template peek<T>());
        F addVecTot = 0;
        for (int i = 0; i < t.size(); i++)
        {
            for (int j = 0; j < t[i].first.size(); j++)
            {
                addVecTot += t[i].first[j];
            }
        }

        auto c(output["total"].template allocate_s<F>());
        (*c) = addVecTot;
        
        output["total"].send();
        input["addvec"].recycle(1);

        return (raft::proceed);
    }
    CLONE();
};