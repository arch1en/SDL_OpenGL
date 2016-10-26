
#include "Math.h"

#pragma region Vector2
template<class T>
an::Vector2<T>::Vector2(T X, T Y)
{
	x = X;
	y = Y;
}

template<class T>
an::Vector2<T>::Vector2(const Vector2<T>& Object)
{
	this->x = Object.x;
	this->y = Object.y;
}

template<class T>
an::Vector2<T> an::Vector2<T>::operator+(const Vector2<T>& RHS)
{
	Vector2<T> NewVector;

	NewVector.x = this->x + RHS.x;
	NewVector.y = this->y + RHS.y;
	
	return NewVector;
}

template<class T>
an::Vector2<T> an::Vector2<T>::operator-(const Vector2<T>& RHS)
{
	Vector2<T> NewVector;

	NewVector.x = this->x - RHS.x;
	NewVector.y = this->y - RHS.y;

	return NewVector;
}

template<class T>
an::Vector2<T> an::Vector2<T>::operator*(const Vector2<T>& RHS)
{
	Vector2<T> NewVector;

	NewVector.x = this->x * RHS.x;
	NewVector.y = this->y * RHS.y;

	return NewVector;
}

template<class T>
an::Vector2<T> an::Vector2<T>::operator/(const Vector2<T>& RHS)
{
	Vector2<T> NewVector;

	NewVector.x = this->x / RHS.x;
	NewVector.y = this->y / RHS.y;

	return NewVector;
}

template<class T>
an::Vector2<T>::~Vector2()
{

}
#pragma endregion
