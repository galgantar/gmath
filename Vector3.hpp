#pragma once

#ifndef VECTOR3
#define VECTOR3


#ifndef MATRIX
#include "Matrix.hpp"
#endif


namespace gm {

	struct Vector3
	{
		union
		{
			struct { float x, y, z; };
			struct { float r, g, b; };
		};


		Vector3()
			: x(), y(), z()
		{

		}
		
		Vector3(const float x, const float y, const float z)
			: x(x), y(y), z(z)
		{

		}

		inline float& operator[](const int index) { return *(&x + index); }
		inline const float& operator[](const int index) const { return *(&x + index); }
	};


	inline bool operator==(const Vector3& V1, const Vector3& V2)
	{
		return V1.x == V2.x && V1.y == V2.y && V1.z == V2.z;
	}

	inline bool operator!=(const Vector3& V1, const Vector3& V2)
	{
		return !operator==(V1, V2);
	}

	inline Vector3 operator-(const Vector3& V)
	{
		return Vector3(-V.x, -V.y, -V.z);
	}

	inline void operator+=(Vector3& V1, const Vector3& V2)
	{
		for (int i = 0; i < 3; ++i)
			V1[i] += V2[i];
	}

	inline void operator-=(Vector3& V1, const Vector3& V2)
	{
		operator+=(V1, -V2);
	}

	inline Vector3 operator+(const Vector3& V1, const Vector3& V2)
	{
		return Vector3(V1.x + V2.x, V1.y + V2.y, V1.z + V2.z);
	}

	inline Vector3 operator-(const Vector3& V1, const Vector3& V2)
	{
		return Vector3(V1.x - V2.x, V1.y - V2.y, V1.z - V2.z);
	}

	inline Vector3 operator*(const Vector3& V, const float f)
	{
		return Vector3(V.x * f, V.y * f, V.z * f);
	}

	inline Vector3 operator*(const float f, const Vector3& V)
	{
		return operator*(V, f);
	}

	inline Vector3 operator/(const Vector3& V, const float f)
	{
		return Vector3(V.x / f, V.y / f, V.z / f);
	}

	inline Vector3 operator/(const float f, const Vector3& V)
	{
		return operator/(V, f);
	}

	inline float dot(const Vector3& V1, const Vector3& V2) {
		return V1.x * V2.x + V1.y * V2.y + V1.z * V2.z;
	}

	inline Vector3 cross(const Vector3& v1, const Vector3& v2)
	{
		Vector3 out;
		out.x = v1.y * v2.z - v1.z * v2.y;
		out.y = v1.z * v2.x - v1.x * v2.z;
		out.z = v1.x * v2.y - v1.y * v2.x;

		return out;
	}

	inline float length(const Vector3& V)
	{
		return sqrt(pow(V.x, 2) + pow(V.y, 2) + pow(V.z, 2));
	}

	inline Vector3 normalize(const Vector3& V)
	{
		return V / gm::length(V);
	}

	inline Vector3 operator*(const Matrix<3, 3>& M, const Vector3& V)
	{
		Vector3 out;

		for (int i = 0; i < 3; ++i)
			for (int j = 0; j < 3; ++j)
				out[j] += M[i][j] * V[j];

		return out;
	}

	inline std::ostream& operator<<(std::ostream& out, const Vector3& V)
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
}

#endif // VECTOR3