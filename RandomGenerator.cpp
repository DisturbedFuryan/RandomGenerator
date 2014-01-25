#include "RandomGenerator.hpp"

using namespace std;


RandomGenerator::RandomGenerator( void ) {
    random_device randomDevice;  // Non-deterministic random number generator using hardware entropy source.
    m_defaultRandomEngine = new default_random_engine( randomDevice() );
}


RandomGenerator::~RandomGenerator( void ) {
    delete m_defaultRandomEngine;
}
