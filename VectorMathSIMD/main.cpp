#include "SIMDCalculator.h"

int main( char** args, int argc ) {
	//Create calculator and run it
	math::SIMDCalculator* calculator = new math::SIMDCalculator();
	int returnCode = calculator->Run();
	delete calculator;

	return returnCode;
}