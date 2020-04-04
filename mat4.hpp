#include <iostream>
#include <array>
#include <initializer_list>


namespace gm {

	struct mat4
	{
		std::array<std::array<float, 4>, 4> arr;
		
		mat4()
			: arr()
		{
			for (int i = 0; i < 4; ++i)
				for (int j = 0; j < 4; ++j)
					arr[i][j] = 0;
		}

		mat4(float f)
			: arr()
		{			
			mat4();
			
			for (int i = 0; i < 4; ++i)
				arr[i][i] = f;
		}

		mat4(std::initializer_list<std::initializer_list<int>> l)
			: arr()
		{
			if (l.size() != 4)
				throw;
			
			for (int i = 0; i < 4; ++i) {
				if ((l.begin() + i)->size() != 4)
					throw;

				for (int j = 0; j < 4; ++j)
					arr[i][j] = *((l.begin() + i)->begin() + j);
			}
		}

		const std::array<float, 4>& operator[](const int index) const
		{
			return arr[index];
		}
		
		std::array<float, 4>& operator[](const int index)
		{
			return arr[index];
		}
	};

}



gm::mat4 operator+(const gm::mat4& m1, const gm::mat4& m2)
{
	gm::mat4 out;

	for (int i = 0; i < 4; ++i)
		for (int j = 0; j < 4; ++j) {
			out[i][j] = m1[i][j] + m2[i][j];
		}

	return out;
}

gm::mat4 operator-(const gm::mat4& m1, const gm::mat4& m2)
{
	gm::mat4 out;

	for (int i = 0; i < 4; ++i)
		for (int j = 0; j < 4; ++j)
			out[i][j] = m1[i][j] - m2[i][j];

	return out;
}

gm::mat4 operator*(const gm::mat4& m, const float f)
{
	gm::mat4 out;

	for (int i = 0; i < 4; ++i)
		for (int j = 0; j < 4; ++j)
			out[i][j] = m[i][j] * f;

	return out;
}

gm::mat4 operator*(const gm::mat4& m1, const gm::mat4& m2)
{
	gm::mat4 out;

	for (int i = 0; i < 4; ++i)
		for (int j = 0; j < 4; ++j)
			for (int k = 0; k < 4; ++k)
				out[i][j] += m1[i][k] * m2[k][j];

	return out;
}


std::ostream& operator<<(std::ostream& out, const gm::mat4& m)
{
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j)
			out << m[i][j] << " ";

		out << '\n';
	}
	return out;
}