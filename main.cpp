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
    RandomIntGenerator< int > randIntGenerator;
    
    // Print information about support.
    cout << "There is "
         << ( randIntGenerator.IsDeviceSupport() ? "device support, hooray!" : "no device support, sorry." ) << endl;
    
    randIntGenerator.Prepare( 1, 10 );
    
    for ( unsigned i = 0; i < 10; ++i ) {
        cout << randIntGenerator.GetNext() << " ";
    }
    cout << endl;
    
    RandomRealGenerator< double > randRealGenerator;
    
    randRealGenerator.Prepare( 0.0d, 1.0d );
    
    for ( unsigned i = 0; i < 10; ++i ) {
        cout << randRealGenerator.GetNext() << " ";
    }
    cout << endl;
    
    return 0;
}
//**********************************************************************************************************************
