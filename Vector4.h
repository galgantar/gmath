#pragma once

#include "Matrix.h"

#include <iostream>


namespace gm {

	struct Vector4
	{
		union
		{
			struct { float x, y, z, w; };
			struct { float r, g, b, a; };
		};
		
		
		Vector4();
		Vector4(const float x, const float y, const float z, const float w);
		~Vector4();

		inline float& operator[](const int index) { return *(&x + index); }
		inline const float& operator[](const int index) const { return *(&x + index); }
	};

	Vector4 operator*(const Vector4& V, const float f);
	Vector4 operator*(const float f, const Vector4& V);
	Vector4 operator/(const Vector4& V, const float f);
	Vector4 operator/(const float f, const Vector4& V);

	Vector4 operator+(const Vector4& V1, const Vector4& V2);
	Vector4 operator-(const Vector4& V1, const Vector4& V2);

	float dot(const Vector4& V1, const Vector4& V2);
	float length(const Vector4& V);
	Vector4 normalize(const Vector4& V);

	std::ostream& operator<<(std::ostream& out, const Vector4& V);

	Vector4 operator*(const Matrix<4, 4>& M, const Vector4& V);
}