#include "Raftlib.h"
#include "SplitVector.hpp"
#include "AddVector.hpp"
#include "Sum.hpp"

#include <raft>
#include <chrono>
using namespace std::chrono;

float Raftlib::sum(std::vector<std::vector<float>> &vec)
{
    using type_v = std::vector<float>;
    using type_a = std::vector<std::pair<type_v, raft::signal>>;
    using splitvec = SplitVector<type_v>;
    using addvec = AddVector<type_a,float>;
    using sum = Sum<float>;
    splitvec sp(NUM_THREADS);
    addvec av;
    sum s(NUM_THREADS);
    raft::map m;

    auto readeachone(raft::read_each<type_v>(vec.begin(), vec.end()));
    m += readeachone >> sp ;
    m += sp <= av >= s;
    auto start = high_resolution_clock::now();

    m.exe();
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    std::cout << "Raft Sum Time: " << duration.count() << std::endl;

    return (s.total);
}
