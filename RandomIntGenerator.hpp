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
template < typename T >
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


#include "RandomIntGenerator.cpp"

#endif
