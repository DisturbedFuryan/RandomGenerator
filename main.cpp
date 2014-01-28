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
    RandomIntGenerator< int > randIntGenerator;
    
    randIntGenerator.Prepare( 11, 20 );
    
    for ( unsigned i = 0; i < 5; ++i ) {
        cout << randIntGenerator.GetNext() << endl;
    }
    
    cout << randIntGenerator.GetOne( 1, 10) << endl;
    
    for ( unsigned i = 0; i < 5; ++i ) {
        cout << randIntGenerator.GetNext() << endl;
    }
    
    return 0;
}
//**********************************************************************************************************************
