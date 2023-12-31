/******************************************************************************/
/*!
\file		Vector2D.cpp
\author 	Shaikh Faid Bin Omar, shaikhfaid.binomar, 390003019
\par    	email: shaikhfaid.binomar@digipen.edu
\date   	July 26, 2020
\brief

Copyright (C) 2020 DigiPen Institute of Technology.
Reproduction or disclosure of this file or its contents without the prior
written consent of DigiPen Institute of Technology is prohibited.
 */
 /******************************************************************************/

#include "Vector2D.h"
#include <cmath>

using namespace CS230;

/* creating the conversion constructor, assigning input to x, and y accordingly */
Vector2D::Vector2D(float _x, float _y) : x(_x), y(_y) {}

/* creating the unary - operator */
Vector2D CS230::Vector2D::operator-() const
{
	/* declare a new 2d vector */
	Vector2D newVec2D = { 0.0f, 0.0f };
	/* assigning new vector 2d to be returned with a negavtive multiplication */
	newVec2D.x = this->x * (-1);
	newVec2D.y = this->y * (-1);

	/* return new negated vector */
	return newVec2D;
}

/* creating the binary addition operator + */
Vector2D CS230::operator+(const Vector2D& lhs, const Vector2D& rhs)
{
	/* declare a new 2d vector */
	Vector2D newVecAdd = { 0.0f, 0.0f };
	/* assigning new vector 2d with lhs to be operated on */
	newVecAdd = { lhs.x, lhs.y };
	/* add new vector 2d with rhs values */
	newVecAdd.x += rhs.x;
	newVecAdd.y += rhs.y;

	/* return new added vector */
	return newVecAdd;
}

/* creating the assignment addition operator + */
Vector2D& CS230::Vector2D::operator+=(const Vector2D& rhs)
{
	/* assign and add the lhs to the rhs */
	this->x += rhs.x;
	this->y += rhs.y;

	/* return the new calculated value pointer */
	return *this;
}

/* creating the binary minus operator + */
Vector2D CS230::operator-(const Vector2D& lhs, const Vector2D& rhs)
{
	/* declare a new 2d vector */
	Vector2D newVecAdd = { 0.0f, 0.0f };
	/* assigning new vector 2d with lhs to be operated on */
	newVecAdd = { lhs.x, lhs.y };
	/* subtract new vector 2d with rhs values */
	newVecAdd.x -= rhs.x;
	newVecAdd.y -= rhs.y;

	/* return new subtracted vector */
	return newVecAdd;
}

/* creating the assignment subtract operator + */
Vector2D& CS230::Vector2D::operator-=(const Vector2D& rhs)
{
	/* assign and subtract the lhs to the rhs */
	this->x -= rhs.x;
	this->y -= rhs.y;

	/* return the new calculated value pointer */
	return *this;
}

/* creating the scaling vector by rhs multiplication vector 2d */
Vector2D CS230::operator*(const Vector2D& lhs, float rhs)
{
	/* declare a new 2d vector */
	Vector2D newVecMul = { 0.0f, 0.0f };
	/* assign new 2d vector with given to be operated on */
	newVecMul.x = lhs.x;
	newVecMul.y = lhs.y;

	/* multiply each axis by rhs scale */
	newVecMul.x *= rhs;
	newVecMul.y *= rhs;

	/* return newly scaled 2d vector */
	return newVecMul;
}

/* creating the scaling vector by lhs multiplication vector 2d */
Vector2D CS230::operator*(float lhs, const Vector2D& rhs)
{
	/* declare a new 2d vector */
	Vector2D newVecMul = { 0.0f, 0.0f };
	/* assign new 2d vector with given to be operated on */
	newVecMul.x = rhs.x;
	newVecMul.y = rhs.y;

	/* multiply each axis by lhs scale */
	newVecMul.x *= lhs;
	newVecMul.y *= lhs;

	/* return newly scaled 2d vector */
	return newVecMul;
}

/* creating the scaling vector by rhs multiplication */
Vector2D& CS230::Vector2D::operator*=(float rhs)
{
	/* multiply the passed vector x and y with rhs value */
	this->x *= rhs;
	this->y *= rhs;

	/* return the new calculated value pointer */
	return *this;
}

/* creating the scaling vector by rhs division */
Vector2D CS230::operator/(const Vector2D& lhs, float rhs)
{	
	/* declare a new 2d vector */
	Vector2D newVecDiv = { 0.0f, 0.0f };
	/* assign new 2d vector with given to be operated on */
	newVecDiv.x = lhs.x;
	newVecDiv.y = lhs.y;

	/* divide each axis by lhs scale */
	newVecDiv.x /= rhs;
	newVecDiv.y /= rhs;

	/* return newly scaled 2d vector */
	return newVecDiv;
}

/* creating the scaling vector by rhs multiplication */
Vector2D& CS230::Vector2D::operator/=(float rhs)
{
	/* divide the passed vector x and y with rhs value */
	this->x /= rhs;
	this->y /= rhs;

	/* return the new calculated value pointer */
	return *this;
}

/* creating the noramlized vector 2d */
void CS230::Vector2DNormalize(Vector2D& pResult, const Vector2D& pVec0)
{
	/* declare variable to store calculations */
	float x = 0.0f, y = 0.0f, sum = 0.0f;
	/* assign vec2d x and y to new var x and y to be operated on */
	x = pVec0.x; y = pVec0.y;

	/* multiply x and y by itself respectively */
	x *= x;
	y *= y;

	/* calculate the magnitude of x and y */
	sum = sqrt(x + y);
	/* normalizing the vector by dividing each pts with its magnitude */
	pResult.x = pVec0.x / sum;
	pResult.y = pVec0.y / sum;
}

/* calculate the magnitude of vector */
float CS230::Vector2DLength(const Vector2D& pVec0)
{
	return sqrt((pVec0.x * pVec0.x) + (pVec0.y * pVec0.y));
}

/* calculate the squared magnitude of vector */
float CS230::Vector2DSquareLength(const Vector2D& pVec0)
{
	return ((pVec0.x * pVec0.x) + (pVec0.y * pVec0.y));
}

/* calculate the distance between 2 points (vector) */
float CS230::Vector2DDistance(const Vector2D& pVec0, const Vector2D& pVec1)
{
	return sqrt((pVec1.x - pVec0.x)*(pVec1.x - pVec0.x) + 
				(pVec1.y - pVec0.y)*(pVec1.y - pVec0.y));
}

/* calculate the squared distance between 2 points (vector) */
float CS230::Vector2DSquareDistance(const Vector2D& pVec0, const Vector2D& pVec1)
{
	return ((pVec1.x - pVec0.x) * (pVec1.x - pVec0.x) +
			(pVec1.y - pVec0.y) * (pVec1.y - pVec0.y));
}

/* calculate the dot product of 2 vectors and returns scalar */
float CS230::Vector2DDotProduct(const Vector2D& pVec0, const Vector2D& pVec1)
{
	return ((pVec0.x * pVec1.x) + (pVec0.y * pVec1.y));
}

/* calculate the cross product magnitude of 2 vectors and returns scalar */
float CS230::Vector2DCrossProductMag(const Vector2D& pVec0, const Vector2D& pVec1)
{
	return ((pVec0.x * pVec1.y) - (pVec0.y * pVec1.x));
}

