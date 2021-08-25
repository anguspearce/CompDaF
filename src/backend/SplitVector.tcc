#include <iostream>
#include <cstdint>
#include <cstdlib>
#include <raft>
#include <raftio>
#include <raftrandom>

#include "Raftlib.tcc"

template <typename T>
class SplitVector : public raft::parallel_k
{
public:
    SplitVector(const std::size_t n_output_ports = 1) : raft::parallel_k()
    {
        input.addPort<T>("a");
        for (auto i(0); i < n_output_ports; i++)
        {
            //addPortTo<std::vector<std::pair<T, raft::signal>>>(output);
            output.addPort<std::vector<std::pair<T, raft::signal>>>(std::to_string(i));
        }
        //output.addPort<std::vector<std::pair<T, raft::signal>>>(std::to_string( index ));
    }

    virtual raft::kstatus run()
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

private:
    const int NUM_VECTORS = 1;
};