#ifndef  __VECTOR4_H__
#define __VECTOR4_H__

#include <string>

namespace math {

class Vector4 {

public:
	Vector4( float x, float y, float z, float w );
	virtual ~Vector4( void );

private:
	float m_X;
	float m_Y;
	float m_Z;
	float m_W;

};

}

#endif // ! __VECTOR4_H__

