#pragma once

#ifndef MATRIX
#include "Matrix.hpp"
#endif


namespace gm {

	inline float radians(float degrees)
	{
		return degrees * 0.01745329251994329576923690768489f;
	}

	inline Matrix<4, 4> ortho(float right, float top, float near, float far)
	{
		Matrix<4, 4> mat;

		mat[0][0] = 1.f / right;
		mat[1][1] = 1.f / top;
		mat[2][2] = -2 / (far - near);
		mat[2][3] = (far + near) / (near - far);
		mat[3][3] = 1;

		return mat;
	}
	
	inline Matrix<4, 4> perspective(float fov, float ratio, float near, float far)
	{
		float right = tan(fov / 2.f) * near;
		float top = right / ratio;

		Matrix<4, 4> mat;
		mat[0][0] = near / right;
		mat[1][1] = near / top;
		mat[2][2] = -(far + near) / (far - near);
		mat[2][3] = -(2 * far * near) / (far - near);
		mat[3][2] = -1;

		return mat;
	}


	inline Matrix<4, 4> lookAt(const Vector3& eye, const Vector3& target, const Vector3& worldUp)
	{
		Vector3 camera_front = normalize(eye - target);
		Vector3 camera_right = normalize(cross(normalize(worldUp), camera_front));
		Vector3 camera_up = cross(camera_front, camera_right);

		Matrix<4, 4> camera_translation(1.f);
		camera_translation[0][3] = -eye.x;
		camera_translation[1][3] = -eye.y;
		camera_translation[2][3] = -eye.z;

		Matrix<4, 4> camera_rotation(1.f);
		for (int i = 0; i < 3; ++i)
			camera_rotation[i][0] = camera_right[i];
		for (int i = 0; i < 3; ++i)
			camera_rotation[i][1] = camera_up[i];
		for (int i = 0; i < 3; ++i)
			camera_rotation[i][2] = camera_front[i];

		return transpose(camera_rotation) * camera_translation;
	}
}