#ifndef RAFTLIB_H
#define RAFTLIB_H

#include <vector>
#include <iostream>
// #include "Raftlib.h"
#include "SplitVector.tcc"
#include "AddVector.tcc"
#include "Sum.tcc"

#include <raft>
#include <chrono>
using namespace std::chrono;

template <typename T>
class Raftlib
{
public:
    Raftlib()
    {
        this->sumTotal=0;
    }
    void sum(std::vector<std::vector<T>> &vec)
    {
        using type_v = std::vector<T>;
        using type_a = std::vector<std::pair<type_v, raft::signal>>;
        using splitvec = SplitVector<type_v>;
        using addvec = AddVector<type_a, T>;
        using sum = Sum<T>;
        splitvec sp(NUM_THREADS);
        addvec av;
        sum s(NUM_THREADS);
        raft::map m;

        auto readeachone(raft::read_each<type_v>(vec.begin(), vec.end()));
        m += readeachone >> sp;
        m += sp <= av >= s;
        auto start = high_resolution_clock::now();

        m.exe();
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);
        std::cout << "Raft Sum Time: " << duration.count() << std::endl;
        this->sumTotal=s.total;
    }
    double mean();
    double stdDev();
    double max();
    double min();
    T getSum(){
            return this->sumTotal;

    }

private:
    const int NUM_THREADS = 5;
    T sumTotal;
};

#endif
