#include "RandomIntGenerator.hpp"
#include "RandomRealGenerator.hpp"
#include <iostream>

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
    // Creating a random integer generator, precisely - the random int type numbers generator.
    RandomIntGenerator< int > randomIntGenerator;
    
    // Print information about support.
    cout << "There is "
         << ( randomIntGenerator.IsDeviceSupport() ? "device support, hooray!" : "no device support, sorry." ) << endl;
    
    randomIntGenerator.Prepare( 1, 100 );
    
    int* array = randomIntGenerator.CreateNextArray( 10 );
    
    cout << "[ ";
    for ( unsigned i = 0; i < 10; ++i ) {
        cout << array[ i ] << " ";
    }
    cout << "]\n";
    
    delete[] array;
    
    return 0;
}
//**********************************************************************************************************************
