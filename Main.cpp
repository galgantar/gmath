#include <iostream>

#include "gmath.h"

int main()
{
	gm::mat4 m(3.f);
	gm::vec4 v1(1.f, 2.f, -3.f, 9.f);
	gm::vec4 v2(1.f, 2.f, -3.f, 9.f);

	std::cout << m * v1 << std::endl;
	std::cout << v1 + v2 << std::endl;
	gm::normalize(v1);

	return 0;
}