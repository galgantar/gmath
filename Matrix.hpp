#pragma once

#ifndef MATRIX
#define MATRIX


namespace gm {

	template <int M, int N>
	class Matrix
	{
	protected:
		std::array<std::array<float, N>, M> arr;

	public:
		Matrix()
			: arr()
		{
			for (int i = 0; i < M; ++i)
				for (int j = 0; j < N; ++j)
					arr[i][j] = 0;
		}

		Matrix(float f)
			: arr()
		{
			if (M != N)
				throw;

			Matrix<M, N>();

			for (int i = 0; i < M; ++i)
				arr[i][i] = f;
		}

		Matrix(std::initializer_list<std::initializer_list<float>> init_list)
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

		inline std::array<float, N>& operator[](const int index) { return arr[index]; }
		inline const std::array<float, N>& operator[](const int index) const { return arr[index]; };
	};


	template <int M, int N>
	inline Matrix<M, N> operator+(const Matrix<M, N>& M1, Matrix<M, N>& M2)
	{
		Matrix<M, N> out;

		for (int i = 0; i < M; ++i)
			for (int j = 0; j < N; ++j) {
				out[i][j] = M1[i][j] + M2[i][j];
			}

		return out;
	}

	template <int M, int N>
	inline Matrix<M, N> operator-(const Matrix<M, N>& M1, const Matrix<M, N>& M2)
	{
		Matrix<M, N> out;

		for (int i = 0; i < M; ++i)
			for (int j = 0; j < N; ++j)
				out[i][j] = M1[i][j] - M2[i][j];

		return out;
	}

	template <int M, int N>
	inline Matrix<M, N> operator*(const float f, const Matrix<M, N>& mat)
	{
		Matrix<M, N> out;

		for (int i = 0; i < M; ++i)
			for (int j = 0; j < N; ++j)
				out[i][j] = mat[i][j] * f;

		return out;
	}

	template <int M, int N>
	inline Matrix<M, N> operator*(const Matrix<M, N>& mat, const float f)
	{
		return operator*(f, mat);
	}	

	template <int M, int N>
	inline Matrix<N, M> operator*(const Matrix<N, M>& M1, const Matrix<N, M>& M2)
	{
		{
			Matrix<M, N> out;

			for (int i = 0; i < M; ++i)
				for (int j = 0; j < N; ++j)
					for (int k = 0; k < M; ++k)
						out[i][j] += M1[i][k] * M2[k][j];

			return out;
		}
	}

	template <int M, int N>
	inline Matrix<N, M> transpose(const Matrix<M, N>& mat)
	{
		Matrix<N, M> transposed;
		
		for (int i = 0; i < N; ++i)
			for (int j = 0; j < M; ++j)
				transposed[i][j] = mat[j][i];

		return transposed;
	}

	template <int M, int N>
	inline std::ostream& operator<<(std::ostream& out, const Matrix<M, N>& mat)
	{
		for (int i = 0; i < M; ++i) {
			for (int j = 0; j < N; ++j)
				out << mat[i][j] << " ";

			out << '\n';
		}
		return out;
	}

	template <int M, int N>
	inline const float* value_ptr(const Matrix<M, N>& mat)
	{
		return &(mat[0][0]);
	}
}

#endif // MATRIX