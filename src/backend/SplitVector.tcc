#ifndef SPLITVECTOR_TCC
#define SPLITVECTOR_TCC
#include <iostream>
#include <cstdint>
#include <cstdlib>
#include <raft>
#include <raftio>
#include <raftrandom>

#include "Raftlib.h"

template <typename T>
SplitVector<T>::SplitVector(const std::size_t n_output_ports) : raft::parallel_k()
{
    input.addPort<T>("a");
    for (auto i(0); i < n_output_ports; i++)
    {
        //addPortTo<std::vector<std::pair<T, raft::signal>>>(output);
        output.addPort<std::vector<std::pair<T, raft::signal>>>(std::to_string(i));
    }
    //output.addPort<std::vector<std::pair<T, raft::signal>>>(std::to_string( index ));
}

template <typename T>
raft::kstatus SplitVector<T>::run()
{
    std::vector<std::pair<T, raft::signal>> r(NUM_VECTORS);
    std::vector<std::pair<T, raft::signal>> &t = r;

    for (auto &port : output)
    {
        //if (port.space_avail())
        //{
        input["a"].template pop_range(t, NUM_VECTORS);

        auto c(port.template allocate_s<std::vector<std::pair<T, raft::signal>>>());
        (*c) = t;
        port.send();
        //}
    }
    //auto c(output["split"].template allocate_s<std::vector<std::pair<T, raft::signal>>>());

    return (raft::proceed);
}

#endif