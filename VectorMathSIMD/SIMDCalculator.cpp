#include "SIMDCalculator.h"

#include <iostream>

namespace math {
/*
==========
SIMDCalculator::SIMDCalculator

	SIMDCalculator default constructor
==========
*/
SIMDCalculator::SIMDCalculator( void ) {

}
/*
==========
SIMDCalculator::~SIMDCalculator

	SIMDCalculator destructor
==========
*/
SIMDCalculator::~SIMDCalculator( void ) {

}
/*
==========
SIMDCalculator::Run

	Takes in vectors from the command line until 'q' is found.
	Returns 0 for successful exit
==========
*/
int SIMDCalculator::Run( void ) {
	std::string inputString; //Store the line from the console

	std::cout << "Welcome to the SIMD vector calculator!\nInput 'q' at anytime to quit.\n";

	while ( true ) {
		std::cout << "Enter a vector seperating the components with ','\n";
		std::getline( std::cin, inputString );

		//Check for quit command
		if ( IsQuitCommand( inputString ) ) {
			return 0;
		}
	}
}
/*
==========
SIMDCalculator::IsQuitCommand

	Returns true if the given string should exit the program
==========
*/
bool SIMDCalculator::IsQuitCommand( const std::string& inputString ) {
	return inputString.length() == 1 && inputString[ 0 ] == 'q';
}
}