#ifndef ADDVECTOR_H
#define ADDVECTOR_H
#include <iostream>
#include <cstdint>
#include <cstdlib>
#include <raft>
#include <raftio>
#include <raftrandom>

#include "Raftlib.h"

template <typename T, typename F>
class AddVector : public raft::parallel_k
{
public:
    F &max;
    F &min;
    AddVector(F &max, F &min);
    AddVector(const AddVector &other);
    virtual raft::kstatus run();
    CLONE();
};
#include "AddVector.tcc"
#endif