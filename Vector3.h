#pragma once

#include "Matrix.h"

#include <iostream>


namespace gm {

	struct Vector3
	{
		union
		{
			struct { float x, y, z; };
			struct { float r, g, b; };
		};


		Vector3();
		Vector3(const float x, const float y, const float z);
		~Vector3();

		inline float& operator[](const int index) { return *(&x + index); }
		inline const float& operator[](const int index) const { return *(&x + index); }
	};

	Vector3 operator*(const Vector3& V, const float f);
	Vector3 operator*(const float f, const Vector3& V);
	Vector3 operator/(const Vector3& V, const float f);
	Vector3 operator/(const float f, const Vector3& V);

	Vector3 operator+(const Vector3& V1, const Vector3& V2);
	Vector3 operator-(const Vector3& V1, const Vector3& V2);

	float length(const Vector3& V);
	float dot(const Vector3& V1, const Vector3& V2);
	Vector3 cross(const Vector3& V1, const Vector3& V2);
	Vector3 normalize(const Vector3& V);

	std::ostream& operator<<(std::ostream& out, const Vector3& V);

	Vector3 operator*(const Matrix<3, 3>& M, const Vector3& V);
}