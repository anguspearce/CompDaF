#include "Raftlib.h"
#include "Sum.h"

double Raftlib::sum(std::vector<std::int64_t> vec){
    /** define type for streams **/
   using type_t = std::vector<std::int64_t>;

   /** this will be our worker 'sum' kernel **/
   using sum    = Sum< type_t >;
   sum s;
   
   raft::map m;
   /** Linking the vector to the input of the kernel**/
   m += splitAndSum >> s[ "input_arr" ];
   /** take the only output port of s and link it to the only input port of p **/
   auto total = 0;
   m += s >> total;
   /** 
    * NOTE: this will be going away soon, 
    * to be called on scope exit, an explicit
    * barrier call will enable integration with
    * sequential code.
    */
   m.exe();
   return( EXIT_SUCCESS );
}

std::vector<std::int64_t> splitAndSum(){
    return 
}