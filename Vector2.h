#pragma once

#include "Matrix.h"

#include <iostream>


namespace gm {

	struct Vector2
	{
		union
		{
			struct { float x, y; };
		};


		Vector2();
		Vector2(const float x, const float y);
		~Vector2();

		inline float& operator[](const int index) { return *(&x + index); }
		inline const float& operator[](const int index) const { return *(&x + index); }
	};

	Vector2 operator*(const Vector2& V, const float f);
	Vector2 operator*(const float f, const Vector2& V);
	Vector2 operator/(const Vector2& V, const float f);
	Vector2 operator/(const float f, const Vector2& V);

	Vector2 operator+(const Vector2& V1, const Vector2& V2);
	Vector2 operator-(const Vector2& V1, const Vector2& V2);

	float dot(const Vector2& V1, const Vector2& V2);
	float length(const Vector2& V);
	Vector2 normalize(const Vector2& V);

	std::ostream& operator<<(std::ostream& out, const Vector2& V);

	Vector2 operator*(const Matrix<2, 2>& M, const Vector2& V);
}