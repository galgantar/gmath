#pragma once

#include <array>
#include <initializer_list>

namespace gm {

	template <int M, int N>
	class Matrix
	{
	protected:
		std::array<std::array<float, M>, N> arr;
	
	public:
		Matrix();
		Matrix(float f);
		Matrix(std::initializer_list<std::initializer_list<float>> l);

		inline std::array<float, N>& operator[](const int index) { return arr[index]; }
		inline const std::array<float, N>& operator[](const int index) const { return arr[index]; };
	};

}