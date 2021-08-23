#ifndef RAFTLIB_H
#define RAFTLIB_H

#include <vector>
#include <iostream>
// #include "Raftlib.h"
#include "SplitVector.tcc"
#include "AddVector.tcc"
#include "StdvVector.tcc"

#include "Sum.tcc"

#include <raft>
#include <chrono>
#include <cmath>

using namespace std::chrono;

template <typename T>
class Raftlib
{
public:
    Raftlib(int height, int width)
    {
        this->noOfPixels = height * width;
        this->sumTotal = 0;
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
        this->sumTotal = s.total;
    }
    void mean()
    {
        this->imgMean = this->sumTotal / this->noOfPixels;
    }
    void stdDev(std::vector<std::vector<T>> &vec)
    {
        using type_v = std::vector<T>;
        using type_a = std::vector<std::pair<type_v, raft::signal>>;
        using splitvec = SplitVector<type_v>;
        using stdvvec = StdvVector<type_a, T>;
        using sum = Sum<T>;
        splitvec sp(NUM_THREADS);
        stdvvec sv(getMean());
        sum s(NUM_THREADS);
        raft::map m;

        auto readeachone(raft::read_each<type_v>(vec.begin(), vec.end()));
        m += readeachone >> sp;
        m += sp <= sv >= s;
        auto start = high_resolution_clock::now();

        m.exe();
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);
        std::cout << "Raft Stdv Time: " << duration.count() << std::endl;
        this->stdvDev = sqrt(s.total / this->noOfPixels);
    }
    double max();
    double min();
    T getSum()
    {
        return this->sumTotal;
    }
    T getMean()
    {
        return this->imgMean;
    }
    T getStdv()
    {
        return this->stdvDev;
    }

private:
    const int NUM_THREADS = 4;
    int noOfPixels;
    T sumTotal;
    T stdvDev;
    T imgMean;
};

#endif
