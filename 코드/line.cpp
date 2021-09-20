#include "stdafx.h"
#include "Line.h"


/**************************************************************************************************
## TagLine ##
**************************************************************************************************/
Figure::FloatLine::FloatLine(const Vector2& start, const Vector2& end)
	: start(start), end(end) {}
//�߽� ���� ���� �������� line����
Figure::FloatLine::FloatLine(const Vector2& start, const float& angle, const float& dist)
	: start(start)
{
	end.x = cosf(angle) * dist;
	end.y = -sinf(angle) * dist;
}

void Figure::FloatLine::Update(const Vector2 & start, const Vector2 & end)
{
	this->start = start;
	this->end = end;
}

float Figure::FloatLine::Length()
{
	return Vector2::Length(&(start - end));
}


