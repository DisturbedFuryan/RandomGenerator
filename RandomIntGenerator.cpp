#include "RandomIntGenerator.hpp"


template < typename T >
RandomIntGenerator< T >::RandomIntGenerator( void ) : m_uniformIntDistribution( nullptr ) {}


template < typename T >
RandomIntGenerator< T >::~RandomIntGenerator( void ) {
    CleanUniformIntDistribution();
}


template < typename T >
inline T RandomIntGenerator< T >::GetOne( const T& min, const T& max ) const {
    std::uniform_int_distribution< T > uniformIntDistribution( min, max );
    return uniformIntDistribution( IRandomGenerator< T >::ms_defaultRandomEngine );
}


template < typename T >
inline void RandomIntGenerator< T >::MakeOneRandom( T& number, const T& min, const T& max ) const {
    std::uniform_int_distribution< T > uniformIntDistribution( min, max );
    number = uniformIntDistribution( IRandomGenerator< T >::ms_defaultRandomEngine );
}


template < typename T >
inline void RandomIntGenerator< T >::Prepare( const T& min, const T& max ) {
    // Clean a previous uniform int distribution.
    CleanUniformIntDistribution();
    
    // Make a new one.
    m_uniformIntDistribution = new std::uniform_int_distribution< T >( min, max );
}


template < typename T >
inline T RandomIntGenerator< T >::GetNext( void ) const {
    assert( m_uniformIntDistribution );
    return ( *m_uniformIntDistribution )( IRandomGenerator< T >::ms_defaultRandomEngine );
}


template < typename T >
inline void RandomIntGenerator< T >::MakeNextRandom( T& number ) const {
    assert( m_uniformIntDistribution );
    number = ( *m_uniformIntDistribution )( IRandomGenerator< T >::ms_defaultRandomEngine );
}


template < typename T >
inline void RandomIntGenerator< T >::CleanUniformIntDistribution( void ) {
    if ( m_uniformIntDistribution ) {
        delete m_uniformIntDistribution;
        m_uniformIntDistribution = nullptr;
    }
}
