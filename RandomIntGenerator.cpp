#include "RandomIntGenerator.hpp"


template < typename T >
RandomIntGenerator< T >::RandomIntGenerator( void ) : m_uniformIntDistribution( nullptr ) {}


template < typename T >
RandomIntGenerator< T >::~RandomIntGenerator( void ) {
    CleanUniformIntDistribution();
}


template < typename T >
T RandomIntGenerator< T >::GetOne( const T& min, const T& max ) {
    std::uniform_int_distribution< T > uniformIntDistribution( min, max );
    return uniformIntDistribution( IRandomGenerator< T >::ms_defaultRandomEngine );
}


template < typename T >
void RandomIntGenerator< T >::Prepare( const T& min, const T& max ) {
    // Clean a previous uniform int distribution.
    CleanUniformIntDistribution();
    
    // Make a new one.
    m_uniformIntDistribution = new std::uniform_int_distribution< T >( min, max );
}


template < typename T >
T RandomIntGenerator< T >::GetNext( void ) {
    assert( m_uniformIntDistribution );
    return ( *m_uniformIntDistribution )( IRandomGenerator< T >::ms_defaultRandomEngine );
}


template < typename T >
void RandomIntGenerator< T >::CleanUniformIntDistribution( void ) {
    if ( m_uniformIntDistribution ) {
        delete m_uniformIntDistribution;
        m_uniformIntDistribution = nullptr;
    }
}
