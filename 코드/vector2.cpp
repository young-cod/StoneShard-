#include "stdafx.h"
#include "Vector2.h"


/****************************************************************************************************
## Vector2 ##
*****************************************************************************************************/
Vector2::Vector2()
	:x(0.f), y(0.f) {}

Vector2::Vector2(const float& x, const float& y)
	: x(x), y(y) {}

Vector2::Vector2(const int& x, const int& y)
	: x((float)x), y((float)y) {}

Vector2::Vector2(const POINT& pt)
	: x((float)pt.x), y((float)pt.y) {}

/****************************************************************************************************
## GetIntX ##
@@ return int : int Çü x
*****************************************************************************************************/
const int Vector2::GetIntX()
{
	return static_cast<int>(this->x);
}
/****************************************************************************************************
## GetIntY ##
@@ return int : intÇü y
*****************************************************************************************************/
const int Vector2::GetIntY()
{
	return static_cast<int>(this->y);
}
/****************************************************************************************************
## GetPoint ##
@@ return POINT : POINT Çü Vector2
*****************************************************************************************************/
const POINT Vector2::GetPoint()
{
	return { (LONG)x,(LONG)y };
}
/****************************************************************************************************
## Operator oveloading ##
*****************************************************************************************************/
Vector2 Vector2::operator+(const Vector2& v)
{
	Vector2 result;
	result.x = this->x + v.x;
	result.y = this->y + v.y;
	return result;
}

Vector2 Vector2::operator-(const Vector2& v)
{
	Vector2 result;
	result.x = this->x - v.x;
	result.y = this->y - v.y;
	return result;
}

void Vector2::operator+=(const Vector2& v)
{
	this->x += v.x;
	this->y += v.y;
}

void Vector2::operator-=(const Vector2& v)
{
	this->x -= v.x;
	this->y -= v.y;
}

Vector2 Vector2::operator*(const float& scalar)
{
	Vector2 result;
	result.x = this->x * scalar;
	result.y = this->y * scalar;
	return result;
}

Vector2 Vector2::operator/(const float& scalar)
{
	Vector2 result;
	result.x = this->x / scalar;
	result.y = this->y / scalar;
	return result;
}

/****************************************************************************************************
## Static Normalize ##
@@ Vector2* pVector2 : Á¤±ÔÈ­ ÇÒ º¤ÅÍ

@@ return Vector2 : Á¤±ÔÈ­µÈ º¤ÅÍ
*****************************************************************************************************/
Vector2 Vector2::Normalize(const Vector2* const pVector2)
{
	Vector2 result = *pVector2;

	float length = sqrtf(result.x * result.x + result.y * result.y);
	result.x /= length;
	result.y /= length;

	return result;
}

/****************************************************************************************************
## static Length ##
@@ Vector2* pVector2 : Å©±â ±¸ÇÒ º¤ÅÍ

@@ return float : º¤ÅÍÀÇ Å©±â
*****************************************************************************************************/
float Vector2::Length(const Vector2* const pVector2)
{
	return sqrt(pVector2->x * pVector2->x + pVector2->y * pVector2->y);
}
/****************************************************************************************************
## static Dot ##
@@ Vector2* pVector2A : º¤ÅÍ A
@@ Vector2* pVector2B : º¤ÅÍ B

@@ return float : µÎ º¤ÅÍÀÇ ³»Àû °ª
*****************************************************************************************************/
float Vector2::Dot(const Vector2* const pVector2A, const Vector2* const pVector2B)
{
	return pVector2A->x * pVector2B->x + pVector2A->y * pVector2B->y;
}
/****************************************************************************************************
## static Cross ##
@@ Vector2* pVector2A : º¤ÅÍ A
@@ Vector2* pVector2B : º¤ÅÍ B

@@ return float : µÎ º¤ÅÍÀÇ ¿ÜÀû °ª
*****************************************************************************************************/
float Vector2::Cross(const Vector2* const pvector2A, const Vector2* const pVector2B)
{
	return pvector2A->x * pVector2B->y - pvector2A->y * pVector2B->x;
}

