#ifndef RANDOMINTGENERATOR_HPP
#define RANDOMINTGENERATOR_HPP

#include "RandomGenerator.hpp"
#include <random>


//==================================================================================================
/** Generates non-deterministic random integer numbers or pseudo-random, if there is no support.
 * 
 *  @author   Marcin Rainka
 *  @version  1.0
 */
template < typename T >
class RandomIntGenerator : public IRandomGenerator< T, std::uniform_int_distribution< T > > {};
//==================================================================================================


#endif
