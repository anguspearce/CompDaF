#ifndef RAFTLIB_H
#define RAFTLIB_H

#include <vector>
#include <iostream>

class Raftlib{
    public:
        double sum(std::vector<std::vector<double>> &vec);
        double mean();
        double stdDev();
        double max();
        double min();

};


#endif


