#ifndef MERGEBINS_TCC
#define MERGEBINS_TCC
#include "MergeBins.h"

template <typename T>
MergeBins<T>::MergeBins(std::vector<int> &bins, const std::size_t n_input_ports) : raft::parallel_k(), bins(bins)
{

    for (auto i(0); i < n_input_ports; i++)
    {
        addPortTo<std::vector<int>>(input);
    }
    //input.template addPort<T>("a");
};

template <typename T>
raft::kstatus MergeBins<T>::run()
{

    for (auto &port : input)
    {
        if (port.size() > 0)
        {
            //T a;
            //port.pop(a);
            auto &a(port.template peek<std::vector<int>>());
            // for (auto itr = a.begin(); itr != a.end(); ++itr)
            // {
            //     //std::cout<<itr->first<<" "<<itr->second<<std::endl;
            //     bins[itr->first] += itr->second;
            // }
            //std::cout<<a.size()<<std::endl;
            for(int i=0;i<a.size();i++){
                bins[i]+=a[i];
            }
            port.unpeek();

            port.recycle();
        }
    }

    return (raft::proceed);
};

#endif