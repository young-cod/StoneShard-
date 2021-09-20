#include "stdafx.h"
#include "iniDataManager.h"


iniDataManager::iniDataManager()
{
}


iniDataManager::~iniDataManager()
{
}

HRESULT iniDataManager::init()
{
	return S_OK;
}

void iniDataManager::release()
{
}

void iniDataManager::addData(const char * subject, const char * title, const char * body)
{
	tagIniDate iniData;
	iniData.subject = subject;
	iniData.title = title;
	iniData.body = body;

	arrIniData vIniData;
	vIniData.push_back(iniData);

	_vDatas.push_back(vIniData);
}
void iniDataManager::deleteData(const char * subject, const char * title, const char * body)
{

}

void iniDataManager::iniSave(const char * fileName)
{
	char str[256];
	char dir[256];

	ZeroMemory(dir, sizeof(dir));
	sprintf_s(dir, "\\saveLoad\\%s.ini", fileName);

	//현재 디텍토리 경로를 받아와주는 함수
	GetCurrentDirectory(256, str);
	strncat_s(str, 256, dir, 254);

	for (int i = 0; i < _vDatas.size(); ++i)
	{
		arrIniData vData = _vDatas[i];
		WritePrivateProfileString(vData[0].subject, vData[0].title, vData[0].body, str);

		vData.clear();
	}
	_vDatas.clear();
}


char* iniDataManager::loadDataString(const char * fileName, const char * subject, const char * title)
{
	char str[1024];
	char dir[1024];

	ZeroMemory(dir, sizeof(dir));
	sprintf_s(dir, "\\%s.ini", fileName);

	GetCurrentDirectory(1024, str);
	strncat_s(str, 1024, dir, 1022);

	char data[1024] = {};
	GetPrivateProfileString(subject, title, "", dataBuffer, 1024, str);

	return dataBuffer;
}
char* iniDataManager::loadDataString2(const char * fileName, const char * subject, const char * title)
{
	char str[1024];
	char dir[1024];

	ZeroMemory(dir, sizeof(dir));
	sprintf_s(dir, "\\%s.ini", fileName);

	GetCurrentDirectory(1024, str);
	strncat_s(str, 1024, dir, 1022);

	char data[1024] = {};
	GetPrivateProfileString(subject, title, "", dataBuffer2, 1024, str);

	return dataBuffer2;
}

char* iniDataManager::loadDataStr(const char * fileName, const char * subject, const char * title)
{
	char str[1024];
	char dir[1024];

	ZeroMemory(dir, sizeof(dir));
	sprintf_s(dir, "\\saveLoad\\%s.ini", fileName);

	GetCurrentDirectory(1024, str);
	strncat_s(str, 1024, dir, 1022);

	char data[1024] = {};
	GetPrivateProfileString(subject, title, "", strBuffer, 1024, str);

	return strBuffer; 
}


int iniDataManager::loadDataInt(const char * fileName, const char * subject, const char * title)
{
	char str[256];
	char dir[256];

	ZeroMemory(dir, sizeof(dir));
	sprintf_s(dir, "\\saveLoad\\%s.ini", fileName);

	GetCurrentDirectory(256, str);
	strncat_s(str, 256, dir, 254);


	return GetPrivateProfileInt(subject, title, 0, str);
}