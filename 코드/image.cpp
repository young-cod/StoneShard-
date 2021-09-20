#include "stdafx.h"
#include "image.h"

image::image()
	:_fileName(NULL)
{
}

image::~image()
{
}

/*
================================================
## �⺻ �̹���(������ �̹���X)
@@ bitmap	: ��Ʈ��
================================================
*/
HRESULT image::init(ID2D1Bitmap * const bitmap, const char * key)
{

	_bitmap = bitmap;
	_imageInfo = new IMAGE_INFO;
	_imageInfo->width = bitmap->GetPixelSize().width;
	_imageInfo->height = bitmap->GetPixelSize().height;

	int len = strlen(key);

	_fileName = new CHAR[len + 1];
	strcpy_s(_fileName, len + 1, key);

	ResetRenderOption();

	return S_OK;
}

HRESULT image::init(const char * key, int width, int height)
{
	_imageInfo = new IMAGE_INFO;
	_imageInfo->width = width;
	_imageInfo->height = height;

	int len = strlen(key);

	_fileName = new CHAR[len + 1];
	strcpy_s(_fileName, len + 1, key);

	ResetRenderOption();

	return S_OK;
}

/*
================================================
## �⺻ �̹���(������ �̹���X)
@@ bitmap	: ��Ʈ��
@@ fileName : ���� �̸�
@@ widht	: type(0) - �ʺ�  type(1) maxFrameX
@@ height	: type(0) - ����  type(1) maxFrameY
@@ type		: �Ϲ��̹���(0) , �������̹���(1)
================================================
*/
HRESULT image::init(ID2D1Bitmap * const bitmap, const char * key, int width, int height, bool type)
{

	_bitmap = bitmap;

	if (!type)
	{
		_imageInfo = new IMAGE_INFO;
		_imageInfo->width = width;
		_imageInfo->height = height;

		int len = strlen(key);

		_fileName = new CHAR[len + 1];
		strcpy_s(_fileName, len + 1, key);
	}
	else
	{
		_imageInfo = new IMAGE_INFO;
		_imageInfo->width = bitmap->GetPixelSize().width;
		_imageInfo->height = bitmap->GetPixelSize().height;
		_imageInfo->maxFrameX = width;
		_imageInfo->maxFrameY = height;
		_imageInfo->currentFrameX = 0;
		_imageInfo->currentFrameY = 0;
		_imageInfo->frameWidth = _imageInfo->width / width;
		_imageInfo->frameHeight = _imageInfo->height / height;

		int len = strlen(key);

		_fileName = new CHAR[len + 1];
		strcpy_s(_fileName, len + 1, key);
	}

	ResetRenderOption();

	return S_OK;
}

/*
================================================
## ������ �̹���
@@ bitmap	: ��Ʈ��
@@ fileName : ���� �̸�
@@ widht	: �ʺ�
@@ height	: ����
@@ frameX	: �ִ� ���� �� ������ ����
@@ frameY	: �ִ� ���� �� ������ ����
================================================
*/
HRESULT image::init(ID2D1Bitmap * const bitmap, const char * key, int width, int height, int frameX, int frameY)
{

	_bitmap = bitmap;

	_imageInfo = new IMAGE_INFO;
	_imageInfo->width = bitmap->GetPixelSize().width;
	_imageInfo->height = bitmap->GetPixelSize().height;
	_imageInfo->maxFrameX = frameX;
	_imageInfo->maxFrameY = frameY;
	_imageInfo->currentFrameX = 0;
	_imageInfo->currentFrameY = 0;
	_imageInfo->frameWidth = _imageInfo->width / frameX;
	_imageInfo->frameHeight = _imageInfo->height / frameY;

	_count = 0;

	int len = strlen(key);

	_fileName = new CHAR[len + 1];
	strcpy_s(_fileName, len + 1, key);

	ResetRenderOption();

	return S_OK;
}

void image::release()
{
	SAFE_DELETE(_bitmap);
	SAFE_DELETE(_fileName);
}

