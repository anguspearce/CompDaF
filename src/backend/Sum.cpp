#include "Raftlib.h"
#include "Sum.h"


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


template< typename T > Sum<T>::Sum() : public raft::kernel()
{
    /** declare ports **/
    input.template addPort< T >("input_arr");
    output.template addPort< T  >( "sum" );
}

template< typename T > raft::kstatus Sum<T>::run()
{
    T a;
    input[ "input_arr" ].pop( a );

    /** smart obj allocate directly on output port **/
    auto out( output[ "sum" ].template allocate_s< T >() );
    /** like an iterator, dereference the out to write to it **/
    (*out) = std::accumulate(a.begin(), a.end(), 0);
    /** out will automatically release to the next kernel on scope exit **/
    return( raft::proceed );
}