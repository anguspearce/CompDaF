#ifndef MERGEBINS_H
#define MERGEBINS_H
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
class MergeBins : public raft::parallel_k
{
public:
    std::vector<int> &bins;
    MergeBins(std::vector<int> &bins,const std::size_t n_input_ports = 1);

    virtual raft::kstatus run();
};
#include "MergeBins.tcc"
#endif