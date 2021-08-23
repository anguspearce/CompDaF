#include <iostream>
#include <cstdint>
#include <cstdlib>
#include <raft>
#include <raftio>
#include <raftrandom>

#include "Raftlib.tcc"

template <typename T, typename F>
class AddVector : public raft::parallel_k
{
public:
    F &max;
    F &min;
    AddVector(F &max, F &min) : raft::parallel_k(), min(min), max(max)
    {

        input.addPort<T>("addvec");
        output.addPort<F>("total");
    }
    AddVector(const AddVector &other) : raft::parallel_k(), min(other.min), max(other.max)
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
                if (t[i].first[j] < min)
                {
                    min = t[i].first[j];
                }

                if (t[i].first[j] > max)
                {
                    max = t[i].first[j];
                }
                addVecTot += t[i].first[j];
            }
        }
        input["addvec"].unpeek();

        auto c(output["total"].template allocate_s<F>());
        (*c) = addVecTot;

        output["total"].send();
        input["addvec"].recycle(1);

        return (raft::proceed);
    }
    CLONE();
};