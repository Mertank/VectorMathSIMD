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
Vector4::~Vector4() 
{}
/*
==========
operator<<

	Vector4 overload for writing to an output stream
==========
*/
std::ostream& operator<<( std::ostream& os, const Vector4& vec ) {
	os <<
		"{ " << vec.m_X <<
		", " << vec.m_Y <<
		", " << vec.m_Z <<
		", " << vec.m_W << 
		" }";

	return os;
}
}