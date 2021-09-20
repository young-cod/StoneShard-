#pragma once
#include "gameNode.h"

class button : public gameNode
{
private:
	image* _img;
	RECT _rc;
	RECT _description;
	bool _isClick;
public:
	button();
	~button();

	HRESULT init();
	HRESULT init(image* img);
	void release();
	void update();
	void render();

	void imageSet();

	RECT getRECT() { return _rc; }
	void setRECT(RECT rc) { _rc = rc; }
	bool getIsClick() { return _isClick; }
	void setIsClick(bool is) { _isClick = is; }
	image* getImage() { return _img; }
	void setImage(image* img) { _img = img; }
	int getWidth() { return _rc.right - _rc.left; }
	int getHeight() { return _rc.bottom - _rc.top; }
	RECT getDesCription() { return _description; }
	void setDiscription(RECT rc) { _description = rc; }
};

