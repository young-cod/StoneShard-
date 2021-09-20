
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

	//�ޱ۰��� ������ �Լ� 3D���� ���Ͱ���� ���
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


	//�簢���� �簢���� �浹�ߴ�?
	bool IsCollision(const RECT& rc1, const RECT& rc2)
	{
		if ((rc1.left <= rc2.right && rc1.right >= rc2.left) &&
			(rc1.top <= rc2.bottom && rc1.bottom >= rc2.top)) return true;
		return false;
	}

	char * ConvertWCtoC(wchar_t * str)
	{
		//��ȯ�� char* ���� ����
		char* pStr;

		//�Է¹��� wchar_t ������ ���̸� ����
		int strSize = WideCharToMultiByte(CP_ACP, 0, str, -1, NULL, 0, NULL, NULL);
		//char* �޸� �Ҵ�
		pStr = new char[strSize];

		//�� ��ȯ 
		WideCharToMultiByte(CP_ACP, 0, str, -1, pStr, strSize, 0, 0);
		return pStr;
	}

	const char * ConvertWCtoC(const wchar_t * str)
	{
		//��ȯ�� char* ���� ����
		char* pStr;

		//�Է¹��� wchar_t ������ ���̸� ����
		int strSize = WideCharToMultiByte(CP_ACP, 0, str, -1, NULL, 0, NULL, NULL);
		//char* �޸� �Ҵ�
		pStr = new char[strSize];

		//�� ��ȯ 
		WideCharToMultiByte(CP_ACP, 0, str, -1, pStr, strSize, 0, 0);
		return pStr;
	}

	wchar_t *ConvertCtoWC(char * str)
	{
		//wchar_t�� ���� ����
		wchar_t* pStr;
		//��Ƽ ����Ʈ ũ�� ��� ���� ��ȯ
		int strSize = MultiByteToWideChar(CP_ACP, 0, str, -1, NULL, NULL);
		//wchar_t �޸� �Ҵ�
		pStr = new WCHAR[strSize];
		//�� ��ȯ
		MultiByteToWideChar(CP_ACP, 0, str, strlen(str) + 1, pStr, strSize);
		return pStr;
	}
	
	const wchar_t *ConvertCtoWC(const char * str)
	{
		//wchar_t�� ���� ����
		wchar_t* pStr;
		//��Ƽ ����Ʈ ũ�� ��� ���� ��ȯ
		int strSize = MultiByteToWideChar(CP_ACP, 0, str, -1, NULL, NULL);
		//wchar_t �޸� �Ҵ�
		pStr = new WCHAR[strSize];
		//�� ��ȯ
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
	
	VECTOR addVector(VECTOR& a, VECTOR& b) //���� �߰�
	{
		VECTOR vector;
		vector.x = a.x + b.x;
		vector.y = a.y + b.y;
		return vector;
	}

	float absDotVector(VECTOR& a, VECTOR& b) //���� �������밪 (abs == ���밪)
	{
		return abs(a.x * b.x + a.y * b.y);
	}

	float degreeToRadian(float degreeAngle) //��׸� ���� ��ȯ
	{
		return degreeAngle / 180 * PI;
	}
	float radianToDegree(float radianAngle)
	{
		return radianAngle * 180 / PI;
	}

	VECTOR getDistanceVector(SHAPE& a, SHAPE& b) //���� �Ÿ� ����
	{
		VECTOR vectorDistance;
		vectorDistance.x = (a.left + a.width / 2) - (b.left + b.width / 2);
		vectorDistance.y = (a.top + a.height / 2) - (b.top + b.height / 2);
		return vectorDistance;
	}

	VECTOR getHeightVector(SHAPE& a) //����
	{
		VECTOR vectorHeight;
		vectorHeight.x = a.height * cos(degreeToRadian(a.degreeAngle - 90)) / 2;
		vectorHeight.y = a.height * sin(degreeToRadian(a.degreeAngle - 90)) / 2;
		return vectorHeight;
	}

	VECTOR getWidthVector(SHAPE& a) //��
	{
		VECTOR vectorWidth;
		vectorWidth.x = a.width * cos(degreeToRadian(a.degreeAngle)) / 2;
		vectorWidth.y = a.width * sin(degreeToRadian(a.degreeAngle)) / 2;
		return vectorWidth;
	}

	VECTOR getUnitVector(VECTOR& a) //�������� == ��Ŭ���Ⱥ��� :: ũ�Ⱑ 1�� ������ ���� ����
	{
		VECTOR unitVector;
		float size;
		size = sqrt(pow(a.x, 2) + pow(a.y, 2));
		unitVector.x = a.x / size;
		unitVector.y = a.y / size;
		return unitVector;
	}

	bool OBB(SHAPE& a, SHAPE& b) //üũ
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