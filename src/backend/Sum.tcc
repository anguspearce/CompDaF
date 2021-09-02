#ifndef SUM_TCC
#define SUM_TCC
#include "Sum.h"

template <typename T>
Sum<T>::Sum(const std::size_t n_input_ports) : raft::parallel_k()
{
    this->total = 0;
    for (auto i(0); i < n_input_ports; i++)
    {
        addPortTo<std::vector<T>>(input);
    }
    //input.template addPort<T>("a");
};

template <typename T>
raft::kstatus Sum<T>::run()
{

    for (auto &port : input)
    {
        if (port.size() > 0)
        {
            //T a;
            //port.pop(a);
            auto &a(port.template peek<std::vector<T>>());
            total += a[0];
            sumSquaresTotal+=a[1];
            port.unpeek();

            port.recycle();
        }
    }

    return (raft::proceed);
};

#endif