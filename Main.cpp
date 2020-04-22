#include <iostream>

#include "gmath.h"

int main()
{
	gm::mat4 m(1.f);
	
	m = gm::rotate(m, gm::vec3(0.f, 0.f, 1.f), 3.14159265 / 2.0);

	
	gm::vec4 vec(1.f, 0.f, 0.f, 1.f);

	std::cout << m * vec << std::endl;
	
	return 0;
}