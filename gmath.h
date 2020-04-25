#pragma once

#ifndef _IOSTREAM_
#include <iostream>
#endif

#ifndef _ARRAY_
#include <array>
#endif

#include <initializer_list>
#include <cmath>


#include "Matrix.hpp"

#include "Vector2.hpp"
#include "Vector3.hpp"
#include "Vector4.hpp"

#include "MatrixTransform.hpp"
#include "Projections.hpp"

namespace gm {

	using mat4 = Matrix<4, 4>;
	using mat3 = Matrix<3, 3>;
	using mat2 = Matrix<2, 2>;

	using vec2 = Vector2;
	using vec3 = Vector3;
	using vec4 = Vector4;
}