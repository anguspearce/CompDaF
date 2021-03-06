#ifndef SPLITVECTOR_H
#define SPLITVECTOR_H

#include <iostream>
#include <cstdint>
#include <cstdlib>
#include <raft>
#include <raftio>
#include <raftrandom>

template <typename T>
class SplitVector : public raft::parallel_k
{
public:
    SplitVector(const std::size_t n_output_ports = 1);

    virtual raft::kstatus run();

private:
    const int NUM_VECTORS = 1;
};

#include "SplitVector.tcc"
#endif