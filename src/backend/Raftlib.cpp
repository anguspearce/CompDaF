#include "Raftlib.h"
#include "SplitVector.hpp"
#include "AddVector.hpp"
#include "Sum.hpp"

#include <raft>

double Raftlib::sum(std::vector<std::vector<double>> &vec)
{
    using type_v = std::vector<double>;
    using type_a = std::vector<std::pair<type_v, raft::signal>>;
    using splitvec = SplitVector<type_v>;
    using addvec = AddVector<type_a>;
    using sum = Sum<double>;
    splitvec sp;
    addvec av;
    sum s;
    raft::map m;

    auto readeachone(raft::read_each<type_v>(vec.begin(), vec.end()));
    m += readeachone >> sp >> av >> s;

    m.exe();

    return (s.total);
}
