#ifndef RAFTREADIMAGE_H
#define RAFTREADIMAGE_H
#include <iostream>
#include <cstdint>
#include <cstdlib>
#include <raft>
#include <raftio>
#include <raftrandom>

#include "Raftlib.h"

template <typename T>
class RaftReadImage : public raft::kernel
{
public:
    long naxes[3] = {1, 1, 1},fpixel[3]={1, 1, 1};
    int bitpix, naxis;
    int status;
    long totPixels;
    float *pixels;
    fitsfile *fptr;
    long readTime=0;
    RaftReadImage(fitsfile *fptr);
    //RaftReadImage(const RaftReadImage &other);
    virtual raft::kstatus run();
    //CLONE();
};
#include "RaftReadImage.tcc"
#endif