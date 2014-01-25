#include "RandomGenerator.hpp"
#include <iostream>
#include <limits>

using namespace std;


//**********************************************************************************************************************
/**
 * The main() function.
 * 
 * @param  argc  indicates how many arguments were entered on the command line when the program was started
 * @param  argv  the arguments that were entered on the command line when the program was started
 * @return       indication how the program exited
 */
int main( int argc, char** argv ) {
    RandomGenerator randomGenerator;
    
    /* Random numbers of the int type. */
    cout << "Random ints: ";
    for ( int i = 0; i < 10; ++i ) {
        cout << randomGenerator.RandomIntegerNumber< int >() << " ";
    }
    cout << endl;
    
    /* Random numbers of the double type. */
    cout << "Random doubles: ";
    for ( int i = 0; i < 10; ++i ) {
        cout << randomGenerator.RandomRealNumber< double >() << " ";
    }
    cout << endl;
    
    return 0;
}
//**********************************************************************************************************************
