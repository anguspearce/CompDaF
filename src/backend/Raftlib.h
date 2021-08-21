#ifndef RAFTLIB_H
#define RAFTLIB_H

#include <vector>
#include <iostream>

class Raftlib{
    public:
        float sum(std::vector<std::vector<float>> &vec);
        double mean();
        double stdDev();
        double max();
        double min();
    private:
        const int NUM_THREADS = 5;

};


#endif


