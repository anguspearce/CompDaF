#ifndef RAFTSTATISTICS_H
#define RAFTSTATISTICS_H
#include <iostream>
#include <cstdint>
#include <cstdlib>
#include <raft>
#include <raftio>
#include <raftrandom>

#include "Raftlib.h"

template <typename T, typename F>
class RaftStatistics : public raft::kernel
{
public:
    F &max;
    F &min;
    RaftStatistics(F &max, F &min);
    RaftStatistics(const RaftStatistics &other);
    virtual raft::kstatus run();
    CLONE();
};
#include "RaftStatistics.tcc"
#endif