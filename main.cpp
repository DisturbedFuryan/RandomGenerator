#include "RandomIntGenerator.hpp"
#include "RandomRealGenerator.hpp"
#include <iostream>

using namespace std;


/**
 * Prints an input array.
 * 
 * @param  array  array to be printed
 * @param  size   size of the array
 */
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
         << ( randomIntsGenerator.isDeviceSupport() ? "device support, hooray!" : "no device support, sorry." )
         << endl << endl;
    
    //------------------------------------------------------------------------------------------------------------------
    // Let's see how it works for creating single numbers and arrays!
    //------------------------------------------------------------------------------------------------------------------
    
    // Getting single random number.
    //------------------------------------------------------------------------------------------------------------------
    
    cout << "Single random int type number within < 1; 100 >: " << randomIntsGenerator.getOne( 1, 100) << endl;
    cout << "Single random double type number within ( 0; 1 ): " << randomDoublesGenerator.getOne( 0.0, 1.0)
         << endl << endl;
    
    // Creating a single array filled with random numbers.
    //------------------------------------------------------------------------------------------------------------------
    
    int* randomIntsArray = randomIntsGenerator.createOneArray( 10, 1, 100 );
    double* randomDoublesArray = randomDoublesGenerator.createOneArray( 10, 0.0, 1.0 );
    
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
    
    randomIntsGenerator.makeOneRandom( intNumber, 1, 100 );
    randomDoublesGenerator.makeOneRandom( doubleNumber, 0.0, 1.0 );
    
    cout << "Single int type number changed into random within < 1; 100 >: " << intNumber << endl;
    cout << "Single double type number changed into random within ( 0; 1 ): " << doubleNumber << endl << endl;
    
    // Filling a single array created before with random numbers.
    //------------------------------------------------------------------------------------------------------------------
    
    int intsArray[ 10 ];
    double doublesArray[ 10 ];
    
    randomIntsGenerator.makeOneArrayRandom( intsArray, 10, 1, 100 );
    randomDoublesGenerator.makeOneArrayRandom( doublesArray, 10, 0.0, 1.0 );
    
    cout << "Single array created before and filled with random int type numbers within < 1; 100 >:\n";
    PrintArray< int >( intsArray, 10 );
    cout << endl;
    
    cout << "Single array created before and filled with random double type numbers within < 0; 1 >:\n";
    PrintArray< double >( doublesArray, 10 );
    cout << endl;
    
    //------------------------------------------------------------------------------------------------------------------
    // Let's see how it works for creating sequences of numbers and arrays!
    //------------------------------------------------------------------------------------------------------------------
    
    // Defining a range for future random numbers.
    randomIntsGenerator.prepare( 1, 100 );
    randomDoublesGenerator.prepare( 0.0, 1.0 );
    
    // Getting a sequence of random numbers within defined range.
    //------------------------------------------------------------------------------------------------------------------
    
    cout << "Sequence of random int type numbers within defined range < 1; 100 >:\n";
    for ( unsigned i = 0; i < 10; ++i ) {
        cout << randomIntsGenerator.getNext() << " ";
    }
    cout << endl << endl;
    
    cout << "Sequence of random double type numbers within defined range ( 0; 1 ):\n";
    for ( unsigned i = 0; i < 10; ++i ) {
        cout << randomDoublesGenerator.getNext() << " ";
    }
    cout << endl << endl;
    
    // Creating a sequence of arrays filled with random numbers within defined range.
    //------------------------------------------------------------------------------------------------------------------
    
    int* randomIntsArrays[ 4 ];
    double* randomDoublesArrays[ 4 ];
    
    for ( unsigned i = 0; i < 4; ++i ) {
        randomIntsArrays[ i ] = randomIntsGenerator.createNextArray( 10 );  // Needed only length now.
        randomDoublesArrays[ i ] = randomDoublesGenerator.createNextArray( 10 );
    }
    
    cout << "Sequence of arrays filled with random int type numbers within defined range < 1; 100 >:\n";
    for ( unsigned i = 0; i < 4; ++i ) {
        PrintArray< int >( randomIntsArrays[ i ] , 10);
    }
    cout << endl;
    
    cout << "Sequence of arrays filled with random double type numbers within defined range ( 0; 1 ):\n";
    for ( unsigned i = 0; i < 4; ++i ) {
        PrintArray< double >( randomDoublesArrays[ i ] , 10);
    }
    cout << endl;
    
    for ( unsigned i = 0; i < 4; ++i ) {
        delete[] randomIntsArrays[ i ];
        delete[] randomDoublesArrays[ i ];
    }
    
    // Changing multiple numbers created before into random numbers within defined range.
    //------------------------------------------------------------------------------------------------------------------
    
    int intNumberA, intNumberB, intNumberC;
    
    randomIntsGenerator.makeNextRandom( intNumberA );
    randomIntsGenerator.makeNextRandom( intNumberB );
    randomIntsGenerator.makeNextRandom( intNumberC );
    
    cout << "Three int type numbers created before and changed into random numbers within defined range < 1; 100 >:"
         << endl << intNumberA << " " << intNumberB << " " << intNumberC << endl << endl;
         
    double doubleNumberA, doubleNumberB, doubleNumberC;
    
    randomDoublesGenerator.makeNextRandom( doubleNumberA );
    randomDoublesGenerator.makeNextRandom( doubleNumberB );
    randomDoublesGenerator.makeNextRandom( doubleNumberC );
    
    cout << "Three double type numbers created before and changed into random numbers within defined range ( 0; 1 ):"
         << endl << doubleNumberA << " " << doubleNumberB << " " << doubleNumberC << endl << endl;
    
    // Filling a sequence of arrays created before with random numbers within defined range.
    //------------------------------------------------------------------------------------------------------------------
    
    int intsArrays[ 4 ][ 10 ];
    double doublesArrays[ 4 ][ 10 ];
    
    for ( unsigned i = 0; i < 4; ++i ) {
        randomIntsGenerator.makeNextArrayRandom( intsArrays[ i ], 10 );
        randomDoublesGenerator.makeNextArrayRandom( doublesArrays[ i ], 10 );
    }
    
    cout << "Sequence of arrays created before and filled with random int type numbers "
         << "within defined range < 1; 100 >:\n";
    for ( unsigned i = 0; i < 4; ++i ) {
        PrintArray< int >( intsArrays[ i ], 10 );
    }
    cout << endl;
    
    cout << "Sequence of arrays created before and filled with random double type numbers "
         << "within defined range ( 0; 1 ):\n";
    for ( unsigned i = 0; i < 4; ++i ) {
        PrintArray< double >( doublesArrays[ i ], 10 );
    }
    
    return 0;
}
//**********************************************************************************************************************
