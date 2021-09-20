#pragma once
#include "animation.h"

class image final
{
public:

	typedef struct tagImageInfo
	{
		int				width;			//이미지 전체 가로크기
		int				height;			//이미지 전체 세로크기
		int				currentFrameX;	//현재 프레임 번호(가로)
		int				currentFrameY;	//현재 프레임 번호(세로)
		int				maxFrameX;		//최대 프레임 번호(가로)
		int				maxFrameY;		//최대 프레임 번호(세로)
		int				frameWidth;		//1프레임 당 가로크기
		int				frameHeight;	//1프레임 당 세로크기
		float				x;
		float				y;

		tagImageInfo()
		{
			width = 0;
			height = 0;
			currentFrameX = 0;
			currentFrameY = 0;
			maxFrameX = 0;
			maxFrameY = 0;
			frameWidth = 0;
			frameHeight = 0;
			x = 0;
			y = 0;
		}
		RECT rc;
	}IMAGE_INFO, *LPIMAGE_INFO;

private:
	LPIMAGE_INFO	_imageInfo;
	CHAR*			_fileName;
		
	ID2D1Bitmap*	_bitmap;			//이미지 비트맵
		
	float			_alpha;
	float			_scale;
	float			_angle;
	int				_count;

public:	
	image();
	~image();

	HRESULT init(ID2D1Bitmap* const bitmap, const char* key);
	HRESULT init(const char* key,int width, int height);
	HRESULT init(ID2D1Bitmap*const bitmap, const char* key, int width, int height, bool type = false);
	HRESULT init(ID2D1Bitmap*const bitmap, const char* key, int width, int height, int frameX, int frameY);

	void release();

	void render(const float x, const float y, const float scaleW = 1.f, const float scaleH = 1.f,
		const float degreeAngle = 0.f, const float rotateX = 0.f, const float rotateY = 0.f,
		const float transX = 0.f, const float transY = 0.f);
	void frameRender(int destX, int destY, int currentFrameX, int currentFrameY);
	void aniRender(int destX, int destY, animation* ani);
	void barRender(const float X, const float Y, const float sourX);
	void objRender(const float x, const float y, bool type = false, const float scaleW = 1.f, const float scaleH = 1.f);
	void objRender_F(const float x, const float y, const float sourX, const float sourY,
		const float sourW, const float sourH, const float alpha = 1.f);
	void cutRender(const float x, const float y, const float sourX, const float sourY,
		const float sourW, const float sourH, const float alpha = 1.f, const float scaleW = 1.f, const float scaleH = 1.f,
		const float degreeAngle = 0.f, const float rotateX = 0.f, const float rotateY = 0.f,
		const float transX = 0.f, const float transY = 0.f);
	void tileRender(const float x, const float y, const float sourX, const float sourY,
		const float sourW, const float sourH, const float alpha = 1.f, const float scaleW = 1.f, const float scaleH = 1.f,
		const float degreeAngle = 0.f, const float rotateX = 0.f, const float rotateY = 0.f,
		const float transX = 0.f, const float transY = 0.f);
	void playerRender(const float x, const float y, const float scaleW = 1.f, const float scaleH = 1.f,
		const float degreeAngle = 0.f, const float rotateX = 0.f, const float rotateY = 0.f,
		const float transX = 0.f, const float transY = 0.f);
	void playerRender_F(bool type, const float x, const float y, const float sourX, const float sourY,
		const float sourW, const float sourH, const float alpha = 1.f, const float scaleW = 1.f, const float scaleH = 1.f,
		const float degreeAngle = 0.f, const float rotateX = 0.f, const float rotateY = 0.f,
		const float transX = 0.f, const float transY = 0.f);
	void mapRender(const float x, const float y, const float scaleW = 1.f, const float scaleH = 1.f,
		const float degreeAngle = 0.f, const float rotateX = 0.f, const float rotateY = 0.f,
		const float transX = 0.f, const float transY = 0.f);
	void uiRender(bool type,const float x, const float y, const float alpha = 1.f);
	void uiRender_F(bool type,const float x, const float y, const float sourX, const float sourY,
		const float sourW, const float sourH, const float alpha = 1.f, const float scaleW = 1.f, const float scaleH = 1.f,
		const float degreeAngle = 0.f, const float rotateX = 0.f, const float rotateY = 0.f,
		const float transX = 0.f, const float transY = 0.f);
	void sampleRender(const float x, const float y, const float alpha = 1.f);
	void sampleRender_F(const float x, const float y, const float sourX, const float sourY,
		const float sourW, const float sourH, const float alpha = 1.f);
	/*===============================================================
							접근자 / 설정자
	===============================================================*/


	void	ResetRenderOption();

	float	getAlpha() { return _alpha; }
	void	setAlpha(const float alpha) { _alpha = alpha; }
	void	setScale(const float scale) { _scale = scale; }
	void	setAngle(const float angle) { _angle = angle; }

	float	getX() { return _imageInfo->x; }
	void	setX(float x) { _imageInfo->x = x; }
	float	getY() { return _imageInfo->y; }
	void	setY(float y) { _imageInfo->y = y; }

	void	setFrameX(int frameX) { _imageInfo->currentFrameX = frameX; }
	int		getFrameX() { return _imageInfo->currentFrameX; }
	void	setFrameY(int frameY) { _imageInfo->currentFrameY = frameY; }
	int		getFrameY() { return _imageInfo->currentFrameY; }

	const int getMaxFrameX()const { return _imageInfo->maxFrameX; }
	const int getMaxFrameY()const { return _imageInfo->maxFrameY; }
	const UINT getWidth() const { return _imageInfo->width; }		//원본 이미지 사이즈 크기 가져오기
	const UINT getHeight()const { return _imageInfo->height; }		//원본 이미지 사이즈 크기 가져오기
	const float getFrameWidth()const { return _imageInfo->frameWidth; }
	const float getFrameHeight()const { return _imageInfo->frameHeight; }
	Vector2 getFrameSize(const int& frame = 0) const { return Vector2(_imageInfo->frameWidth, _imageInfo->height); }
};

