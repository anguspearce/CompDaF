#ifndef SUM_H
#define SUM_H
#include <cassert>
#include <iostream>
#include <cstdint>
#include <cstdlib>
#include <raft>
#include <raftio>
#include <raftrandom>
#include <raftmath>
#include <raftutility>
#include <numeric>

template <typename T>
class Sum : public raft::parallel_k
{
public:
    T total;
    Sum(const std::size_t n_output_ports = 1) : raft::parallel_k()
    {
        this->total = 0;
        for (auto i(0); i < n_output_ports; i++)
        {
            addPortTo<T>(input);
        }
        //input.template addPort<T>("a");
    };

    virtual raft::kstatus run()
    {

        for (auto &port : input)
        {
            if (port.size() > 0)
            {
                //T a;
                //port.pop(a);
                auto &a(port.template peek<T>());
                total += a;
                port.unpeek();

                port.recycle();
            }
        }

        return (raft::proceed);
    };
};

#endif