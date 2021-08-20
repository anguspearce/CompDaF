#ifndef READER_H
#define READER_H

#include <raft>
#include <raftio>
#include <raftrandom>
#include <raftmath>
#include <raftutility>
#include <numeric>

template< typename T  > class Reader : public raft::parallel_k {
    public:
        Reader(std::vector<double>& in) : raft::parallel_k()
        {
            this->in = in;
            output.template addPort<T>("s");
        };

        virtual raft::kstatus run()
        {
            /** smart obj allocate directly on output port **/
            auto out(output["s"].template allocate_s<T>());
            
            /** like an iterator, dereference the out to write to it **/
            (*out) = this->in;
            
            /** out will automatically release to the next kernel on scope exit **/
            return (raft::proceed);
        };

};


#endif