#ifndef RANDOMREALGENERATOR_HPP
#define RANDOMREALGENERATOR_HPP

#include "RandomGenerator.hpp"
#include <random>


//==================================================================================================
/** Generates non-deterministic random real numbers or pseudo-random, if there is no support.
 * 
 *  @author   Marcin Rainka
 *  @version  1.0
 */
template < typename T >
class RandomRealGenerator : public IRandomGenerator< T, std::uniform_real_distribution< T > > {};
//==================================================================================================


#endif
