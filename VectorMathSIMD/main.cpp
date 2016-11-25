#include "SIMDCalculator.h"
#include <memory>

int main( char** args, int argc ) {
	//Create calculator and run it
	std::unique_ptr<math::SIMDCalculator> calculator = std::make_unique<math::SIMDCalculator>();
	
	int returnCode = calculator->Run();

	return returnCode;
}