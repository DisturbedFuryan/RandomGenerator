#include "RandomIntGenerator.hpp"
#include "RandomRealGenerator.hpp"
#include <iostream>

using namespace std;


template < typename T >
void PrintArray( const T* array, const unsigned long long& size ) {
    if ( size ) {
        cout << "[ ";
        
        for ( unsigned long long i = 0; i < size; ++i ) {
            cout << array[ i ] << " ";
        }
        
        cout << "]\n";
    }
}


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
    RandomIntGenerator< int > randomIntsGenerator;
    
    // Creating a random real generator, precisely - the random double type numbers generator.
    RandomRealGenerator< double > randomDoublesGenerator;
    
    // Print information about support.
    cout << "There is "
         << ( randomIntsGenerator.IsDeviceSupport() ? "device support, hooray!" : "no device support, sorry." )
         << endl << endl;
    
    //------------------------------------------------------------------------------------------------------------------
    // Let's see how it works for creating single numbers and arrays!
    //------------------------------------------------------------------------------------------------------------------
    
    // Getting single random number.
    //------------------------------------------------------------------------------------------------------------------
    
    cout << "Single random int type number within < 1; 100 >: " << randomIntsGenerator.GetOne( 1, 100) << endl;
    cout << "Single random double type number within ( 0; 1 ): " << randomDoublesGenerator.GetOne( 0.0d, 1.0d)
         << endl << endl;
    
    // Creating a single array filled with random numbers.
    //------------------------------------------------------------------------------------------------------------------
    
    int* randomIntsArray = randomIntsGenerator.CreateOneArray( 10, 1, 100 );
    double* randomDoublesArray = randomDoublesGenerator.CreateOneArray( 10, 0.0d, 1.0d );
    
    cout << "Single random array filled with random int type numbers within < 1; 100 >:\n";
    PrintArray< int >( randomIntsArray, 10 );
    cout << endl;
    
    cout << "Single random array filled with random double type numbers within < 0; 1 >:\n";
    PrintArray< double >( randomDoublesArray, 10 );
    cout << endl;
    
    delete[] randomIntsArray;
    delete[] randomDoublesArray;
    
    // Changing a single number created before into random number.
    //------------------------------------------------------------------------------------------------------------------
    
    int intNumber;
    double doubleNumber;
    
    randomIntsGenerator.MakeOneRandom( intNumber, 1, 100 );
    randomDoublesGenerator.MakeOneRandom( doubleNumber, 0.0d, 1.0d );
    
    cout << "Single int type number changed into random within < 1; 100 >: " << intNumber << endl;
    cout << "Single double type number changed into random within ( 0; 1 ): " << doubleNumber << endl << endl;
    
    // Filling a single array created before with random numbers.
    //------------------------------------------------------------------------------------------------------------------
    
    int intsArray[ 10 ];
    double doublesArray[ 10 ];
    
    randomIntsGenerator.MakeOneArrayRandom( intsArray, 10, 1, 100 );
    randomDoublesGenerator.MakeOneArrayRandom( doublesArray, 10, 0.0d, 1.0d );
    
    cout << "Single array created before and filled with random int type numbers within < 1; 100 >:\n";
    PrintArray< int >( intsArray, 10 );
    cout << endl;
    
    cout << "Single array created before and filled with random double type numbers within < 0; 1 >:\n";
    PrintArray< double >( doublesArray, 10 );
    cout << endl;
    
    return 0;
}
//**********************************************************************************************************************
