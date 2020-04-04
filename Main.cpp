#include <iostream>
#include <array>

#include "vec1.hpp"
#include "vec2.hpp"
#include "vec3.hpp"
#include "vec4.hpp"

#include "mat4.hpp"


int main()
{
	gm::mat4 mat = { {1,2,3,4}, {1,2,3,4}, {1,2,3,4}, {1,2,3,4} };
	gm::mat4 mat2 = { {1,2,3,4}, {1,2,3,4}, {1,2,3,4}, {1,2,3,4} };
	std::cout << mat * mat2 << std::endl;

	return 0;
}