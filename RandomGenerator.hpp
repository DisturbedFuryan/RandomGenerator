#ifndef RANDOMGENERATOR_HPP
#define RANDOMGENERATOR_HPP

#include <random>


//======================================================================================================================
/**
 * Generates non-deterministic random numbers or pseudo-random, if there is no support.
 * 
 * @author   Marcin Rainka
 * @version  1.0
 */
template < typename T >
class IRandomGenerator {
public:

    IRandomGenerator( void );

    /**
     * Gets a single random number within a range.
     * 
     * @param  min  minimum value of random number
     * @param  max  maximum value of random number
     * @return      single random number
     */
    virtual T GetOne( const T& min, const T& max ) = 0;
    
    /**
     * Prepares for creating random numbers within a range.
     * 
     * @param  min  minimum value of random number
     * @param  max  maximum value of random number
     */
    virtual void Prepare( const T& min, const T& max ) = 0;
    
    /**
     * Gets a random number within a range defined by Prepare().
     * 
     * @return  random number within a defined range
     */
    virtual T GetNext( void ) = 0;
    
    /**
     * Checks is there a support for non-deterministic random number generation.
     * 
     * @return  true when there is a support and false when there is no
     */
    bool IsDeviceSupport( void ) const;


protected:

    /** 
     * Predefined random number generator.
     */
    static std::default_random_engine ms_defaultRandomEngine;
    
    /**
     * Keeps the information about support for non-deterministic random number generation.
     */
    static bool ms_deviceSupport;
    
    /**
     * Static member of the auxiliary DefaultRandomEngineSeeder class.
     * Thanks to it, the default_random_engine object will be seeded only once.
     */
    static class DefaultRandomEngineSeeder {
    public:
        DefaultRandomEngineSeeder( void ) {
            // Creating non-deterministic random number generator using hardware entropy source.
            // NOTE: Numbers may be pseudo-random, if there is no support!
            std::random_device randomDevice;
            
            // Checking is there a support for non-deterministic random number generation.
            ms_deviceSupport = ( randomDevice.entropy() > 0 );
            
            // Seeding the engine with created random generator.
            ms_defaultRandomEngine.seed( randomDevice() );
        }
    } ms_defaultRandomEngineSeeder;
};
//======================================================================================================================


#include "RandomGenerator.cpp"

#endif
