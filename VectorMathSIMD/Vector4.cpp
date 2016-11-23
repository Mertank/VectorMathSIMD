#include "Vector4.h"

namespace math {
/*
==========
Vector4::Vector4

	Vector4 constructor taking in the float values for each part of the Vector4
==========
*/
Vector4::Vector4( float x, float y, float z, float w ) :
	m_X( x ), m_Y( y ), m_Z( z ), m_W( w ) {}
/*
==========
Vector4::~Vector4

	Vector4 destructor
==========
*/
Vector4::~Vector4() {

}
/*
==========
Vector4::CreateFromString

	Creates a Vector4 from a string.
	Returns nullptr if the string was in an invalid format
==========
*/
Vector4 Vector4::CreateFromString( const std::string& vectorString ) {
	
}
}