////////////////////////
//
//
//
//	TODO : TEST.
////////////////////////

#pragma once

#include "../stdafx.h"

namespace an
{

#pragma region Vector2
	template<class T>
	class Vector2
	{
	public:

		Vector2(T X, T Y);
		Vector2(const Vector2& Object);

		Vector2<T> operator+(const Vector2<T>& RHS);
		Vector2<T> operator-(const Vector2<T>& RHS);
		Vector2<T> operator*(const Vector2<T>& RHS);
		Vector2<T> operator/(const Vector2<T>& RHS);

	protected:

		T x;
		T y;

		~Vector2();

	};
#pragma endregion

	template<class T>
	bool IsPowerOfTwo(T InParam)
	{
		return (InParam & (InParam - 1) == 0);
	}

}

