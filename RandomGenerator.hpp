#ifndef RANDOMGENERATOR_H
#define RANDOMGENERATOR_H

#include <random>


//======================================================================================================================
/**
 * Generates random numbers.
 * 
 * @author Marcin Rainka
 * @version 1.0
 */
class RandomGenerator {
public:
    RandomGenerator();
    
    ~RandomGenerator();
    
    /**
     * Returns random number between two values of an integer type.
     * 
     * @param minimum  minimum value of random number
     * @param maximum  maximum value of random number
     * @return         random number of an integer type
     */
    int RandomNumber( int minimum, int maximum );
    
    /**
     * Returns random number between two values of an unsigned integer type.
     * 
     * @param minimum  minimum value of random number
     * @param maximum  maximum value of random number
     * @return         random number of an unsigned integer type
     */
    unsigned int RandomNumber( unsigned int minimum, unsigned int maximum );
    
    /**
     * Returns random number between two values of a double type.
     * 
     * @param minimum  minimum value of random number
     * @param maximum  maximum value of random number
     * @return         random number of a double type
     */
    double RandomNumber( double minimum, double maximum );
    
private:
    /** Non-deterministic random number generator using hardware entropy source. */
    std::random_device m_randomDevice;
    
    /** Predefined random number generator. */
    std::default_random_engine* m_defaultRandomEngine;
};
//======================================================================================================================


inline int RandomGenerator::RandomNumber( int minimum, int maximum ) {
    std::uniform_int_distribution<int> uniformIntDist( minimum, maximum );
    return uniformIntDist( *m_defaultRandomEngine );
}


inline unsigned int RandomGenerator::RandomNumber( unsigned int minimum, unsigned int maximum ) {
    std::uniform_int_distribution<unsigned int> uniformIntDist( minimum, maximum );
    return uniformIntDist( *m_defaultRandomEngine );
}


inline double RandomGenerator::RandomNumber( double minimum, double maximum ) {
    std::uniform_real_distribution<double> uniformRealDist( minimum, maximum );
    return uniformRealDist( *m_defaultRandomEngine );
}


#endif
