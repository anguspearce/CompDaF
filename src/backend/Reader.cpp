#include "Raftlib.h"
#include "Reader.h"


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


template< typename T > Reader<T>::Reader(std::vector<std::int64_t> &in) : public raft::kernel()
{
    /** declare ports **/
    this->in = *in;
    output.template addPort< T  >( "sum" );
}

template< typename T > raft::kstatus Reader<T>::run()
{
    
    

    /** smart obj allocate directly on output port **/
    auto out( output[ "sum" ].template allocate_s< T >() );
    /** like an iterator, dereference the out to write to it **/
    (*out) = std::accumulate(a.begin(), a.end(), 0);
    /** out will automatically release to the next kernel on scope exit **/
    return( raft::proceed );
}