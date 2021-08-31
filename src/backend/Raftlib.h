#ifndef RAFTLIB_H
#define RAFTLIB_H

#include <vector>
#include <iostream>
// #include "Raftlib.h"
#include "SplitVector.h"
#include "AddVector.h"
#include "StdvVector.h"
#include "Sum.h"

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
    Raftlib(long *naxes,long totPixels);
    void sum(std::vector<std::vector<T>> &vec);
    void mean();
    void stdDev(std::vector<std::vector<T>> &vec);
    void calculateBins();
    void getBins(int &nBins, double &bWidth, std::vector<int> &bins);
    T getSum();
    T getMean();
    T getStdv();
    void getMinAndMax(T &imgMin, T &imgMax);
    T getBinCenter();

private:
    const int NUM_THREADS = 5;
    long noOfPixels;
    long width;
    long height;
    long depth;
    T sumTotal;
    T stdvDev;
    T imgMean;
    T max;
    T min;
    T firstBinCenter;
    int noOfBins;
    double binWidth;
    std::vector<int> bins;
};
#include "Raftlib.tcc"
#endif
