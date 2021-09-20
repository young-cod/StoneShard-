#pragma once
#include "singletonBase.h"
#include <vector>

struct tagIniDate
{
	const char* subject;
	const char* title;
	const char* body;
};


class iniDataManager : public singletonBase<iniDataManager>
{
private:
	typedef vector<tagIniDate>					arrIniData;
	typedef vector<tagIniDate>::iterator		arrIniDataIter;
	
	typedef vector<arrIniData>					arrIniDatas;
	typedef vector<arrIniDataIter>::iterator	arrIniDatasIter;


private:
	arrIniDatas _vDatas;

	char dataBuffer[256];
	char dataBuffer2[256];

	string titleName;
	char getX[256];
	char getY[256];
	char strBuffer[256];

public:
	iniDataManager();
	~iniDataManager();

	HRESULT init();
	void release();

	void addData(const char* subject, const char* title, const char* body);
	void deleteData(const char* subject, const char* title, const char* body);
	void iniSave(const char* fileName);
	

	char* loadDataString(const char* fileName, const char* subject, const char* title);
	
	char* loadDataString2(const char* fileName, const char* subject, const char* title);
	
	//øµº∑¿Ã≤®
	char* loadDataStr(const char* fileName, const char* subject, const char* title);
	int loadDataInt(const char* fileName, const char* subject, const char* title);

};

