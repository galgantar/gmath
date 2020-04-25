#pragma once

#include "Matrix.h"
#include "Vector3.h"

namespace gm {

	float radians(float degrees);
	
	Matrix<4, 4> orthographic(float right, float top, float near, float far);
	Matrix<4, 4> perspective(float fov, float ratio, float near, float far);

	Matrix<4, 4> lookAt(const Vector3& pos, const Vector3& front, const Vector3& up);

}