#pragma once

#define PI 3.141592f
#define PI2 PI*2

#define RECT_WIDTH(rc) static_cast<float>(rc.right - rc.left)
#define RECT_HEIGHT(rc) static_cast<float>(rc.bottom - rc.top)
#define RECT_CENTER_X(rc) static_cast<float>((rc.left + rc.right) * 0.5f)
#define RECT_CENTER_Y(rc) static_cast<float>((rc.top + rc.bottom) * 0.5f)


namespace LYS_UTIL
{
	//�Ÿ��������� �Լ�
	float GetDistance(float startX, float startY, float endX, float endY);
	float GetDistanceM(float idX1, float idY1, float idX2, float idY2);
	float GetAngle(float x1, float y1, float x2, float y2);

	
	bool IsCollision(const RECT& rc1, const RECT& rc2);

	//wchar_t ���� char ���� ����ȯ �Լ�
	char * ConvertWCtoC(wchar_t * str);
	const char * ConvertWCtoC(const wchar_t * str);
	//char ���� wchar_t ���� ����ȯ �Լ�
	wchar_t *ConvertCtoWC(char * str);
	const wchar_t *ConvertCtoWC(const char * str);
	//stirng ���� wstring ���� �� ��ȯ �Լ�
	wstring ConvertStoWS(string str);
	string ConvertWStoS(wstring w_str);

	// OBB�浹
	// ���������� ������ִ� �� SHAPE �� OBB�Դϴ�.
	// interSectRect�� ���� rect�� ������ִ� ��ó�� SHAPE�� �����
	// OBB�� üũ�ϸ� �˴ϴ�.
	typedef struct VECTOR
	{
		double x, y;
	};

	typedef struct SHAPE //ȸ���浹::������ ���
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
	bool OBB(SHAPE& a, SHAPE& b); //ȸ���浹::������ ���
}