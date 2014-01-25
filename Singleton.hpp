#ifndef SINGLETON_HPP
#define SINGLETON_HPP

#include <cassert>
#include <cstdint>


//======================================================================================================================
/**
 * Template automatically defines the singleton pointer.
 * 
 * @author   Marcin Rainka
 * @version  2.0
 */
template< class T >
class ISingleton {
public:
    ISingleton( void );
    
    ~ISingleton( void );

    /**
     * @return  reference to singleton
     */
    static T& Singleton( void );
    
    /**
     * @return  pointer to singleton
     */
    static T* SingletonPtr( void );


private:

    /**
     * Pointer to singleton.
     */
    static T* ms_singleton;
};
//======================================================================================================================


template< class T >
T* ISingleton< T >::ms_singleton = nullptr;


template< class T >
inline ISingleton< T >::ISingleton( void ) {
    assert( !ms_singleton );
    intptr_t offset = ( ( intptr_t )( T* )1 - ( intptr_t )( ISingleton< T >* )( T* )1 );
    ms_singleton = ( ( T* )( ( intptr_t )this + offset ) );
}


template< class T >
inline ISingleton< T >::~ISingleton( void ) {
    assert( ms_singleton );
    ms_singleton = nullptr;
}


template< class T >
inline T& ISingleton< T >::Singleton( void ) {
    assert( ms_singleton );
    return *ms_singleton;
}


template< class T >
inline T* ISingleton< T >::SingletonPtr( void ) {
    return ms_singleton;
}


#endif
