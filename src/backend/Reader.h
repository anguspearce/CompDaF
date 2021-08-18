#ifndef READER_H
#define READER_H

#include <raft>

template< typename T  > class Reader : public raft::kernel {
    public:
        Reader(std::vector<std::int64_t>&) : raft::kernel();
        virtual raft::kstatus run();
};


#endif