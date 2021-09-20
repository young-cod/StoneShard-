#pragma once
//=============================
// ## 21.06.24 ## Macro~ ##
//=============================

//선긋기 뿌려줄DC, 선시작좌표X 선시작좌표Y 선의 끝좌표X, 선의 끝좌표Y
inline void LineMake(HDC hdc, int startX, int startY, int endX, int endY)
{
	MoveToEx(hdc, startX, startY, NULL);
	LineTo(hdc, endX, endY);
}

//
inline void LineMake(HDC hdc, Vector2 start, Vector2 end, float angle, float dist=0.f)
{
	MoveToEx(hdc, start.x, start.y, NULL);

	end.x = cosf(angle)*dist;
	end.y = -sinf(angle)*dist;

	LineTo(hdc, end.x, end.y);
}


//매크로 포인트
inline POINT PointMake(int x, int y)
{
	POINT pt = { x,y };

	return pt;
}

//================= 렉트 관련 함수 ===================
//left, top 기준으로 렉트 탄생(left, top, 가로크기, 세로크기)
inline RECT RectMake(int x, int y, int width, int height)
{
	RECT rc = { x, y, x +width, y + height };

	return rc;
}
inline RECT RectMakeDrag(int left, int top, int right, int bottom)
{
	RECT rc = { left, top, right, bottom};

	return rc;
}

// 중점 X,Y를 기준으로 렉트탄생(중점X, 중점Y, 가로크기, 세로크기)
inline RECT RectMakeCenter(int x, int y, int width, int height)
{
	RECT rc = { x - (width / 2), y - (height / 2), x + (width / 2), y + (height / 2) };

	return rc;
}



//================= 사각형 관련 함수 ==================

inline void Rectangle(HDC hdc, RECT& rc)
{
	Rectangle(hdc, rc.left, rc.top, rc.right, rc.bottom);
}



//left, top 기준으로 사각형그린다(뿌려줄DC, 기준점 X, 기준점 Y, 가로크기, 세로크기)
inline void RectangleMake(HDC hdc, int x, int y, int width, int height)
{
	Rectangle(hdc, x, y, x + width, y + height);
}

// 중점 X,Y를 기준으로 사각형탄생(뿌려줄DC, 중점X, 중점Y, 가로크기, 세로크기)
inline void RectangleMakeCenter(HDC hdc, int x, int y, int width, int height)
{
	Rectangle(hdc, x - (width / 2), y - (height / 2),
		x + (width / 2), y + (height / 2));
}

//================== 원 관련 함수 =====================
inline void Ellipse(HDC hdc, RECT& rc)
{
	Ellipse(hdc, rc.left, rc.top, rc.right, rc.bottom);
}

//left, top 기준으로 원 그린다(뿌려줄DC, 기준점 X, 기준점 Y, 가로크기, 세로크기)
inline void EllipseMake(HDC hdc, int x, int y, int width, int height)
{
	Ellipse(hdc, x, y, x + width, y + height);
}

// 중점 X,Y를 기준으로 원 탄생(뿌려줄DC, 중점X, 중점Y, 가로크기, 세로크기)
inline void EllipseMakeCenter(HDC hdc, int x, int y, int width, int height)
{
	Ellipse(hdc, x - (width / 2), y - (height / 2),
		x + (width / 2), y + (height / 2));
}