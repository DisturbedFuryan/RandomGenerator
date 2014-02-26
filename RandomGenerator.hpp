#ifndef RANDOMGENERATOR_HPP
#define RANDOMGENERATOR_HPP

#include <cassert>
#include <random>


//==================================================================================================
/** Generates non-deterministic random numbers or pseudo-random, if there is no support.
 * 
 *  @author   Marcin Rainka
 *  @version  1.0
 */
template < typename TSpec, typename TDist >
class IRandomGenerator {
public:
    IRandomGenerator();
    ~IRandomGenerator() { CleanRandomNumberDistribution(); }

    /** Gets a single random number within a range.
     * 
     *  @param   min  minimum value of random number
     *  @param   max  maximum value of random number
     *  @return       single random number
     */
    TSpec GetOne( const TSpec& min, const TSpec& max ) const;
    
    /** Creates a single array filled with random numbers.
     *  IMPORTANT: You will have to remember about deallocation with delete[] for your own!
     * 
     *  @param   size  size of the array
     *  @param   min   minimum value of random numbers
     *  @param   max   maximum value of random numbers
     *  @return        pointer to allocated and filled array
     */
    TSpec* CreateOneArray( const unsigned long long& size,
                           const TSpec& min, const TSpec& max ) const;
    
    /** Changes an input number into random number within a range.
     * 
     *  @param  number  number going to be random
     *  @param  min     minimum value of random number
     *  @param  max     maximum value of random number
     */
    void MakeOneRandom( TSpec& number, const TSpec& min, const TSpec& max ) const;
    
    /** Fills an input array with random numbers within a range.
     *  IMPORTANT: You will have to be sure, that entered length is not too large!
     * 
     *  @param  array   array going to be filled with random numbers
     *  @param  length  number of the elements counted from the beginning
     *  @param  min     minimum value of random numbers
     *  @param  max     maximum value of random numbers
     */
    void MakeOneArrayRandom( TSpec* array, const unsigned long long& length,
                             const TSpec& min, const TSpec& max ) const;
    
    /** Prepares for creating random numbers within a range.
     * 
     *  @param  min  minimum value of random number
     *  @param  max  maximum value of random number
     */
    void Prepare( const TSpec& min, const TSpec& max );
    
    /** Gets a random number within a range defined by Prepare().
     * 
     *  @return  random number within a defined range
     */
    TSpec GetNext() const;
    
    /** Creates an array filled with random numbers within a range defined by Prepare().
     *  IMPORTANT: You will have to remember about deallocation with delete[] for your own!
     * 
     *  @param   size  size of the array
     *  @return        pointer to allocated and filled array
     */
    TSpec* CreateNextArray( const unsigned long long& size ) const;
    
    /** Changes an input number into random number within a range defined by Prepare().
     * 
     *  @param  number  number going to be random
     */
    void MakeNextRandom( TSpec& number ) const;
    
    /** Fills an input array with random numbers within a range defined by Prepare().
     *  IMPORTANT: You will have to be sure, that entered length is not too large!
     * 
     *  @param  array   array going to be filled with random numbers
     *  @param  length  number of the elements counted from the beginning
     */
    void MakeNextArrayRandom( TSpec* array, const unsigned long long& length ) const;
    
    /** Checks is there a support for non-deterministic random number generation.
     * 
     *  @return  true when there is a support and false when there is no
     */
    bool IsDeviceSupport() const { return ms_isDeviceSupport; }

private:

    /** Predefined random number generator. */
    static std::default_random_engine ms_defaultRandomEngine;
    
    /** Keeps the information about support for non-deterministic random number generation. */
    static bool ms_isDeviceSupport;
    
    /** Static member of the auxiliary DefaultRandomEngineSeeder class.
     *  Thanks to it, the default_random_engine object will be seeded only once.
     */
    static class DefaultRandomEngineSeeder {
    public:
        DefaultRandomEngineSeeder() {
            // Creating non-deterministic random number generator using hardware entropy source.
            // NOTE: Numbers may be pseudo-random, if there is no support!
            std::random_device randomDevice;
            
            // Checking is there a support for non-deterministic random number generation.
            ms_isDeviceSupport = ( randomDevice.entropy() > 0.0 );
            
            // Seeding the engine with created random generator.
            ms_defaultRandomEngine.seed( randomDevice() );
        }
    } ms_defaultRandomEngineSeeder;
    
    /** Random number distribution. */
    TDist* m_randomNumberDistribution;
    
    /** Cleans a random number distribution. */
    void CleanRandomNumberDistribution();
};
//==================================================================================================


template < typename TSpec, typename TDist >
inline IRandomGenerator< TSpec, TDist >::IRandomGenerator()
            : m_randomNumberDistribution( nullptr ) {
    // Forcing the creation of objects.
    &ms_defaultRandomEngine;
    &ms_defaultRandomEngineSeeder;
}


template < typename TSpec, typename TDist >
inline TSpec IRandomGenerator< TSpec, TDist >::GetOne( const TSpec& min, const TSpec& max ) const {
    TDist randomNumberDistribution( min, max );
    return randomNumberDistribution( ms_defaultRandomEngine );
}


template < typename TSpec, typename TDist >
TSpec* IRandomGenerator< TSpec, TDist >::CreateOneArray( const unsigned long long& size,
                                                         const TSpec& min, const TSpec& max )
                                                                                             const {
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
inline void IRandomGenerator< TSpec, TDist >::MakeOneRandom( TSpec& number, const TSpec& min,
                                                             const TSpec& max ) const {
    TDist randomNumberDistribution( min, max );
    number = randomNumberDistribution( ms_defaultRandomEngine );
}


template < typename TSpec, typename TDist >
void IRandomGenerator< TSpec, TDist >::MakeOneArrayRandom( TSpec* array,
                                                           const unsigned long long& length,
                                                           const TSpec& min, const TSpec& max )
                                                                                             const {
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
void IRandomGenerator< TSpec, TDist >::MakeNextArrayRandom( TSpec* array,
                                                            const unsigned long long& length )
                                                                                             const {
    assert( m_randomNumberDistribution );
    
    if ( length ) {
        for ( unsigned long long i = 0; i < length; ++i ) {
            array[ i ] = ( *m_randomNumberDistribution )( ms_defaultRandomEngine );
        }
    }
}


template < typename TSpec, typename TDist >
std::default_random_engine IRandomGenerator< TSpec, TDist >::ms_defaultRandomEngine;


/* ms_deviceSupport is initially false,
 * but the DefaultRandomEngineSeeder constructor will verify it.
 */
template < typename TSpec, typename TDist >
bool IRandomGenerator< TSpec, TDist >::ms_isDeviceSupport = false;


template < typename TSpec, typename TDist > typename
IRandomGenerator< TSpec, TDist >::DefaultRandomEngineSeeder
IRandomGenerator< TSpec, TDist >::ms_defaultRandomEngineSeeder;


template < typename TSpec, typename TDist >
inline void IRandomGenerator< TSpec, TDist >::CleanRandomNumberDistribution() {
    if ( m_randomNumberDistribution ) {
        delete m_randomNumberDistribution;
        m_randomNumberDistribution = nullptr;
    }
}


#endif
