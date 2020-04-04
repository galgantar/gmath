#include <cmath>

namespace gm {

	struct vec3
	{
		float x, y, z;
		vec3() : x(), y(), z() {}
		vec3(const float x, const float y, const float z) : x(x), y(y), z(z) {}
		~vec3() {}
	};

	vec3 operator+(const vec3& v1, const vec3& v2)
	{
		return vec3(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z);
	}

	vec3 operator-(const vec3& v1, const vec3& v2)
	{
		return vec3(v1.x - v2.x, v1.y - v2.y, v1.z - v2.z);
	}

	vec3 operator*(const vec3& v, const float f)
	{
		return vec3(v.x * f, v.y * f, v.z * f);
	}

	vec3 operator/(const vec3& v, const float f)
	{
		return vec3(v.x / f, v.y / f, v.z / f);
	}

	float dot(const vec3& v1, const vec3& v2)
	{
		return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
	}

	vec3 cross(const vec3& v1, const vec3& v2)
	{
		vec3 out;
		out.x = v1.y * v1.z - v1.z * v2.y;
		out.y = v1.z * v2.x - v1.x * v2.z;
		out.z = v1.x * v2.y - v1.y * v2.x;
		
		return out;
	}

	float length(const vec3& v)
	{
		return sqrt(pow(v.x, 2) + pow(v.y, 2) + pow(v.z, 2));
	}

	vec3 normalize(const vec3& v)
	{
		return v / length(v);
	}
}