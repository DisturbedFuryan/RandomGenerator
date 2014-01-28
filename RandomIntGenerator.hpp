#ifndef RANDOMINTGENERATOR_HPP
#define RANDOMINTGENERATOR_HPP

#include "RandomGenerator.hpp"
#include <cassert>
#include <random>


//======================================================================================================================
/**
 * Generates non-deterministic random integer numbers or pseudo-random, if there is no support.
 * 
 * @author   Marcin Rainka
 * @version  1.0
 */
template< typename T >
class RandomIntGenerator : public IRandomGenerator< T > {
public:
    RandomIntGenerator( void );
    
    ~RandomIntGenerator( void );
    
    /**
     * Gets a single random integer number within a range.
     * 
     * @param  min  minimum value of random number
     * @param  max  maximum value of random number
     * @return      random integer number
     */
    T GetOne( const T& min, const T& max );
    
    /**
     * Prepares for creating random integer numbers within a range.
     * 
     * @param  min  minimum value of random number
     * @param  max  maximum value of random number
     */
    void Prepare( const T& min, const T& max );
    
    /**
     * Gets a random integer number within a range defined by Prepare().
     * 
     * @return  random integer number within a defined range
     */
    T GetNext( void );


private:

    /**
     * Produces integer values evenly distributed across a range.
     */
    std::uniform_int_distribution< T >* m_uniformIntDistribution;
    
    /**
     * Cleans uniform distribution.
     */
    void CleanUniformIntDistribution( void );
};
//======================================================================================================================




template< typename T >
RandomIntGenerator< T >::RandomIntGenerator( void ) : m_uniformIntDistribution( nullptr ) {}


template< typename T >
RandomIntGenerator< T >::~RandomIntGenerator( void ) {
    CleanUniformIntDistribution();
}


template< typename T >
T RandomIntGenerator< T >::GetOne( const T& min, const T& max ) {
    std::uniform_int_distribution< T > uniformIntDistribution( min, max );
    return uniformIntDistribution( IRandomGenerator< T >::ms_defaultRandomEngine );
}


template< typename T >
void RandomIntGenerator< T >::Prepare( const T& min, const T& max ) {
    // Clean a previous uniform int distribution.
    CleanUniformIntDistribution();
    
    // Make a new one.
    m_uniformIntDistribution = new std::uniform_int_distribution< T >( min, max );
}


template< typename T >
T RandomIntGenerator< T >::GetNext( void ) {
    assert( m_uniformIntDistribution );
    return ( *m_uniformIntDistribution )( IRandomGenerator< T >::ms_defaultRandomEngine );
}


template< typename T >
void RandomIntGenerator< T >::CleanUniformIntDistribution( void ) {
    delete m_uniformIntDistribution;
    m_uniformIntDistribution = nullptr;
}


#endif
