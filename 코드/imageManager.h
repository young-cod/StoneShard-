#pragma once
#include "singletonBase.h"
#include "image.h"

/****************************************************************************
## ImageRenderer ##
*****************************************************************************/
class imageManager : public singletonBase<imageManager>
{
public:
	/*static imageManager* GetInstance()
	{
		static imageManager istance;
		return &istance;
	}*/

	//unordered_map : 해시테이블 알고리즘으로 이루어져 있다
	//map : 레드블랙바이너리트리 알고리즘으로 이루어져 있다
private:
	typedef map<string, image*>				mapImageList;
	typedef map<string, image*>::iterator	mapImageIter;
private:
	mapImageList _mImageList;

	class IWICImagingFactory* mWicFactory;
public:
	imageManager();
	~imageManager();

	HRESULT init();
	void release();

	image* addImage(int width, int height);
	image* addImage(string key, const wstring& fileName);
	image* addImage(string key, int width , int height);
	image* addImage(string key, const wstring& fileName,int width, int height);

	image* addFrameImage(string key, const wstring& fileName, int maxFrameX, int maxFrameY);
	image* addFrameImage(string key, const wstring& fileName, int width, int height, int maxFrameX, int maxFrameY);

	image* findImage(string key);

	BOOL deleteImage(string key);

	BOOL deleteAll();

	void render(string key, int destX, int destY);
	void render(string key, int destX, int destY, int sourX, int sourY, int sourW, int sourH);


	ID2D1Bitmap* CreateD2DBitmapFromFile(const wstring& file);
};

//#define IMAGEMANAGER imageManager::GetInstance()