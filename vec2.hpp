#include <cmath>

namespace gm {

	struct vec2
	{
		float x, y;
		vec2() : x(), y() {}
		vec2(const float x, const float y) : x(x), y(y) {}
		~vec2() {}
	};

	vec2 operator+(const vec2& v1, const vec2& v2)
	{
		return vec2(v1.x + v2.x, v1.y + v2.y);
	}

	vec2 operator-(const vec2& v1, const vec2& v2)
	{
		return vec2(v1.x - v2.x, v1.y - v2.y);
	}

	vec2 operator*(const vec2& v, const float f)
	{
		return vec2(v.x * f, v.y * f);
	}

	vec2 operator/(const vec2& v, const float f)
	{
		return vec2(v.x / f, v.y / f);
	}

	float dot(const vec2& v1, const vec2& v2) {
		return v1.x * v2.x + v1.y * v2.y;
	}

	float length(const vec2& v)
	{
		return sqrt(pow(v.x, 2) + pow(v.y, 2));
	}

	vec2 normalize(const vec2& v)
	{
		return v / length(v);
	}
}