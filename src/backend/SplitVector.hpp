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
    SplitVector(const std::size_t n_output_ports = 1) : raft::parallel_k()
    {
        input.addPort<T>("a");
        for( auto i( 0 ); i < n_output_ports; i++ )
        {
            addPortTo<std::vector<std::pair<T, raft::signal>>>( output );
        }
        //output.addPort<std::vector<std::pair<T, raft::signal>>>("split");
    }

    virtual raft::kstatus run()
    {
        std::vector<std::pair<T, raft::signal>> r(2);
        std::vector<std::pair<T, raft::signal>> &t = r;

        input["a"].template pop_range(t, 2);
        for( auto &port : output )
        {
            
            auto c(port.template allocate_s<std::vector<std::pair<T, raft::signal>>>());
            (*c) = t;

        }
        //auto c(output["split"].template allocate_s<std::vector<std::pair<T, raft::signal>>>());

        return (raft::proceed);
    }
};