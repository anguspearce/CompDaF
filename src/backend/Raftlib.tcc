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
#include <algorithm>
#include <math.h>

using namespace std::chrono;

template <typename T>
class Raftlib
{
public:
    Raftlib(long *naxes)
    {
        this->width=naxes[0];
        this->height=naxes[1];
        this->depth=naxes[2];
        //this->noOfPixels = naxes[0] * naxes[1] *naxes[2];
        this->sumTotal = 0;
    }
    void sum(std::vector<std::vector<T>> &vec)
    {

        using type_v = std::vector<T>;
        using type_a = std::vector<std::pair<type_v, raft::signal>>;
        using splitvec = SplitVector<type_v>;
        using addvec = AddVector<type_a, T>;
        using sum = Sum<T>;
        this->max = -999999;
        this->min = 999999;

        splitvec sp(NUM_THREADS);
        addvec av(max, min);
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
        this->imgMean = this->sumTotal / (this->width*this->height*this->depth);
    }
    void stdDev(std::vector<std::vector<T>> &vec)
    {
        using type_v = std::vector<T>;
        using type_a = std::vector<std::pair<type_v, raft::signal>>;
        using splitvec = SplitVector<type_v>;
        using stdvvec = StdvVector<type_a, T>;
        using sum = Sum<T>;
        calculateBins();
        std::vector<int> lbins(this->noOfBins, 0);
        this->bins = lbins;
        splitvec sp(NUM_THREADS);
        stdvvec sv(getMean(), bins, this->min, this->binWidth);
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
        this->stdvDev = sqrt(s.total / (this->width*this->height*this->depth));
    }
    void calculateBins()
    {
        this->noOfBins = int(std::max(2.0, sqrt((this->width*this->height))));
        this->binWidth = (this->max - this->min) / this->noOfBins;
    }
    void getBins(int &nBins, double &bWidth, std::vector<int> &bins)
    {
        nBins = this->noOfBins;
        bWidth = this->binWidth;
        bins = this->bins;
    }
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
    const int NUM_THREADS = 5;
    //long noOfPixels;
    long width;
    long height;
    long depth;
    T sumTotal;
    T stdvDev;
    T imgMean;
    T max;
    T min;
    int noOfBins;
    double binWidth;
    std::vector<int> bins;
};

#endif
