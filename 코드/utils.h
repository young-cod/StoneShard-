#pragma once

#define PI 3.141592f
#define PI2 PI*2

#define RECT_WIDTH(rc) static_cast<float>(rc.right - rc.left)
#define RECT_HEIGHT(rc) static_cast<float>(rc.bottom - rc.top)
#define RECT_CENTER_X(rc) static_cast<float>((rc.left + rc.right) * 0.5f)
#define RECT_CENTER_Y(rc) static_cast<float>((rc.top + rc.bottom) * 0.5f)


namespace LYS_UTIL
{
	//거리가져오는 함수
	float GetDistance(float startX, float startY, float endX, float endY);
	float GetDistanceM(float idX1, float idY1, float idX2, float idY2);
	float GetAngle(float x1, float y1, float x2, float y2);

	
	bool IsCollision(const RECT& rc1, const RECT& rc2);

	//wchar_t 에서 char 로의 형변환 함수
	char * ConvertWCtoC(wchar_t * str);
	const char * ConvertWCtoC(const wchar_t * str);
	//char 에서 wchar_t 로의 형변환 함수
	wchar_t *ConvertCtoWC(char * str);
	const wchar_t *ConvertCtoWC(const char * str);
	//stirng 에서 wstring 으로 형 변환 함수
	wstring ConvertStoWS(string str);
	string ConvertWStoS(wstring w_str);

	// OBB충돌
	// 실질적으로 사용해주는 건 SHAPE 와 OBB입니다.
	// interSectRect를 위해 rect를 만들어주는 것처럼 SHAPE를 만들고
	// OBB로 체크하면 됩니다.
	typedef struct VECTOR
	{
		double x, y;
	};

	typedef struct SHAPE //회전충돌::실질적 사용
	{
		double left, top, width, height, degreeAngle;
	};

	VECTOR addVector(VECTOR& a, VECTOR& b);
	float absDotVector(VECTOR& a, VECTOR& b);
	float degreeToRadian(float degreeAngle);
	float radianToDegree(float radianAngle);
	VECTOR getDistanceVector(SHAPE& a, SHAPE& b);
	VECTOR getHeightVector(SHAPE& a);
	VECTOR getWidthVector(SHAPE& a);
	VECTOR getUnitVector(VECTOR& a);
	bool OBB(SHAPE& a, SHAPE& b); //회전충돌::실질적 사용
}