#pragma once
template<typename T>
struct Vec4
{
	Vec4(const T _X = 0, const T _Y = 0, const T _Z = 0, const T _A = 0)
	{
		x = _X;
		y = _Y;
		z = _Z;
		a = _A;
	}
	T x, y, z, a;

	Vec4& operator+=(const Vec4& _Right)
	{
		x += _Right.x;
		y += _Right.y;
		z += _Right.z;
		a += _Right.a;
		return this;
	}
	Vec4& operator-=(const Vec4& _Right)
	{
		x -= _Right.x;
		y -= _Right.y;
		z -= _Right.z;
		a -= _Right.a;
		return this;
	}
	Vec4 operator+(const Vec4& _Right)
	{
		Vec4 temp;
		temp.x = this.x + _Right.x;
		temp.y = this.y + _Right.y;
		temp.z = this.z + _Right.z;
		temp.a = this.a + _Right.a;
		return temp;
	}
	Vec4 operator-(const Vec4& _Right)
	{
		Vec4 temp;
		temp.x = this.x - _Right.x;
		temp.y = this.y - _Right.y;
		temp.z = this.z - _Right.z;
		temp.a = this.a - _Right.a;
		return temp;
	}
};

typedef Vec4<float> Vec4f;
typedef Vec4<double> Vec4d;
typedef Vec4<int> Vec4i;

