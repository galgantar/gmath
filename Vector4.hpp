#pragma once

#ifndef VECTOR4
#define VECTOR4


#ifndef MATRIX
#include "Matrix.hpp"
#endif


namespace gm {

	struct Vector4
	{
		union
		{
			struct { float x, y, z, w; };
			struct { float r, g, b, a; };
		};
		
		Vector4()
			: x(), y(), z(), w()
		{

		}

		Vector4(const float x, const float y, const float z, const float w)
			: x(x), y(y), z(z), w(w)
		{

		}

		inline float& operator[](const int index) { return *(&x + index); }
		inline const float& operator[](const int index) const { return *(&x + index); }
	};


	bool operator==(const Vector4& V1, const Vector4& V2)
	{
		return V1.x == V2.x && V1.y == V2.y && V1.z == V2.z && V1.w == V2.w;
	}

	bool operator!=(const Vector4& V1, const Vector4& V2)
	{
		return !operator==(V1, V2);
	}

	Vector4 operator+(const Vector4& V1, const Vector4& V2)
	{
		return Vector4(V1.x + V2.x, V1.y + V2.y, V1.z + V2.z, V1.w + V2.w);
	}

	Vector4 operator-(const Vector4& V1, const Vector4& V2)
	{
		return Vector4(V1.x - V2.x, V1.y - V2.y, V1.z - V2.z, V1.w - V2.w);
	}

	Vector4 operator*(const Vector4& V, const float f)
	{
		return Vector4(V.x * f, V.y * f, V.z * f, V.w * f);
	}

	Vector4 operator*(const float f, const Vector4& V)
	{
		return operator*(V, f);
	}

	Vector4 operator/(const Vector4& V, const float f)
	{
		return Vector4(V.x / f, V.y / f, V.z / f, V.w / f);
	}

	Vector4 operator/(const float f, const Vector4& V)
	{
		return operator/(V, f);
	}

	float dot(const Vector4& V1, const Vector4& V2)
	{
		return V1.x * V2.x + V1.y * V2.y + V1.z * V2.z + V1.w * V2.w;
	}

	float length(const Vector4& V)
	{
		return sqrt(pow(V.x, 2) + pow(V.y, 2) + pow(V.z, 2) + pow(V.w, 2));
	}

	Vector4 normalize(const Vector4& V)
	{
		return V / gm::length(V);
	}

	Vector4 operator*(const Matrix<4, 4>& M, const Vector4& V)
	{
		Vector4 out;

		for (int i = 0; i < 4; ++i)
			for (int j = 0; j < 4; ++j)
				out[i] += M[i][j] * V[j];

		return out;
	}

	std::ostream& operator<<(std::ostream& out, const Vector4& V)
	{
		out << "( ";
		for (int i = 0; i < 4; ++i) {
			out << V[i];
			if (i != 3)
				out << ", ";
		}
		out << " )";

		return out;
	}
}

#endif // VECTOR4