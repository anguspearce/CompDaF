#ifndef SUM_H
#define SUM_H

#include <raft>

template< typename T  > class Sum : public raft::kernel {
    public:
        Sum() : raft::kernel();
        virtual raft::kstatus run();
};


#endif