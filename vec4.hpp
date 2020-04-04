#include <cmath>

namespace gm {

	struct vec4
	{
		float x, y, z, w;
		vec4() : x(), y(), z(), w() {}
		vec4(const float x, const float y, const float z, const float w) : x(x), y(y), z(z), w(w) {}
		~vec4() {}
	};

	vec4 operator+(const vec4& v1, const vec4& v2)
	{
		return vec4(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z, v1.w + v2.w);
	}

	vec4 operator-(const vec4& v1, const vec4& v2)
	{
		return vec4(v1.x - v2.x, v1.y - v2.y, v1.z - v2.z, v1.w - v2.w);
	}

	vec4 operator*(const vec4& v, const float f)
	{
		return vec4(v.x * f, v.y * f, v.z * f, v.w * f);
	}

	vec4 operator/(const vec4& v, const float f)
	{
		return vec4(v.x / f, v.y / f, v.z / f, v.w / f);
	}

	float dot(const vec4& v1, const vec4& v2) {
		return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z + v1.w * v2.w;
	}

	float length(const vec4& v)
	{
		return sqrt(pow(v.x, 2) + pow(v.y, 2) + pow(v.z, 2) + pow(v.z, 2));
	}

	vec4 normalize(const vec4& v)
	{
		return v / length(v);
	}
}