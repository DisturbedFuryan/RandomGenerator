#include "RandomGenerator.hpp"


template < typename T >
IRandomGenerator< T >::IRandomGenerator( void ) {
    // Forcing the creation of objects.
    &ms_defaultRandomEngine;
    &ms_defaultRandomEngineSeeder;
}


template < typename T >
inline bool IRandomGenerator< T >::IsDeviceSupport( void ) const {
    return ms_deviceSupport;
}


template < typename T >
std::default_random_engine IRandomGenerator< T >::ms_defaultRandomEngine;


/* ms_deviceSupport is initially false, but the DefaultRandomEngineSeeder constructor will verify it. */
template < typename T >
bool IRandomGenerator< T >::ms_deviceSupport = false;


template < typename T >
typename IRandomGenerator< T >::DefaultRandomEngineSeeder IRandomGenerator< T >::ms_defaultRandomEngineSeeder;
