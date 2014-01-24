#include "RandomGenerator.hpp"

using namespace std;


RandomGenerator::RandomGenerator() {
    m_defaultRandomEngine = new default_random_engine( m_randomDevice() );
}


RandomGenerator::~RandomGenerator() {
    delete m_defaultRandomEngine;
}
