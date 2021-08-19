#ifndef SUM_H
#define SUM_H

#include <raft>

template< typename T  > class Sum : public raft::parallel_k {
    public:
        Sum() : raft::kernel();
        virtual raft::kstatus run();
};




#endif