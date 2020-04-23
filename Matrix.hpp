#include "Matrix.h"


#include <array>
#include <initializer_list>

#ifndef MATRIX_CLASS
#define MATRIX_CLASS

namespace gm {

	template <int M, int N>
	Matrix<M, N>::Matrix()
		: arr()
	{
		for (int i = 0; i < M; ++i)
			for (int j = 0; j < N; ++j)
				arr[i][j] = 0;
	}

	template <int M, int N>
	Matrix<M, N>::Matrix(float f)
		: arr()
	{
		if (M != N)
			throw;

		Matrix<M, N>();

		for (int i = 0; i < M; ++i)
			arr[i][i] = f;
	}

	template<int M, int N>
	Matrix<M, N>::Matrix(std::initializer_list<std::initializer_list<float>> init_list)
		: arr()
	{
		if (init_list.size() != M)
			throw;

		for (int i = 0; i < M; ++i) {
			if ((init_list.begin() + i)->size() != N)
				throw;

			for (int j = 0; j < N; ++j)
				arr[i][j] = *((init_list.begin() + i)->begin() + j);
		}
	}



	template <int M, int N>
	Matrix<M, N> operator+(const Matrix<M, N>& M1, Matrix<M, N>& M2)
	{
		Matrix<M, N> out;

		for (int i = 0; i < M; ++i)
			for (int j = 0; j < N; ++j) {
				out[i][j] = M1[i][j] + M2[i][j];
			}

		return out;
	}

	template <int M, int N>
	Matrix<M, N> operator-(const Matrix<M, N>& M1, const Matrix<M, N>& M2)
	{
		Matrix<M, N> out;

		for (int i = 0; i < M; ++i)
			for (int j = 0; j < N; ++j)
				out[i][j] = M1[i][j] - M2[i][j];

		return out;
	}

	template <int M, int N>
	Matrix<M, N> operator*(const float f, const Matrix<M, N>& mat)
	{
		Matrix<M, N> out;

		for (int i = 0; i < M; ++i)
			for (int j = 0; j < N; ++j)
				out[i][j] = mat[i][j] * f;

		return out;
	}

	template <int M, int N>
	Matrix<M, N> operator*(const Matrix<M, N>& mat, const float f)
	{
		return operator*(f, mat);
	}

	template <int M, int N>
	Matrix<M, N> operator*(const Matrix<M, N>& M1, const Matrix<M, N>& M2)
	{
		Matrix<M, N> out;

		for (int i = 0; i < M; ++i)
			for (int j = 0; j < N; ++j)
				for (int k = 0; k < M; ++k)
					out[i][j] += M1[i][k] * M2[k][j];

		return out;
	}

	template <int M, int N>
	std::ostream& operator<<(std::ostream& out, const Matrix<M, N>& mat)
	{
		for (int i = 0; i < M; ++i) {
			for (int j = 0; j < N; ++j)
				out << mat[i][j] << " ";

			out << '\n';
		}
		return out;
	}
}

#endif