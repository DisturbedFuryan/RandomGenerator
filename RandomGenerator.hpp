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
    
    /**
     * Creates an array with random integer numbers and returns pointer to the allocated array.
     * IMPORTANT: You will have to deallocate array yourself by delete[] instruction!
     * 
     * @param  size     size of array
     * @param  minimum  minimum value of random number
     * @param  maximum  maximum value of random number
     * @return          pointer to allocated array with random integer numbers
     */
    template< typename T >
    T* CreateRandomIntegerArray( const unsigned size,
                                 const T minimum = std::numeric_limits< T >::min(),
                                 const T maximum = std::numeric_limits< T >::max() ) const;
                           
    /**
     * Creates an array with random real numbers and returns pointer to the allocated array.
     * IMPORTANT: You will have to deallocate array yourself by delete[] instruction!
     * 
     * @param  size     size of array
     * @param  minimum  minimum value of random number
     * @param  maximum  maximum value of random number
     * @return          pointer to allocated array with random real numbers
     */
    template< typename T >
    T* CreateRandomRealArray( const unsigned size,
                              const T minimum = std::numeric_limits< T >::min(),
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


template< typename T >
T* RandomGenerator::CreateRandomIntegerArray( const unsigned size, const T minimum, const T maximum ) const {
    T* randomIntegerArray = nullptr;
    
    if ( size > 0 ) {
        /* Allocation. */
        randomIntegerArray = new T[ size ];
        
        std::uniform_int_distribution< T > uniformIntDist( minimum, maximum );
        
        /* Fill the array with random numbers. */
        for ( unsigned u = 0; u < size; ++u ) {
            randomIntegerArray[ u ] = uniformIntDist( *m_defaultRandomEngine );
        }
    }
    
    return randomIntegerArray;
}


template< typename T >
T* RandomGenerator::CreateRandomRealArray( const unsigned size, const T minimum, const T maximum ) const {
    T* randomRealArray = nullptr;
    
    if ( size > 0 ) {
        /* Allocation. */
        randomRealArray = new T[ size ];
        
        std::uniform_real_distribution< T > uniformRealDist( minimum, maximum );
        
        /* Fill the array with random numbers. */
        for ( unsigned u = 0; u < size; ++u ) {
            randomRealArray[ u ] = uniformRealDist( *m_defaultRandomEngine );
        }
    }
    
    return randomRealArray;
}


#endif
