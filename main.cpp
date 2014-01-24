#include "RandomGenerator.hpp"
#include <iostream>

using namespace std;


//**********************************************************************************************************************
/**
 * The main() function.
 * 
 * @param argc  indicates how many arguments were entered on the command line when the program was started
 * @param argv  the arguments that were entered on the command line when the program was started
 * @return      indication how the program exited
 */
int main( int argc, char** argv ) {
    RandomGenerator randomGenerator;
    
    for ( int i = 0; i < 10; ++i ) {
        cout << randomGenerator.RandomNumber( 0.0d, 1.0d ) << endl;
    }
    
    return 0;
}
//**********************************************************************************************************************
