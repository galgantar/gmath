#pragma once

#include "MatrixTransform.h"
#include "Matrix.hpp"

namespace gm {

	Matrix<4, 4> scale(Matrix<4, 4>& mat, const Vector3& vec)
	{
		Matrix<4, 4> scale_mat(1.f);
		for (int i = 0; i < 3; ++i)
			scale_mat[i][i] = vec[i];

		return mat * scale_mat;

	}

	Matrix<4, 4> translate(Matrix<4, 4>& mat, const Vector3& trans_vec)
	{
		Matrix<4, 4> trans_mat(1.f);
		for (int i = 0; i < 3; ++i)
			trans_mat[i][3] = trans_vec[i];

		return mat * trans_mat;
	}

	Matrix<4, 4> rotate(Matrix<4, 4>& mat, const Vector3& R, const float r)
	{
		Matrix<4, 4> rot_mat;
		rot_mat =
		{
			{ cos(r) + pow(R.x, 2) * (1 - cos(r)), R.x * R.y * (1 - cos(r)) - R.z * sin(r), R.x * R.z * (1 - cos(r)) + R.y * sin(r), 0 },
			{ R.y * R.x * (1 - cos(r)) + R.z * sin(r), cos(r) + pow(R.y, 2) * (1 - cos(r)), R.y * R.z * (1 - cos(r)) - R.x * sin(r), 0 },
			{ R.z * R.x * (1 - cos(r)) - R.y * sin(r), R.z * R.y * (1 - cos(r)) + R.x * sin(r), cos(r) + pow(R.z, 2) * (1 - cos(r)), 0 },
			{ 0, 0, 0, 1 }
		};

		return mat * rot_mat;
	}

}