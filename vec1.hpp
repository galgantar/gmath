namespace gm {

	struct vec1
	{
		float x;
		vec1() : x() {}
		vec1(const float x) : x(x) {}
		~vec1() {}
	};

	vec1 operator+(const vec1& v1, const vec1& v2)
	{
		return vec1(v1.x + v2.x);
	}

	vec1 operator-(const vec1& v1, const vec1& v2)
	{
		return vec1(v1.x - v2.x);
	}

	vec1 operator*(const vec1& v, const float f)
	{
		return vec1(v.x * f);
	}

	vec1 operator/(const vec1& v, const float f)
	{
		return vec1(v.x / f);
	}

	float dot(const vec1& v1, const vec1& v2) {
		return v1.x * v2.x;
	}

	float length(const vec1& v)
	{
		return v.x;
	}

	vec1 normalize(const vec1& v)
	{
		return v / length(v);
	}
}