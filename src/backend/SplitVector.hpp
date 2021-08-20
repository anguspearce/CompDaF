#include <iostream>
#include <cstdint>
#include <cstdlib>
#include <raft>
#include <raftio>
#include <raftrandom>

#include "Raftlib.h"

template <typename T>
class SplitVector : public raft::parallel_k
{
public:
    //T total = 0;
    SplitVector() : raft::parallel_k()
    {
        /** define ports **/
        input.addPort<T>("a");
        output.addPort<std::vector<std::pair<T, raft::signal>>>("split");
    }

    virtual raft::kstatus run()
    {
        //T a;
        /** ports are accessed via names defined above **/
        //auto &val(input["input_a"].template peek<T>());
        //std::cout << "peek: " << val << std::endl;
        std::vector<std::pair<T, raft::signal>> r(2);
        std::vector<std::pair<T, raft::signal>> &t = r;
        input["a"].template pop_range(t, 2);

        //input["input_b"].pop(b);
        /** allocate mem directly on queue **/
        auto c(output["split"].template allocate_s<std::vector<std::pair<T, raft::signal>>>());
        (*c) = t;

        //std::cout << "total vec = " << counter << std::endl;
        //std::cout << "peek: " << val << std::endl;

        //total += val;
        /** 
       * mem for C pushed to queue on scope exit, proceed 
       * signals the run-time to continue 
       */
        return (raft::proceed);
    }
};