/*
================================================
## �⺻ ����
@@ x, y				: �̹����� ���� left,top
@@ scaleW, scaleH	: �̹��� ������ ����(�⺻ 1.f)
@@ degreeAngle		: �츮�� ���� ���� ���� ex) 180�� (�⺻ 0.f)
@@ rotateX, rotateY	: �̹����� ȸ�� �� ���� �� (�⺻ 0.f)
@@ transX, transY	: �̹��� �̵� ��Ű�� (�⺻ 0.f)
================================================
*/
void image::render(const float x, const float y,
	const float scaleW, const float scaleH,
	const float degreeAngle, const float rotateX, const float rotateY,
	const float transX, const float transY)
{

	D2D1::Matrix3x2F scaleMatrix = D2D1::Matrix3x2F::Scale(scaleW, scaleH, D2D1::Point2F(x, y));
	D2D1::Matrix3x2F rotateMatrix = D2D1::Matrix3x2F::Rotation(-degreeAngle, D2D1::Point2F(x + rotateX, y + rotateY));
	D2D1::Matrix3x2F transMatrix = D2D1::Matrix3x2F::Translation(transX, transY);

	D2D1_RECT_F viewArea = D2D1::RectF(x, y, x + _imageInfo->width, y + _imageInfo->height);

	D2DRENDERTARGET->SetTransform(scaleMatrix * rotateMatrix * transMatrix);
	D2DRENDERTARGET->DrawBitmap(_bitmap, viewArea, _alpha);

	if (_alpha <= 0)ResetRenderOption();
}

void image::frameRender(int destX, int destY, int currentFrameX, int currentFrameY)
{
	cutRender(destX, destY, currentFrameX, currentFrameY, _imageInfo->frameWidth, _imageInfo->frameHeight);
}


void image::aniRender(int destX, int destY, animation * ani)
{
	cutRender( destX, destY, ani->getFramePos().x, ani->getFramePos().y, ani->getFrameWidth(), ani->getFrameHeight());
}
 
/*
================================================
## �⺻ ����(�̹��� �� Ư�� ���� �߶� ��� ����)
@@ x, y				: �̹����� ���� left,top
@@ sourX, sourY		: �̹��� �ڸ� ��ġ
@@ sourW, sourH		: ȭ�鿡 ���� �̹��� �ʺ�, ����
@@ alpha			: ���� ����(�⺻ 1.f)
@@ scaleW, scaleH	: �̹��� ������ ����(�⺻ 1.f)
@@ degreeAngle		: �츮�� ���� ���� ���� ex) 180�� (�⺻ 0.f)
@@ rotateX, rotateY	: �̹����� ȸ�� �� ���� �� (�⺻ 0.f)
@@ transX, transY	: �̹��� �̵� ��Ű�� (�⺻ 0.f)
================================================
*/
void image::cutRender(const float x, const float y,
	const float sourX, const float sourY,
	const float sourW, const float sourH,
	const float alpha,
	const float scaleW, const float scaleH,
	const float degreeAngle, const float rotateX, const float rotateY,
	const float transX, const float transY)
{
	D2D1::Matrix3x2F scaleMatrix = D2D1::Matrix3x2F::Scale(scaleW, scaleH, D2D1::Point2F(x, y));
	D2D1::Matrix3x2F rotateMatrix = D2D1::Matrix3x2F::Rotation(-degreeAngle, D2D1::Point2F(x + rotateX, y + rotateY));
	D2D1::Matrix3x2F transMatrix = D2D1::Matrix3x2F::Translation(transX, transY);

	int cutX = sourX * _imageInfo->frameWidth;
	int cutY = sourY * _imageInfo->frameHeight;

	D2D1_RECT_F viewArea = D2D1::RectF(x, y, x + sourW, y + sourH);						//���̴� ����
	D2D1_RECT_F sourArea = D2D1::RectF(cutX, cutY, cutX+_imageInfo->frameWidth,cutY+ _imageInfo->frameHeight);			//�ڸ� ����

	D2DRENDERTARGET->SetTransform(scaleMatrix * rotateMatrix * transMatrix);
	D2DBACKTARGER->DrawBitmap(_bitmap, viewArea, alpha,
		D2D1_BITMAP_INTERPOLATION_MODE_LINEAR, &sourArea);

	if (alpha <= 0)ResetRenderOption();
}

