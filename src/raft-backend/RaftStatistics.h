#ifndef RAFTSTATISTICS_H
#define RAFTSTATISTICS_H
#include <iostream>
#include <cstdint>
#include <cstdlib>
#include <raft>
#include <raftio>
#include <raftrandom>

template <typename T, typename F>
class RaftStatistics : public raft::kernel
{
public:

    F min;
    F max;
    RaftStatistics();
    RaftStatistics(const RaftStatistics &other);
    virtual raft::kstatus run();
    CLONE();
};
#include "RaftStatistics.tcc"
#endif