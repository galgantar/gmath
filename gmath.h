#pragma once

#include "Matrix.h"
#include "Matrix.hpp"

#include "Vector2.h"
#include "Vector3.h"
#include "Vector4.h"

#include "MatrixTransform.h"
#include "Projections.h"

namespace gm {

	using mat4 = Matrix<4, 4>;
	using mat3 = Matrix<3, 3>;
	using mat2 = Matrix<2, 2>;

	using vec2 = Vector2;
	using vec3 = Vector3;
	using vec4 = Vector4;
}