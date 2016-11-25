#include "SIMDCalculator.h"

#include <iostream>
#include <regex>

#include "Vector4.h"

namespace math {
/*
==========
SIMDCalculator::SIMDCalculator

	SIMDCalculator default constructor
==========
*/
SIMDCalculator::SIMDCalculator( void ) :
	m_shouldExit( false )
{}
/*
==========
SIMDCalculator::~SIMDCalculator

	SIMDCalculator destructor
==========
*/
SIMDCalculator::~SIMDCalculator( void )
{}
/*
==========
SIMDCalculator::Run

	Takes in vectors from the command line until 'q' is found.
	Returns 0 for successful exit
==========
*/
int SIMDCalculator::Run( void ) {
	std::string		inputString; //Store the line from the console
	
	std::cout << "Welcome to the SIMD vector calculator!" << std::endl << "Input 'q' at anytime to quit." << std::endl;

	while ( !m_shouldExit ) {
		//Read the lhs vector in
		std::cout << "Enter a left hand side vector using ' ' to seperate the numbers" << std::endl;
		std::shared_ptr<Vector4> lhsVector = ReadVectorString( inputString );

		if ( m_shouldExit ) { //Reading in the vector triggered the exit command
			break;
		}
		//Output
		std::cout << std::endl << "Left hand side vector is: " << *lhsVector << std::endl << std::endl;

		//Read the rhs vector in
		std::cout << "Enter a right hand side vector using ' ' to seperate the numbers" << std::endl;
		std::shared_ptr<Vector4> rhsVector = ReadVectorString( inputString );

		if ( m_shouldExit ) { //Reading in the vector triggered the exit command
			break;
		}

		std::cout << std::endl << "Right hand side vector is: " << *rhsVector << std::endl << std::endl;

		while ( !m_shouldExit ) {
			std::cout << "Enter an operator ( +, -, *, / ) or 'r' to enter new vectors:" << std::endl;
			std::getline( std::cin, inputString );

			if ( inputString.length() == 1 ) { //Only valid commands are 1 character long
				switch ( inputString[ 0 ] ) {
					case 'q': //Quit
					{
						m_shouldExit = true;
						break;
					}
					case 'r': //Restart
					{
						break;
					}
					case '+':
					{
						std::cout << *lhsVector << " + " << *rhsVector << " = " << ( *lhsVector + *rhsVector ) << std::endl;
						break;
					}
					case '-':
					{
						std::cout << *lhsVector << " + " << *rhsVector << " = " << ( *lhsVector - *rhsVector ) << std::endl;
						break;
					}
					case '*':
					{
						std::cout << *lhsVector << " + " << *rhsVector << " = " << ( *lhsVector * *rhsVector ) << std::endl;
						break;
					}
					case '/':
					{
						std::cout << *lhsVector << " + " << *rhsVector << " = " << ( *lhsVector / *rhsVector ) << std::endl;
						break;
					}
				}
			}

			std::cout << std::endl;
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
std::shared_ptr<Vector4> SIMDCalculator::ReadVectorString( std::string& targetString ) {
	std::getline( std::cin, targetString );

	//Keep reading until a line is valid
	while ( !IsValidVector( targetString ) ) {
		if ( IsQuitCommand( targetString ) ) {
			m_shouldExit = true;
			return nullptr;
		}

		std::cout << "This string was in an invalid format. Please try again." << std::endl;
		std::getline( std::cin, targetString );
	}

	return CreateVectorFromString( targetString );
}
/*
==========
SIMDCalculator::CreateVectorFromString

	Converts a string into a vector4.
==========
*/
std::shared_ptr<Vector4> SIMDCalculator::CreateVectorFromString( const std::string& vectorString ) {
	float		vectorComponents[ 4 ]	= { 0.0f, 0.0f, 0.0f, 0.0f };
	float*		targetComponent			= vectorComponents;
	const char*	floatStart				= vectorString.c_str();
	char*		floatEnd				= nullptr;

	for ( int i = 0; i < 4; ++i ) {
		*targetComponent = std::strtof( floatStart, &floatEnd ); //Grab the next float
		++targetComponent; //Increase index

		floatStart = floatEnd + 1; //Add 1 to skip the ,
	}

	return std::make_shared<Vector4>( vectorComponents[ 0 ], vectorComponents[ 1 ], vectorComponents[ 2 ], vectorComponents[ 3 ] );
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
	return std::regex_match( inputString, std::regex( "^\\d+(\\.\\d+)?(\\ \\d+(\\.\\d+)?){3}$" ) );
}
}