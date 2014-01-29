#include "RandomIntGenerator.hpp"
#include <iostream>

using namespace std;


/*
    TODO:
    
    RandomGenerator< double > randomDoublesGenerator;
    
    randomDoublesGenerator.GetOne( 0.0d, 1.0d );
    
    double* array = randomDoublesGenerator.CreateArray( 2000000, 0.0d, 1.0d );
    
    double number;
    randomDoublesGenerator.MakeRandom( number, 0.0d, 1.0d );
    randomDoublesGenerator.MakeRandom( array, 2000000, 0.0d, 1.0d );
    
    delete[] array;
*/


//**********************************************************************************************************************
/**
 * The main() function.
 * 
 * @param  argc  indicates how many arguments were entered on the command line when the program was started
 * @param  argv  the arguments that were entered on the command line when the program was started
 * @return       indication how the program exited
 */
int main( int argc, char** argv ) {
    // Creating random integer generator, precisely - the random int type numbers generator.
    RandomIntGenerator< int > randIntGenerator;
    
    // Print information about support.
    cout << "There is "
         << ( randIntGenerator.IsDeviceSupport() ? "device support, hooray!" : "no device support, sorry." ) << endl;
    
    return 0;
}
//**********************************************************************************************************************
