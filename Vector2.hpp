#pragma once

#ifndef VECTOR2
#define VECTOR2


#ifndef MATRIX
#include "Matrix.hpp"
#endif


namespace gm {

	struct Vector2
	{
		union
		{
			struct { float x, y; };
		};


		Vector2()
			: x(), y()
		{

		}

		Vector2(const float f)
			: x(f), y(f)
		{

		}

		Vector2(const float x, const float y)
			: x(x), y(y)
		{

		}

		inline float& operator[](const int index) { return *(&x + index); }
		inline const float& operator[](const int index) const { return *(&x + index); }
	};


	inline bool operator==(const Vector2& V1, const Vector2& V2)
	{
		return V1.x == V2.x && V1.y == V2.y;
	}

	inline bool operator!=(const Vector2& V1, const Vector2& V2)
	{
		return !operator==(V1, V2);
	}

	inline Vector2 operator-(const Vector2& V)
	{
		return Vector2(-V.x, -V.y);
	}

	inline void operator+=(Vector2& V1, const Vector2& V2)
	{
		for (int i = 0; i < 2; ++i)
			V1[i] += V2[i];
	}

	inline void operator-=(Vector2& V1, const Vector2& V2)
	{
		operator+=(V1, -V2);
	}

	inline Vector2 operator+(const Vector2& V1, const Vector2& V2)
	{
		return Vector2(V1.x + V2.x, V1.y + V2.y);
	}

	inline Vector2 operator-(const Vector2& V1, const Vector2& V2)
	{
		return Vector2(V1.x - V2.x, V1.y - V2.y);
	}

	inline Vector2 operator*(const Vector2& V1, const Vector2& V2)
	{
		return Vector2(V1.x * V2.x, V1.y * V2.y);
	}

	inline Vector2 operator*(const Vector2& V, const float f)
	{
		return Vector2(V.x * f, V.y * f);
	}

	inline Vector2 operator*(const float f, const Vector2& V)
	{
		return operator*(V, f);
	}

	inline Vector2 operator/(const Vector2& V, const float f)
	{
		return Vector2(V.x / f, V.y / f);
	}

	inline Vector2 operator/(const float f, const Vector2& V)
	{
		return operator/(V, f);
	}

	inline float dot(const Vector2& V1, const Vector2& V2) {
		return V1.x * V2.x + V1.y * V2.y;
	}

	inline float length(const Vector2& V)
	{
		return sqrt(pow(V.x, 2) + pow(V.y, 2));
	}

	inline Vector2 normalize(const Vector2& V)
	{
		return V / gm::length(V);
	}

	inline Vector2 operator*(const Matrix<2, 2>& M, const Vector2& V)
	{
		Vector2 out;

		for (int i = 0; i < 2; ++i)
			for (int j = 0; j < 2; ++j)
				out[j] += M[i][j] * V[j];

		return out;
	}

	inline std::ostream& operator<<(std::ostream& out, const Vector2& V)
	{
		out << "( ";
		for (int i = 0; i < 2; ++i) {
			out << V[i];
			if (i != 1)
				out << ", ";
		}
		out << " )";

		return out;
	}
}

#endif // VECTOR2