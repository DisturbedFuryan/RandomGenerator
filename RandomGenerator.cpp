#include "RandomGenerator.hpp"
#include <cassert>


template < typename TSpec, typename TDist >
IRandomGenerator< TSpec, TDist >::IRandomGenerator( void ) : m_uniformDistribution( nullptr ) {
    // Forcing the creation of objects.
    &ms_defaultRandomEngine;
    &ms_defaultRandomEngineSeeder;
}


template < typename TSpec, typename TDist >
IRandomGenerator< TSpec, TDist >::~IRandomGenerator( void ) {
    CleanUniformDistribution();
}


template < typename TSpec, typename TDist >
inline TSpec IRandomGenerator< TSpec, TDist >::GetOne( const TSpec& min, const TSpec& max ) const {
    TDist uniformDistribution( min, max );
    return uniformDistribution( ms_defaultRandomEngine );
}


template < typename TSpec, typename TDist >
inline void IRandomGenerator< TSpec, TDist >::MakeOneRandom( TSpec& number, const TSpec& min, const TSpec& max ) const {
    TDist uniformDistribution( min, max );
    number = uniformDistribution( ms_defaultRandomEngine );
}


template < typename TSpec, typename TDist >
inline void IRandomGenerator< TSpec, TDist >::Prepare( const TSpec& min, const TSpec& max ) {
    // Clean a previous uniform distribution.
    CleanUniformDistribution();
    
    // Make a new one.
    m_uniformDistribution = new TDist( min, max );
}


template < typename TSpec, typename TDist >
inline TSpec IRandomGenerator< TSpec, TDist >::GetNext( void ) const {
    assert( m_uniformDistribution );
    return ( *m_uniformDistribution )( ms_defaultRandomEngine );
}


template < typename TSpec, typename TDist >
inline void IRandomGenerator< TSpec, TDist >::MakeNextRandom( TSpec& number ) const {
    assert( m_uniformDistribution );
    number = ( *m_uniformDistribution )( ms_defaultRandomEngine );
}


template < typename TSpec, typename TDist >
inline bool IRandomGenerator< TSpec, TDist >::IsDeviceSupport( void ) const {
    return ms_deviceSupport;
}


template < typename TSpec, typename TDist >
std::default_random_engine IRandomGenerator< TSpec, TDist >::ms_defaultRandomEngine;


/* ms_deviceSupport is initially false, but the DefaultRandomEngineSeeder constructor will verify it. */
template < typename TSpec, typename TDist >
bool IRandomGenerator< TSpec, TDist >::ms_deviceSupport = false;


template < typename TSpec, typename TDist > typename
IRandomGenerator< TSpec, TDist >::DefaultRandomEngineSeeder
IRandomGenerator< TSpec, TDist >::ms_defaultRandomEngineSeeder;


template < typename TSpec, typename TDist >
inline void IRandomGenerator< TSpec, TDist >::CleanUniformDistribution( void ) {
    if ( m_uniformDistribution ) {
        delete m_uniformDistribution;
        m_uniformDistribution = nullptr;
    }
}
