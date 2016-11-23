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
	bool IsValidVector( const std::string& inputString );

	void ReadVectorString( std::string& targetString );

	bool m_shouldExit;
};

}

#endif // ! __SIMDCALCULATOR_H__