void image::tileRender(const float x, const float y, const float sourX, const float sourY, const float sourW, const float sourH, const float alpha, const float scaleW, const float scaleH, const float degreeAngle, const float rotateX, const float rotateY, const float transX, const float transY)
{
	D2D1::Matrix3x2F scaleMatrix = D2D1::Matrix3x2F::Scale(scaleW, scaleH, D2D1::Point2F(x, y));
	D2D1::Matrix3x2F rotateMatrix = D2D1::Matrix3x2F::Rotation(-degreeAngle, D2D1::Point2F(x + rotateX, y + rotateY));
	D2D1::Matrix3x2F transMatrix = D2D1::Matrix3x2F::Translation(transX, transY);

	int cutX = sourX * _imageInfo->frameWidth;
	int cutY = sourY * _imageInfo->frameHeight;

	D2D1_RECT_F viewArea = D2D1::RectF(x, y, x + sourW, y + sourH);						//���̴� ����
	D2D1_RECT_F sourArea = D2D1::RectF(cutX, cutY, cutX + sourW, cutY + sourH);			//�ڸ� ����

	D2DRENDERTARGET->SetTransform(scaleMatrix * rotateMatrix * transMatrix);
	D2DBACKTARGER->DrawBitmap(_bitmap, viewArea, alpha,
		D2D1_BITMAP_INTERPOLATION_MODE_LINEAR, &sourArea);

	if (alpha <= 0)ResetRenderOption();
}

void image::barRender(const float X, const float Y, const float sourX)
{
	D2D1_RECT_F sourArea = D2D1::RectF(X, Y, X + sourX, Y + _imageInfo->height);
	D2D1_RECT_F backArea = D2D1::RectF(X, Y, X + _imageInfo->width, Y + _imageInfo->height);

	D2DBACKTARGER->DrawBitmap(_bitmap, sourArea, _alpha);

	ResetRenderOption();
}
void image::objRender(const float x, const float y, bool type, const float scaleW, const float scaleH)
{
	D2D1::Matrix3x2F scaleMatrix = D2D1::Matrix3x2F::Scale(scaleW, scaleH, D2D1::Point2F(x, y));

	D2D1_RECT_F viewArea = D2D1::RectF(x, y, x + _imageInfo->width, y + _imageInfo->height);

	D2DRENDERTARGET->SetTransform(scaleMatrix);
	if(!type)D2DRENDERTARGET->DrawBitmap(_bitmap, viewArea, _alpha);
	else D2DBACKTARGER->DrawBitmap(_bitmap, viewArea, _alpha);

	if (_alpha <= 0)ResetRenderOption();
}
void image::objRender_F(const float x, const float y, const float sourX, const float sourY, const float sourW, const float sourH, const float alpha)
{
	int cutX = sourX * _imageInfo->frameWidth;
	int cutY = sourY * _imageInfo->frameHeight;

	D2D1_RECT_F viewArea = D2D1::RectF(x, y, x + sourW, y + sourH);						//���̴� ����
	D2D1_RECT_F sourArea = D2D1::RectF(cutX, cutY, cutX + sourW, cutY + sourH);			//�ڸ� ����

	D2DBACKTARGER->DrawBitmap(_bitmap, viewArea, alpha,
		D2D1_BITMAP_INTERPOLATION_MODE_LINEAR, &sourArea);
	if (alpha <= 0)ResetRenderOption();
}

