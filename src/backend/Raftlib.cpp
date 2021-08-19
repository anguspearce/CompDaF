#include "Raftlib.h"
#include "Sum.h"
//#include "Reader.h"
#include <raft>

double Raftlib::sum(std::vector<double> &vec)
{
    /** define type for streams **/
    using type_t = std::vector<double>;

    /** this will be our worker 'sum' kernel **/
    using sum = Sum<type_t>;
    sum s;

    using reader = Reader <type_t>;
    reader r(vec);
    //auto readeachone(raft::read_each<double>(vec.begin(), vec.end()));
    using print = raft::print<type_t, '\n'>;
    print p;
    raft::map m;
    /** Linking the vector to the input of the kernel**/
    m += r >> s["input_arr"];
    /** take the only output port of s and link it to the only input port of p **/
    //auto total = 0;
    m += s >> p;
    /** 
    * NOTE: this will be going away soon, 
    * to be called on scope exit, an explicit
    * barrier call will enable integration with
    * sequential code.
    */
    m.exe();
    return (EXIT_SUCCESS);
}
