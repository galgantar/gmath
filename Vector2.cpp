#include "Vector2.h"

#include <iostream>
#include <cmath>


namespace gm {

	Vector2::Vector2()
		: x(), y()
	{

	}

	Vector2::Vector2(const float x, const float y)
		: x(x), y(y)
	{

	}

	Vector2::~Vector2()
	{

	}



	Vector2 operator+(const Vector2& V1, const Vector2& V2)
	{
		return Vector2(V1.x + V2.x, V1.y + V2.y);
	}

	Vector2 operator-(const Vector2& V1, const Vector2& V2)
	{
		return Vector2(V1.x - V2.x, V1.y - V2.y);
	}

	Vector2 operator*(const Vector2& V, const float f)
	{
		return Vector2(V.x * f, V.y * f);
	}

	Vector2 operator/(const Vector2& V, const float f)
	{
		return Vector2(V.x / f, V.y / f);
	}

	Vector2 operator*(const float f, const Vector2& V)
	{
		return V * f;
	}

	Vector2 operator/(const float f, const Vector2& V)
	{
		return operator/(V, f);
	}

	float dot(const Vector2& V1, const Vector2& V2) {
		return V1.x * V2.x + V1.y * V2.y;
	}

	float length(const Vector2& V)
	{
		return sqrt(pow(V.x, 2) + pow(V.y, 2));
	}

	Vector2 normalize(const Vector2& V)
	{
		return V / gm::length(V);
	}

	std::ostream& operator<<(std::ostream& out, const Vector2& V)
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

	Vector2 operator*(const Matrix<2, 2>& M, const Vector2& V)
	{
		Vector2 out;

		for (int i = 0; i < 2; ++i)
			for (int j = 0; j < 2; ++j)
				out[j] += M[i][j] * V[j];

		return out;
	}
}