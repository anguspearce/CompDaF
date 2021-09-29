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
    T sumSquaresTotal;
    T min;
    T max;
    Sum(const std::size_t n_input_ports = 1);

    virtual raft::kstatus run();
};
#include "Sum.tcc"
#endif