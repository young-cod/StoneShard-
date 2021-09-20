#include "stdafx.h"
#include "imageManager.h"

#include "Image.h"
#include <io.h>

imageManager::imageManager()
	:mWicFactory(nullptr)
{
	//WIC 팩토리 생성
	//Windows Imaging Component
	//Direct2D는 이미지를 로드하는 기능이 없다. 
	//고로 Direct2D는 WIC라는 라이브러리의 이미지로부터 이미지 데이터를 만들 수 있다.
	CoInitialize(NULL);
	HRESULT hr = CoCreateInstance(CLSID_WICImagingFactory, NULL, CLSCTX_INPROC_SERVER, IID_PPV_ARGS(&mWicFactory));
#ifdef _DEBUG
	assert(SUCCEEDED(hr));
#endif
}

/*********************************************************************
## ImageManager ##
**********************************************************************/
imageManager::~imageManager()
{
	this->deleteAll();
	NEW_SAFE_RELEASE(mWicFactory);
}
HRESULT imageManager::init()
{
	return S_OK;
}
void imageManager::release()
{
	deleteAll();
}
image * imageManager::addImage(int width, int height)
{
	image* img;

	return nullptr;
}
image * imageManager::addImage(string key, const wstring & fileName)
{
	image* img = findImage(key);

	if (img)return img;

	ID2D1Bitmap* bitmap = CreateD2DBitmapFromFile(fileName);

	if (bitmap)
	{

		img = new image;
		img->init(bitmap,ConvertWStoS(fileName).c_str());
	
		_mImageList.insert(make_pair(key, img));
	}


	return nullptr;
}
image * imageManager::addImage(string key, int width, int height)
{
	image* img = findImage(key);

	if (img)return img;

		img = new image;
		img->init(key.c_str(),width, height);
		_mImageList.insert(make_pair(key, img));


	return nullptr;
}
image * imageManager::addImage(string key, const wstring & fileName, int width, int height)
{
	image* img = findImage(key);

	if (img)return img;

	ID2D1Bitmap* bitmap = CreateD2DBitmapFromFile(fileName);

	if (bitmap)
	{
		img = new image;
		img->init(bitmap, ConvertWStoS(fileName).c_str(), width, height);
		_mImageList.insert(make_pair(key, img));
		return img;
	}
	else assert(SUCCEEDED(E_FAIL));

	return nullptr;
}

image * imageManager::addFrameImage(string key, const wstring & fileName, int maxFrameX, int maxFrameY)
{
	image* img = findImage(key);

	if (img)return img;

	ID2D1Bitmap* bitmap = CreateD2DBitmapFromFile(fileName);
	if (bitmap)
	{
		img = new image;
		img->init(bitmap, ConvertWStoS(fileName).c_str(), maxFrameX, maxFrameY, 1);
		_mImageList.insert(make_pair(key, img));
	}


	return nullptr;
}

image * imageManager::addFrameImage(string key, const wstring & fileName, int width, int height, int maxFrameX, int maxFrameY)
{
	image* img = findImage(key);

	if (img)return img;

	ID2D1Bitmap* bitmap = CreateD2DBitmapFromFile(fileName);

	if (bitmap)
	{
		img = new image;
		img->init(bitmap, ConvertWStoS(fileName).c_str(), width, height, maxFrameX, maxFrameY);

		_mImageList.insert(make_pair(key, img));

		return img;
	}

	return nullptr;
}
image * imageManager::findImage(string key)
{
	mapImageIter findKey = _mImageList.find(key);

	if (findKey != _mImageList.end())
	{
		return findKey->second;
	}

	return nullptr;
}
BOOL imageManager::deleteImage(string key)
{
	mapImageIter findKey = _mImageList.find(key);

	if (findKey != _mImageList.end())
	{
		findKey->second->release();
		SAFE_DELETE(findKey->second);
		_mImageList.erase(findKey);

		return true;
	}
	return false;
}
BOOL imageManager::deleteAll()
{
	mapImageIter iter = _mImageList.begin();

	for (; iter != _mImageList.end();)
	{
		if (iter->second != nullptr)
		{
			iter->second->release();
			SAFE_DELETE(iter->second);
			_mImageList.erase(iter);
		}
		else ++iter;
	}
	_mImageList.clear();

	return false;
}
void imageManager::render(string key, int destX, int destY)
{
	image* img = findImage(key);

	if (img)img->render(destX, destY);
}
void imageManager::render(string key, int destX, int destY, int sourX, int sourY, int sourW, int sourH)
{
	image* img = findImage(key);

	if (img)img->cutRender(destX, destY, sourX, sourY, sourW, sourH);
}

/*********************************************************************
## CreateD2DBitmapFromFile ##
@@ wstring file : 파일 경로
**********************************************************************/

ID2D1Bitmap * imageManager::CreateD2DBitmapFromFile(const wstring & file)
{
	//디코더 생성
	IWICBitmapDecoder* ipDecoder = nullptr;
	HRESULT hr;
	hr = mWicFactory->CreateDecoderFromFilename(file.c_str(), NULL, GENERIC_READ,
		WICDecodeMetadataCacheOnDemand, &ipDecoder);
#ifdef _DEBUG
	assert(SUCCEEDED(hr));
#endif
	//디코더에서 프레임얻음
	IWICBitmapFrameDecode* ipFrame = nullptr;
	hr = ipDecoder->GetFrame(0, &ipFrame);
#ifdef _DEBUG
	assert(SUCCEEDED(hr));
#endif
	//프레임을 기반으로 포맷 컨버터 생성
	IWICFormatConverter* convertedSrcBmp = nullptr;
	hr = mWicFactory->CreateFormatConverter(&convertedSrcBmp);
#ifdef _DEBUG
	assert(SUCCEEDED(hr));
#endif
	//컨버터 초기화
	hr = convertedSrcBmp->Initialize
	(
		ipFrame,
		GUID_WICPixelFormat32bppPBGRA,
		WICBitmapDitherTypeNone,
		nullptr,
		0.0f,
		WICBitmapPaletteTypeCustom
	);
#ifdef _DEBUG
	assert(SUCCEEDED(hr));
#endif
	//컨버트된 데이터를 기반으로 실제 Direct2D용 비트맵을 생성
	ID2D1Bitmap* ipResult = nullptr;
	hr = D2DRenderer::GetInstance()->GetRenderTarget()->CreateBitmapFromWicBitmap
	(
		convertedSrcBmp,
		nullptr,
		&ipResult
	);
#ifdef _DEBUG
	assert(SUCCEEDED(hr));
#endif

	NEW_SAFE_RELEASE(convertedSrcBmp);
	NEW_SAFE_RELEASE(ipFrame);
	NEW_SAFE_RELEASE(ipDecoder);

	return ipResult;
}