#include <iostream>
#include <string>

#include "SIMDCalculator.h"

bool shouldExit( const std::string& inputStr );

int main( char** args, int argc ) {

	math::SIMDCalculator* calculator = new

	return 0;
}

/*
=========
shouldExit

	Returns if the program should exit
=========
*/
bool shouldExit( const std::string& inputStr ) {
	return inputStr.length() == 1 && inputStr[ 0 ] == 'q';
}