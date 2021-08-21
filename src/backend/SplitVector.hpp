#include <iostream>
#include <cstdint>
#include <cstdlib>
#include <raft>
#include <raftio>
#include <raftrandom>

#include "Raftlib.h"

template <typename T>
class SplitVector : public raft::parallel_k
{
public:
    SplitVector() : raft::parallel_k()
    {
        input.addPort<T>("a");
        output.addPort<std::vector<std::pair<T, raft::signal>>>("split");
    }

    virtual raft::kstatus run()
    {
        std::vector<std::pair<T, raft::signal>> r(2);
        std::vector<std::pair<T, raft::signal>> &t = r;

        input["a"].template pop_range(t, 2);

        auto c(output["split"].template allocate_s<std::vector<std::pair<T, raft::signal>>>());
        (*c) = t;

        return (raft::proceed);
    }
};