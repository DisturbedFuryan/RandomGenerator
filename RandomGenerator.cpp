#include "RandomGenerator.hpp"
#include <cassert>


template < typename TSpec, typename TDist >
IRandomGenerator< TSpec, TDist >::IRandomGenerator( void ) : m_randomNumberDistribution( nullptr ) {
    // Forcing the creation of objects.
    &ms_defaultRandomEngine;
    &ms_defaultRandomEngineSeeder;
}


template < typename TSpec, typename TDist >
IRandomGenerator< TSpec, TDist >::~IRandomGenerator( void ) {
    CleanRandomNumberDistribution();
}


template < typename TSpec, typename TDist >
inline TSpec IRandomGenerator< TSpec, TDist >::GetOne( const TSpec& min, const TSpec& max ) const {
    TDist randomNumberDistribution( min, max );
    return randomNumberDistribution( ms_defaultRandomEngine );
}


template < typename TSpec, typename TDist >
TSpec* IRandomGenerator< TSpec, TDist >::CreateOneArray( const unsigned long long& size,
                                                         const TSpec& min, const TSpec& max ) const {
    TSpec* randomArray = nullptr;
    
    if ( size ) {
        randomArray = new TSpec[ size ];
        
        TDist randomNumberDistribution( min, max );
        
        for ( unsigned long long i = 0; i < size; ++i ) {
            randomArray[ i ] = randomNumberDistribution( ms_defaultRandomEngine );
        }
    }
    
    return randomArray;
}


template < typename TSpec, typename TDist >
inline void IRandomGenerator< TSpec, TDist >::MakeOneRandom( TSpec& number, const TSpec& min, const TSpec& max ) const {
    TDist randomNumberDistribution( min, max );
    number = randomNumberDistribution( ms_defaultRandomEngine );
}


template < typename TSpec, typename TDist >
void IRandomGenerator< TSpec, TDist >::MakeOneArrayRandom( TSpec* array, const unsigned long long& length,
                                                           const TSpec& min, const TSpec& max ) const {
    if ( length ) {
        TDist randomNumberDistribution( min, max );
        
        for ( unsigned long long i = 0; i < length; ++i ) {
            array[ i ] = randomNumberDistribution( ms_defaultRandomEngine );
        }
    }
}


template < typename TSpec, typename TDist >
inline void IRandomGenerator< TSpec, TDist >::Prepare( const TSpec& min, const TSpec& max ) {
    // Clean a previous distribution.
    CleanRandomNumberDistribution();
    
    // Make a new one.
    m_randomNumberDistribution = new TDist( min, max );
}


template < typename TSpec, typename TDist >
inline TSpec IRandomGenerator< TSpec, TDist >::GetNext( void ) const {
    assert( m_randomNumberDistribution );
    return ( *m_randomNumberDistribution )( ms_defaultRandomEngine );
}


template < typename TSpec, typename TDist >
TSpec* IRandomGenerator< TSpec, TDist >::CreateNextArray( const unsigned long long& size ) const {
    assert( m_randomNumberDistribution );
    
    TSpec* randomArray = nullptr;
    
    if ( size ) {
        randomArray = new TSpec[ size ];
        
        for ( unsigned long long i = 0; i < size; ++i ) {
            randomArray[ i ] = ( *m_randomNumberDistribution )( ms_defaultRandomEngine );
        }
    }
    
    return randomArray;
}


template < typename TSpec, typename TDist >
inline void IRandomGenerator< TSpec, TDist >::MakeNextRandom( TSpec& number ) const {
    assert( m_randomNumberDistribution );
    number = ( *m_randomNumberDistribution )( ms_defaultRandomEngine );
}


template < typename TSpec, typename TDist >
void IRandomGenerator< TSpec, TDist >::MakeNextArrayRandom( TSpec* array, const unsigned long long& length ) const {
    assert( m_randomNumberDistribution );
    
    if ( length ) {
        for ( unsigned long long i = 0; i < length; ++i ) {
            array[ i ] = ( *m_randomNumberDistribution )( ms_defaultRandomEngine );
        }
    }
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
inline void IRandomGenerator< TSpec, TDist >::CleanRandomNumberDistribution( void ) {
    if ( m_randomNumberDistribution ) {
        delete m_randomNumberDistribution;
        m_randomNumberDistribution = nullptr;
    }
}