void image::playerRender(const float x, const float y, const float scaleW, const float scaleH, const float degreeAngle, const float rotateX, const float rotateY, const float transX, const float transY)
{
	D2D1::Matrix3x2F scaleMatrix = D2D1::Matrix3x2F::Scale(scaleW, scaleH, D2D1::Point2F(x, y));
	D2D1::Matrix3x2F rotateMatrix = D2D1::Matrix3x2F::Rotation(-degreeAngle, D2D1::Point2F(x + rotateX, y + rotateY));
	D2D1::Matrix3x2F transMatrix = D2D1::Matrix3x2F::Translation(transX, transY);

	D2D1_RECT_F viewArea = D2D1::RectF(x, y, x + _imageInfo->width, y + _imageInfo->height);

	D2DRENDERTARGET->SetTransform(scaleMatrix * rotateMatrix * transMatrix);
	D2DBACKTARGER->DrawBitmap(_bitmap, viewArea, _alpha);

	if (_alpha <= 0)ResetRenderOption();
}
void image::playerRender_F(bool type, const float x, const float y, const float sourX, const float sourY, const float sourW, const float sourH, const float alpha, const float scaleW, const float scaleH, const float degreeAngle, const float rotateX, const float rotateY, const float transX, const float transY)
{
	D2D1::Matrix3x2F scaleMatrix = D2D1::Matrix3x2F::Scale(scaleW, scaleH, D2D1::Point2F(x, y));
	D2D1::Matrix3x2F rotateMatrix = D2D1::Matrix3x2F::Rotation(-degreeAngle, D2D1::Point2F(x + rotateX, y + rotateY));
	D2D1::Matrix3x2F transMatrix = D2D1::Matrix3x2F::Translation(transX, transY);

	int cutX = sourX * _imageInfo->frameWidth;
	int cutY = sourY * _imageInfo->frameHeight;

	D2D1_RECT_F viewArea = D2D1::RectF(x, y, x + sourW, y + sourH);						//���̴� ����
	D2D1_RECT_F sourArea = D2D1::RectF(cutX, cutY, cutX + sourW, cutY + sourH);			//�ڸ� ����
	if (type)
	{
		D2DRENDERTARGET->SetTransform(scaleMatrix * rotateMatrix * transMatrix);
		D2DRENDERTARGET->DrawBitmap(_bitmap, viewArea, alpha,
			D2D1_BITMAP_INTERPOLATION_MODE_LINEAR, &sourArea);
	}
	else
	{
		D2DRENDERTARGET->SetTransform(scaleMatrix * rotateMatrix * transMatrix);
		D2DBACKTARGER->DrawBitmap(_bitmap, viewArea, alpha,
			D2D1_BITMAP_INTERPOLATION_MODE_LINEAR, &sourArea);
	}

	if (alpha <= 0)ResetRenderOption();
}
void image::mapRender(const float x, const float y,
	const float scaleW, const float scaleH,
	const float degreeAngle, const float rotateX, const float rotateY,
	const float transX, const float transY)
{
	D2D1::Matrix3x2F scaleMatrix = D2D1::Matrix3x2F::Scale(scaleW, scaleH, D2D1::Point2F(x, y));
	D2D1::Matrix3x2F rotateMatrix = D2D1::Matrix3x2F::Rotation(-degreeAngle, D2D1::Point2F(x + rotateX, y + rotateY));
	D2D1::Matrix3x2F transMatrix = D2D1::Matrix3x2F::Translation(transX, transY);

	D2D1_RECT_F viewArea = D2D1::RectF(x, y, x + _imageInfo->width, y + _imageInfo->height);

	D2DRENDERTARGET->SetTransform(scaleMatrix * rotateMatrix * transMatrix);
	D2DBACKTARGER->DrawBitmap(_bitmap, viewArea, _alpha);

	if (_alpha <= 0)ResetRenderOption();
}

