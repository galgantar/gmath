#pragma once

#ifndef MATRIX
#include "Matrix.hpp"
#endif

#ifndef VECTOR3
#include "Vector3.hpp"
#endif


namespace gm {

	inline Matrix<4, 4> scale(const Matrix<4, 4>& mat, const Vector3& vec)
	{
		Matrix<4, 4> scale_mat(1.f);
		for (int i = 0; i < 3; ++i)
			scale_mat[i][i] = vec[i];

		return mat * scale_mat;

	}

	inline Matrix<4, 4> translate(const Matrix<4, 4>& mat, const Vector3& trans_vec)
	{
		Matrix<4, 4> trans_mat(1.f);
		for (int i = 0; i < 3; ++i)
			trans_mat[i][3] = trans_vec[i];

		return mat * trans_mat;
	}

	inline Matrix<4, 4> rotate(const Matrix<4, 4>& mat, const Vector3& vec, const float angle)
	{
		Vector3 R = normalize(vec);
		
		Matrix<4, 4> rot_mat;
		float c = cos(angle);
		float s = sin(angle);
		
		rot_mat =
		{
			{ c + pow(R.x, 2) * (1 - c), R.x * R.y * (1 - c) - R.z * s, R.x * R.z * (1 - c) + R.y * s, 0 },
			{ R.y * R.x * (1 - c) + R.z * s, c + pow(R.y, 2) * (1 - c), R.y * R.z * (1 - c) - R.x * s, 0 },
			{ R.z * R.x * (1 - c) - R.y * s, R.z * R.y * (1 - c) + R.x * s, c + pow(R.z, 2) * (1 - c), 0 },
			{ 0, 0, 0, 1 }
		};

		return mat * rot_mat;
	}
}