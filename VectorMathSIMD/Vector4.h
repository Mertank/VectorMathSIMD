#ifndef  __VECTOR4_H__
#define __VECTOR4_H__

#include <string>
#include <iostream>

namespace math {

class Vector4 {

public:
							Vector4( float x, float y, float z, float w );
	virtual					~Vector4( void );

	friend std::ostream&	operator<<( std::ostream& os, const Vector4& vec );

	inline friend Vector4 operator+( Vector4 lhs, const Vector4& rhs ) {
		__m128 lh		= _mm_loadu_ps( &lhs.m_X );
		__m128 rh		= _mm_loadu_ps( &rhs.m_X );

		__m128 result	= _mm_add_ps( lh, rh );

		_mm_storeu_ps( &lhs.m_X, result );
		
		return lhs;
	}

	inline friend Vector4 operator-( Vector4 lhs, const Vector4& rhs ) {
		__m128 lh		= _mm_loadu_ps( &lhs.m_X );
		__m128 rh		= _mm_loadu_ps( &rhs.m_X );

		__m128 result	= _mm_sub_ps( lh, rh );

		_mm_storeu_ps( &lhs.m_X, result );
		
		return lhs;
	}

	inline friend Vector4 operator*( Vector4 lhs, const Vector4& rhs ) {
		__m128 lh		= _mm_loadu_ps( &lhs.m_X );
		__m128 rh		= _mm_loadu_ps( &rhs.m_X );

		__m128 result	= _mm_mul_ps( lh, rh );

		_mm_storeu_ps( &lhs.m_X, result );
		
		return lhs;
	}

	inline friend Vector4 operator/( Vector4 lhs, const Vector4& rhs ) {
		__m128 lh		= _mm_loadu_ps( &lhs.m_X );
		__m128 rh		= _mm_loadu_ps( &rhs.m_X );

		__m128 result	= _mm_div_ps( lh, rh );

		_mm_storeu_ps( &lhs.m_X, result );
		
		return lhs;
	}
private:
	float m_X;
	float m_Y;
	float m_Z;
	float m_W;
};

}

#endif // ! __VECTOR4_H__