void image::uiRender(bool type,const float x, const float y, const float alpha)
{
	D2D1_RECT_F viewArea = D2D1::RectF(x, y, x + _imageInfo->width, y + _imageInfo->height);

	if(type)D2DRENDERTARGET->DrawBitmap(_bitmap, viewArea, alpha);
	else D2DBACKTARGER->DrawBitmap(_bitmap, viewArea, alpha);
	if (_alpha <= 0)ResetRenderOption();
}

void image::uiRender_F(bool type,const float x, const float y, const float sourX, const float sourY, const float sourW, const float sourH, const float alpha, const float scaleW, const float scaleH, const float degreeAngle, const float rotateX, const float rotateY, const float transX, const float transY)
{
	D2D1::Matrix3x2F scaleMatrix = D2D1::Matrix3x2F::Scale(scaleW, scaleH, D2D1::Point2F(x, y));
	D2D1::Matrix3x2F rotateMatrix = D2D1::Matrix3x2F::Rotation(-degreeAngle, D2D1::Point2F(x + rotateX, y + rotateY));
	D2D1::Matrix3x2F transMatrix = D2D1::Matrix3x2F::Translation(transX, transY);

	int cutX = sourX * _imageInfo->frameWidth;
	int cutY = sourY * _imageInfo->frameHeight;

	D2D1_RECT_F viewArea = D2D1::RectF(x, y, x + sourW, y + sourH);						//���̴� ����
	D2D1_RECT_F sourArea = D2D1::RectF(cutX, cutY, cutX + sourW, cutY + sourH);			//�ڸ� ����
	if (type)
	{
	D2DRENDERTARGET->SetTransform(scaleMatrix * rotateMatrix * transMatrix);
	D2DRENDERTARGET->DrawBitmap(_bitmap, viewArea, alpha,
		D2D1_BITMAP_INTERPOLATION_MODE_LINEAR, &sourArea);
	}
	else
	{
		D2DRENDERTARGET->SetTransform(scaleMatrix * rotateMatrix * transMatrix);
		D2DBACKTARGER->DrawBitmap(_bitmap, viewArea, alpha,
			D2D1_BITMAP_INTERPOLATION_MODE_LINEAR, &sourArea);
	}

	if (alpha <= 0)ResetRenderOption();
}

void image::sampleRender(const float x, const float y, const float alpha)
{
	D2D1_RECT_F viewArea = D2D1::RectF(x, y, x + _imageInfo->width, y + _imageInfo->height);

	D2DSAMPLETARGET->DrawBitmap(_bitmap, viewArea, _alpha);

	if (_alpha <= 0)ResetRenderOption();
}

void image::sampleRender_F(const float x, const float y, const float sourX, const float sourY, const float sourW, const float sourH, const float alpha)
{
	int cutX = sourX * _imageInfo->frameWidth;
	int cutY = sourY * _imageInfo->frameHeight;

	D2D1_RECT_F viewArea = D2D1::RectF(x, y, x + sourW, y + sourH);						//���̴� ����
	D2D1_RECT_F sourArea = D2D1::RectF(cutX, cutY, cutX + sourW, cutY + sourH);			//�ڸ� ����

	D2DSAMPLETARGET->DrawBitmap(_bitmap, viewArea, alpha,
		D2D1_BITMAP_INTERPOLATION_MODE_LINEAR, &sourArea);
	if (alpha <= 0)ResetRenderOption();
}


/********************************************************************************
## ResetRenderOption ##
�̹��� Ŭ���� ���� ���� �ɼǵ� ���� �ʱ�ȭ
*********************************************************************************/
void image::ResetRenderOption()
{
	_alpha = 1.0f;
	_scale = 1.0f;
	_angle = 0.f;
	//if (_imageInfo->.size() <= 1)
	//{
	//	this->mSize.x = (float)mBitmap->GetPixelSize().width;
	//	this->mSize.y = (float)mBitmap->GetPixelSize().height;
	//}
	//else
	//{
	//	this->mSize.x = mFrameInfo[0].width;
	//	this->mSize.y = mFrameInfo[0].height;
	//}
}
