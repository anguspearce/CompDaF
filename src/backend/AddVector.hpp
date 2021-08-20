#include <iostream>
#include <cstdint>
#include <cstdlib>
#include <raft>
#include <raftio>
#include <raftrandom>

#include "Raftlib.h"

template <typename T>
class AddVector : public raft::parallel_k
{
public:
    double addVecTot;
    AddVector() : raft::parallel_k()
    {
        addVecTot = 0;

        /** define ports **/
        input.addPort<T>("addvec");
        //output.addPort<T>("total");
    }

    virtual raft::kstatus run()
    {
        T t;
        /** ports are accessed via names defined above **/
        //auto &val(input["input_a"].template peek<T>());
        //std::cout << "peek: " << val << std::endl;
        // std::vector<std::pair<T, raft::signal>> r(2);
        // std::vector<std::pair<T, raft::signal>> &t = r;
        input["addvec"].template pop(t);
        for (int i = 0; i < t.size(); i++)
        {
            for (int j = 0; j < t[i].first.size(); j++)
            {
                addVecTot += t[i].first[j];
            }
            //std::cout<<t[i].first.size()<<std::endl;
            // addVecTot += t[i][j].first;
        }

        //input["input_b"].pop(b);
        /** allocate mem directly on queue **/
        // auto c(output["sum"].template allocate_s<std::vector<std::pair<T, raft::signal>>>());
        //(*c) = t;

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