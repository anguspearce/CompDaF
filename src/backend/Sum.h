#ifndef SUM_H
#define SUM_H
#include <cassert>
#include <iostream>
#include <cstdint>
#include <cstdlib>
#include <raft>
#include <raftio>
#include <raftrandom>
#include <raftmath>
#include <raftutility>
#include <numeric>


template< typename T  > class Sum : public raft::parallel_k {
    public:
        T total = 0;
        Sum() : raft::parallel_k() 
        {
            //this->in = in;
            input.template addPort<T>("a");

            //output.template addPort<T>("sum");
        };

        virtual raft::kstatus run()
        {
            T a;
            //input["a"].insert(this->in.begin(), this->in.end());

            input["a"].pop(a);
            total += a;

            /** smart obj allocate directly on output port **/
            //auto out(output["sum"].template allocate_s<T>());
            /** like an iterator, dereference the out to write to it **/
            //(*out) = total;
            /** out will automatically release to the next kernel on scope exit **/
            return (raft::proceed);
        };
};




#endif