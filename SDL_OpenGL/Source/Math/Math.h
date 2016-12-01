////////////////////////////////////////
//
//  @project    : Arch1eN Engine
//  @name       : Math
//  @author     : Artur Ostrowski
//  @usage      : Library with math functions. Currently not usable.
//  @version    : 1.0.0
//
////////////////////////////////////////
#pragma once

#include "../stdafx.h"

namespace an
{

#pragma region Vector2
	template<class T = float>
	struct Vector2
	{
	public:

		struct
		{
			T x;
			T y;
		};

		Vector2(T X, T Y);
		Vector2(const Vector2& Object);

		Vector2<T> operator+(const Vector2<T>& RHS);
		Vector2<T> operator-(const Vector2<T>& RHS);
		Vector2<T> operator*(const Vector2<T>& RHS);
		Vector2<T> operator/(const Vector2<T>& RHS);

	};
#pragma endregion

#pragma region Vector3
	template<class T = float>
	struct Vector3
	{
	public:
		struct 
		{
			T x;
			T y;
			T z;
		};

		Vector3() : x(0.f) , y(0.f), z(0.f) {}
		Vector3(T x, T y, T z);
		Vector3(const Vector3& InObject);

		Vector3<T> operator+(const Vector3<T>& RHS);
		Vector3<T> operator-(const Vector3<T>& RHS);
		Vector3<T> operator*(const Vector3<T>& RHS);
		Vector3<T> operator/(const Vector3<T>& RHS);
		
	};
#pragma endregion

	template<class T>
	bool IsPowerOfTwo(T InParam)
	{
		return (InParam & (InParam - 1) == 0);
	}

}

