#include "SIMDCalculator.h"

#include <iostream>
#include <regex>

namespace math {
/*
==========
SIMDCalculator::SIMDCalculator

	SIMDCalculator default constructor
==========
*/
SIMDCalculator::SIMDCalculator( void ) :
	m_shouldExit( false )
{

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

	while ( !m_shouldExit ) {
		//Read the lhs vector in
		std::cout << "Enter a left hand side vector using ',' to seperate the numbers\n";
		ReadVectorString( inputString );

		if ( m_shouldExit ) { //Reading in the vector triggered the exit command
			break;
		}
	}

	return 0;
}
/*
==========
SIMDCalculator::ReadVectorString

	Reads a single valid vector string from the console
==========
*/
void SIMDCalculator::ReadVectorString( std::string& targetString ) {
	std::getline( std::cin, targetString );

	//Keep reading until a line is valid
	while ( !IsValidVector( targetString ) ) {
		if ( IsQuitCommand( targetString ) ) {
			m_shouldExit = true;
			return;
		}

		std::cout << "This string was in an invalid format. Please try again.\n";
		std::getline( std::cin, targetString );
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
/*
==========
SIMDCalculator::IsValidVector

	Returns true if the given string is in a valid format
==========
*/
bool SIMDCalculator::IsValidVector( const std::string& inputString ) {
	//Matches optional . and numbers repeated 4 times with commas seperating them
	return std::regex_match( inputString, std::regex( "^\\d+(\\.\\d+)?(\\,\\d+(\\.\\d+)?){3}$" ) );
}
}