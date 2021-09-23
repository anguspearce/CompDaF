#ifndef RAFTREADINGROW_H
#define RAFTREADINGROW_H

#include <iostream>
#include <cstdint>
#include <cstdlib>
#include <raft>
#include <raftio>
#include <raftrandom>

template <typename T>
class RaftReadingRow : public raft::parallel_k
{
public:
    RaftReadingRow(T numRows,const std::size_t n_output_ports = 1);

    virtual raft::kstatus run();
    T numR;
    std::size_t output_ports;

private:
    const int NUM_VECTORS = 1;
};

#include "RaftReadingRow.tcc"
#endif