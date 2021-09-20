
#include "stdafx.h"
#include "utils.h"

namespace LYS_UTIL
{
	float GetDistance(float startX, float startY, float endX, float endY)
	{
		float x = endX - startX;
		float y = endY - startY;

		return sqrtf(x * x + y * y);
	}

	float GetDistanceM(float idX1, float idY1, float idX2, float idY2)
	{
		return abs(idX1-idX2) + abs(idY1 - idY2);
	}

	//앵글값을 얻어오는 함수 3D에서 벡터개념과 비슷
	float GetAngle(float x1, float y1, float x2, float y2)
	{
		float x = x2 - x1;
		float y = y2 - y1;

		float distance = sqrtf(x * x + y * y);
		float angle = acosf(x / distance);

		if (y2 > y1)
		{
			angle = PI2 - angle;

			if (angle >= PI2) angle -= PI2;
		}

		return angle;
	}


	//사각형이 사각형과 충돌했니?
	bool IsCollision(const RECT& rc1, const RECT& rc2)
	{
		if ((rc1.left <= rc2.right && rc1.right >= rc2.left) &&
			(rc1.top <= rc2.bottom && rc1.bottom >= rc2.top)) return true;
		return false;
	}

	char * ConvertWCtoC(wchar_t * str)
	{
		//반환할 char* 변수 선언
		char* pStr;

		//입력받은 wchar_t 변수의 길이를 구함
		int strSize = WideCharToMultiByte(CP_ACP, 0, str, -1, NULL, 0, NULL, NULL);
		//char* 메모리 할당
		pStr = new char[strSize];

		//형 변환 
		WideCharToMultiByte(CP_ACP, 0, str, -1, pStr, strSize, 0, 0);
		return pStr;
	}

	const char * ConvertWCtoC(const wchar_t * str)
	{
		//반환할 char* 변수 선언
		char* pStr;

		//입력받은 wchar_t 변수의 길이를 구함
		int strSize = WideCharToMultiByte(CP_ACP, 0, str, -1, NULL, 0, NULL, NULL);
		//char* 메모리 할당
		pStr = new char[strSize];

		//형 변환 
		WideCharToMultiByte(CP_ACP, 0, str, -1, pStr, strSize, 0, 0);
		return pStr;
	}

	wchar_t *ConvertCtoWC(char * str)
	{
		//wchar_t형 변수 선언
		wchar_t* pStr;
		//멀티 바이트 크기 계산 길이 반환
		int strSize = MultiByteToWideChar(CP_ACP, 0, str, -1, NULL, NULL);
		//wchar_t 메모리 할당
		pStr = new WCHAR[strSize];
		//형 변환
		MultiByteToWideChar(CP_ACP, 0, str, strlen(str) + 1, pStr, strSize);
		return pStr;
	}
	
	const wchar_t *ConvertCtoWC(const char * str)
	{
		//wchar_t형 변수 선언
		wchar_t* pStr;
		//멀티 바이트 크기 계산 길이 반환
		int strSize = MultiByteToWideChar(CP_ACP, 0, str, -1, NULL, NULL);
		//wchar_t 메모리 할당
		pStr = new WCHAR[strSize];
		//형 변환
		MultiByteToWideChar(CP_ACP, 0, str, strlen(str) + 1, pStr, strSize);
		return pStr;
	}

	wstring ConvertStoWS(string str)
	{
		wstring w_str = L"";

		w_str.assign(str.begin(), str.end());

		return w_str;
	}

	string ConvertWStoS(wstring w_str)
	{
		string str;

		str.assign(w_str.begin(), w_str.end());

		return str;
	}
	
	VECTOR addVector(VECTOR& a, VECTOR& b) //벡터 추가
	{
		VECTOR vector;
		vector.x = a.x + b.x;
		vector.y = a.y + b.y;
		return vector;
	}

	float absDotVector(VECTOR& a, VECTOR& b) //내적 벡터절대값 (abs == 절대값)
	{
		return abs(a.x * b.x + a.y * b.y);
	}

	float degreeToRadian(float degreeAngle) //디그리 라디안 변환
	{
		return degreeAngle / 180 * PI;
	}
	float radianToDegree(float radianAngle)
	{
		return radianAngle * 180 / PI;
	}

	VECTOR getDistanceVector(SHAPE& a, SHAPE& b) //중점 거리 벡터
	{
		VECTOR vectorDistance;
		vectorDistance.x = (a.left + a.width / 2) - (b.left + b.width / 2);
		vectorDistance.y = (a.top + a.height / 2) - (b.top + b.height / 2);
		return vectorDistance;
	}

	VECTOR getHeightVector(SHAPE& a) //높이
	{
		VECTOR vectorHeight;
		vectorHeight.x = a.height * cos(degreeToRadian(a.degreeAngle - 90)) / 2;
		vectorHeight.y = a.height * sin(degreeToRadian(a.degreeAngle - 90)) / 2;
		return vectorHeight;
	}

	VECTOR getWidthVector(SHAPE& a) //폭
	{
		VECTOR vectorWidth;
		vectorWidth.x = a.width * cos(degreeToRadian(a.degreeAngle)) / 2;
		vectorWidth.y = a.width * sin(degreeToRadian(a.degreeAngle)) / 2;
		return vectorWidth;
	}

	VECTOR getUnitVector(VECTOR& a) //단위벡터 == 유클리안벡터 :: 크기가 1인 방향을 갖는 벡터
	{
		VECTOR unitVector;
		float size;
		size = sqrt(pow(a.x, 2) + pow(a.y, 2));
		unitVector.x = a.x / size;
		unitVector.y = a.y / size;
		return unitVector;
	}

	bool OBB(SHAPE& a, SHAPE& b) //체크
	{
		VECTOR distance = getDistanceVector(a, b);
		VECTOR vector[4] = { getHeightVector(a), getHeightVector(b), getWidthVector(a), getWidthVector(b) };
		VECTOR unitVector;
		for (int i = 0; i < 4; i++)
		{
			float sum = 0;
			unitVector = getUnitVector(vector[i]);
			for (int j = 0; j < 4; j++) {
				sum += absDotVector(vector[j], unitVector);
			}
			if (absDotVector(distance, unitVector) > sum)
			{
				return false;
			}
		}
		return true;
	}
}