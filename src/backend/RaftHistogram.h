#ifndef RAFTHISTOGRAM_H
#define RAFTHISTOGRAM_H

#include <iostream>
#include <cstdint>
#include <cstdlib>
#include <raft>
#include <raftio>
#include <raftrandom>
#include <cmath>
#include <math.h>
#include "Raftlib.h"
#include <map>
template <typename T, typename F>
class RaftHistogram : public raft::kernel
{
public:
    F mean, min;
    double binWidth;
    //std::vector<int> &bins;

    RaftHistogram(F mean, F min, double binWidth);
    RaftHistogram(const RaftHistogram &other);
    virtual raft::kstatus run();
    CLONE();
};
#include "RaftHistogram.tcc"
#endif