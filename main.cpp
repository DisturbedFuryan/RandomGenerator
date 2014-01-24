#include "RandomGenerator.hpp"
#include <iostream>
#include <limits>

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
    
    /* Random numbers of an integer type. */
    cout << "Random integers <-10;10>: ";
    for ( int i = 0; i < 10; ++i ) {
        cout << randomGenerator.RandomNumber( -10, 10 ) << " ";
    }
    cout << endl;
    
    /* Random numbers of an unsigned integer type. */
    
    unsigned int maxUnsignedInt = numeric_limits<unsigned int>::max();
    
    cout << "Random unsigned integers <" << ( maxUnsignedInt - 10 ) << ";" << maxUnsignedInt << ">: ";
    for ( int i = 0; i < 10; ++i ) {
        cout << randomGenerator.RandomNumber( ( maxUnsignedInt - 10 ), maxUnsignedInt ) << " ";
    }
    cout << endl;
    
    /* Random numbers of a double type. */
    cout << "Random doubles (0;1): ";
    for ( int i = 0; i < 10; ++i ) {
        cout << randomGenerator.RandomNumber( 0.0d, 1.0d ) << " ";
    }
    cout << endl;
    
    return 0;
}
//**********************************************************************************************************************
