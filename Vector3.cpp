#include "Vector3.h"

#include <iostream>
#include <cmath>


namespace gm {

	Vector3::Vector3()
		: x(), y(), z()
	{

	}

	Vector3::Vector3(const float x, const float y, const float z)
		: x(x), y(y), z(z)
	{

	}

	Vector3::~Vector3()
	{

	}



	Vector3 operator+(const Vector3& V1, const Vector3& V2)
	{
		return Vector3(V1.x + V2.x, V1.y + V2.y, V1.z + V2.z);
	}

	Vector3 operator-(const Vector3& V1, const Vector3& V2)
	{
		return Vector3(V1.x - V2.x, V1.y - V2.y, V1.z - V2.z);
	}

	Vector3 operator*(const Vector3& V, const float f)
	{
		return Vector3(V.x * f, V.y * f, V.z * f);
	}

	Vector3 operator/(const Vector3& V, const float f)
	{
		return Vector3(V.x / f, V.y / f, V.z / f);
	}

	Vector3 operator*(const float f, const Vector3& V)
	{
		return V * f;
	}

	Vector3 operator/(const float f, const Vector3& V)
	{
		return operator/(V, f);
	}

	float dot(const Vector3& V1, const Vector3& V2) {
		return V1.x * V2.x + V1.y * V2.y + V1.z * V2.z;
	}

	Vector3 cross(const Vector3& v1, const Vector3& v2)
	{
		Vector3 out;
		out.x = v1.y * v2.z - v1.z * v2.y;
		out.y = v1.z * v2.x - v1.x * v2.z;
		out.z = v1.x * v2.y - v1.y * v2.x;

		return out;
	}

	float length(const Vector3& V)
	{
		return sqrt(pow(V.x, 2) + pow(V.y, 2) + pow(V.z, 2));
	}

	Vector3 normalize(const Vector3& V)
	{
		return V / gm::length(V);
	}

	std::ostream& operator<<(std::ostream& out, const Vector3& V)
	{
		out << "( ";
		for (int i = 0; i < 3; ++i) {
			out << V[i];
			if (i != 2)
				out << ", ";
		}
		out << " )";

		return out;
	}

	Vector3 operator*(const Matrix<3, 3>& M, const Vector3& V)
	{
		Vector3 out;

		for (int i = 0; i < 3; ++i)
			for (int j = 0; j < 3; ++j)
				out[j] += M[i][j] * V[j];

		return out;
	}
}