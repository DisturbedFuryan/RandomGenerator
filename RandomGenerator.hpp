#ifndef RANDOMGENERATOR_HPP
#define RANDOMGENERATOR_HPP

#include "Singleton.hpp"
#include <limits>
#include <random>


//======================================================================================================================
/**
 * Generates random numbers.
 * 
 * @author   Marcin Rainka
 * @version  1.0
 */
class RandomGenerator : public ISingleton< RandomGenerator > {
public:

    RandomGenerator( void );
    
    ~RandomGenerator( void );
    
    /**
     * Returns random integer number between two values.
     * 
     * @param  minimum  minimum value of random number
     * @param  maximum  maximum value of random number
     * @return          random integer number
     */
    template< typename T >
    T RandomIntegerNumber( const T minimum = std::numeric_limits< T >::min(),
                           const T maximum = std::numeric_limits< T >::max() ) const;
    
    /**
     * Returns random real number between two values.
     * 
     * @param  minimum  minimum value of random number
     * @param  maximum  maximum value of random number
     * @return          random real number
     */
    template< typename T >
    T RandomRealNumber( const T minimum = std::numeric_limits< T >::min(),
                        const T maximum = std::numeric_limits< T >::max() ) const;


private:

    /** 
     * Predefined random number generator.
     */
    std::default_random_engine* m_defaultRandomEngine;
};
//======================================================================================================================


template< typename T >
inline T RandomGenerator::RandomIntegerNumber( const T minimum, const T maximum ) const {
    std::uniform_int_distribution< T > uniformIntDist( minimum, maximum );
    return uniformIntDist( *m_defaultRandomEngine );
}


template< typename T >
inline T RandomGenerator::RandomRealNumber( const T minimum, const T maximum ) const {
    std::uniform_real_distribution< T > uniformRealDist( minimum, maximum );
    return uniformRealDist( *m_defaultRandomEngine );
}


#endif
