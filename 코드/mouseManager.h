#pragma once
#include "singletonBase.h"

class mouseManager : public singletonBase<mouseManager>
{
private:
	image* _mouse;
	image* _area;
	POINT _xyMouse;

public:
	HRESULT init();
	void release();
	void update();
	void render();

	void imageSet();
	void click();

	POINT getMouse() { return _xyMouse; }
	
	void setMouseImg(image* img) {  _mouse = img; }
	image* getImage() { return _mouse; }
	void setArea(int frame) { _area->setFrameX(frame); }
};

