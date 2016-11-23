#ifndef  __SIMDCALCULATOR_H__
#define __SIMDCALCULATOR_H__

#include <string>

namespace math {

class SIMDCalculator {

public:
	SIMDCalculator( void );
	~SIMDCalculator( void );

	int Run( void );

private:
	bool IsQuitCommand( const std::string& inputString );
};

}

#endif // ! __SIMDCALCULATOR_H__

