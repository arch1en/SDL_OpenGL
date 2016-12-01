////////////////////////////////////////
//
//  @project    : Arch1eN Engine
//  @name       : Math
//  @author     : Artur Ostrowski
//  @usage      : Library with math functions. Currently not usable.
//  @version    : 1.0.0
//
////////////////////////////////////////
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
an::Vector3<T>::Vector3(T x, T y, T z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

template<class T>
an::Vector3<T>::Vector3(const an::Vector3<T>& InObject)
{
	x = InObject.x;
	y = InObject.y;
	z = InObject.z;
}

template<class T>
an::Vector3<T> an::Vector3<T>::operator+(const an::Vector3<T>& RHS)
{
	Vector3<T> NewVector;

	NewVector.x = this.x + RHS.x;
	NewVector.y = this.y + RHS.y;
	NewVector.z = this.z + RHS.z;

	return NewVector;
}

template<class T>
an::Vector3<T> an::Vector3<T>::operator-(const an::Vector3<T>& RHS)
{
	Vector3<T> NewVector;

	NewVector.x = this.x - RHS.x;
	NewVector.y = this.y - RHS.y;
	NewVector.z = this.z - RHS.z;

	return NewVector;
}

template<class T>
an::Vector3<T> an::Vector3<T>::operator*(const an::Vector3<T>& RHS)
{
	Vector3<T> NewVector;

	NewVector.x = this.x * RHS.x;
	NewVector.y = this.y * RHS.y;
	NewVector.z = this.z * RHS.z;

	return NewVector;
}

template<class T>
an::Vector3<T> an::Vector3<T>::operator/(const an::Vector3<T>& RHS)
{
	Vector3<T> NewVector;

	NewVector.x = this.x / RHS.x;
	NewVector.y = this.y / RHS.y;
	NewVector.z = this.z / RHS.z;

	return NewVector;
}

#pragma endregion
