#ifndef  __SIMDCALCULATOR_H__
#define __SIMDCALCULATOR_H__

#include <string>
#include <memory>

namespace math {

class Vector4;

class SIMDCalculator {

public:
	SIMDCalculator( void );
	~SIMDCalculator( void );

	int Run( void );

private:
	bool IsQuitCommand( const std::string& inputString );
	bool IsValidVector( const std::string& inputString );

	std::shared_ptr<Vector4> ReadVectorString( std::string& targetString );
	std::shared_ptr<Vector4> CreateVectorFromString( const std::string& vectorString );

	bool m_shouldExit;
};

}

#endif // ! __SIMDCALCULATOR_H__

