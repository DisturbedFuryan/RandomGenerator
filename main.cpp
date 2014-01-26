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
    
    /* Random number of the int type. */
    cout << "Random int: " << randomGenerator.RandomIntegerNumber< int >() << endl;
    
    /* Random number of the double type. */
    cout << "Random double: " << randomGenerator.RandomRealNumber< double >() << endl;
    
    /* Array with random numbers of the int type. */
    int* randomIntArray = randomGenerator.CreateRandomIntegerArray< int >( 5 );
    cout << "Random array with ints: [ ";
    for ( unsigned i = 0; i < 5; ++i ) {
        cout << randomIntArray[ i ] << " ";
    }
    cout << "]\n";
    delete[] randomIntArray;
    
    /* Array with random numbers of the double type. */
    double* randomDoubleArray = randomGenerator.CreateRandomRealArray< double >( 5 );
    cout << "Random array with doubles: [ ";
    for ( unsigned i = 0; i < 5; ++i ) {
        cout << randomDoubleArray[ i ] << " ";
    }
    cout << "]\n";
    delete[] randomDoubleArray;
    
    return 0;
}
//**********************************************************************************************************************
