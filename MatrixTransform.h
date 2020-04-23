#pragma once

#include "Matrix.h"

#include "Vector3.h"
#include "Vector4.h"

namespace gm {
	
	Matrix<4, 4> scale(Matrix<4, 4>& mat, const Vector3& vec);
	Matrix<4, 4> translate(Matrix<4, 4>& mat, const Vector3& trans_vec);
	Matrix<4, 4> rotate(Matrix<4, 4>& mat, const Vector3& R, const float r);

}