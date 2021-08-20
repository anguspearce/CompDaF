#include "Raftlib.h"
//#include "Sum.h"
//#include "Reader.h"
#include "SplitVector.hpp"
#include "AddVector.hpp"
#include <raft>

double Raftlib::sum(std::vector<std::vector<double>> &vec)
{
    using type_v = std::vector<double>;
    using type_a = std::vector<std::pair<type_v, raft::signal>>;
    using splitvec = SplitVector<type_v>;
    using addvec = AddVector<type_a>;
    splitvec sp;
    addvec av;
    raft::map m;

    auto readeachone(raft::read_each<type_v>(vec.begin(), vec.end()));
    m += readeachone >> sp >> av;

    m.exe();

    // /** define type for streams **/
    // using type_t = double;

    // /** this will be our worker 'sum' kernel **/
    // using sum = Sum<type_t>;
    // sum s;

    // //using reader = Reader <type_t>;
    // //reader r(vec);
    // auto readeachone(raft::read_each<double>(vec.begin(), vec.end()));
    // //auto v(raft::insert<std::vector<double>>(vec.begin(), vec.end()));
    // using print = raft::print<type_t, '\n'>;
    // print p;
    // raft::map m;
    // /** Linking the vector to the input of the kernel**/
    // m += readeachone >> s;
    // /** take the only output port of s and link it to the only input port of p **/
    // //auto total = 0;
    // /**
    // * NOTE: this will be going away soon,
    // * to be called on scope exit, an explicit
    // * barrier call will enable integration with
    // * sequential code.
    // */
    // m.exe();
    // //std::cout<<s.total<<std::endl;

    return (av.addVecTot);
}
