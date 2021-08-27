#ifndef STDVVECTOR_H
#define STDVVECTOR_H

#include <iostream>
#include <cstdint>
#include <cstdlib>
#include <raft>
#include <raftio>
#include <raftrandom>
#include <cmath>
#include <math.h>
#include "Raftlib.h"

template <typename T, typename F>
class StdvVector : public raft::parallel_k
{
public:
    F mean, min;
    double binWidth;
    std::vector<int> &bins;

    StdvVector(F mean, std::vector<int> &bins, F min, double binWidth);
    StdvVector(const StdvVector &other);
    virtual raft::kstatus run();
    CLONE();
};
#include "StdvVector.tcc"
#endif