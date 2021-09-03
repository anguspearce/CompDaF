#ifndef RAFTLIB_H
#define RAFTLIB_H

#include <vector>
#include <iostream>
// #include "Raftlib.h"
#include "SplitVector.h"
#include "RaftStatistics.h"
#include "RaftHistogram.h"
#include "Sum.h"
#include "MergeBins.h"

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
    void statistics(std::vector<std::vector<T>> &vec);
    void mean();
    void calcStdv();
    void histogram(std::vector<std::vector<T>> &vec);
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
    T sumsquares;
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
