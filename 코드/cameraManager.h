#pragma once
#include "singletonBase.h"

struct tagCamera
{
	RECT rc;
	float width, height;
	float x, y;
};

struct tagMap
{
	RECT rc;
	float width, height;
	float x, y;
};

class cameraManager : public singletonBase<cameraManager>
{
private:
	tagCamera _camera;
	tagMap _map;

	float _x, _y;
	float _zoomX, _zoomY;
	bool _isZoom;
	string _type;

public:
	HRESULT init();
	void release();
	void update();
	void render();
	void cameraRender(int x, int y);

	void setMapCamera(float x, float y);
	void setCamera(float x, float y);

	//게터세터 쓰는 용
	void updateCamera(POINT mouse);		
	//그냥 이 함수 자체로 쓰는 용
	void updateCamera(POINT mouse,POINT mouse2, int speed =1.f);	
	void updateCamera(POINT mouse,POINT mouse2,float x,float y);	

	//맵 중앙 기준
	void updateCamera(RECT& player, float playerX, float playerY);
	void updateCameraH(float x, float y);
	void updateCameraW(RECT player ,float x, float y, float ratio1, float ratio2);

	//스톤샤드 용
	void updateCameraStone(float x, float y);
	void updateCameraIndex(int idX, int idY);

	float getX() { return _x; }
	void setX(float x) { _x = x; }
	float getY() { return _y; }
	void setY(float y) { _y = y; }
	tagCamera getCameraInfo() { return _camera; }
	void setLeft(float left) { _camera.rc.left = left; }
	void setTop(float top) { _camera.rc.left = top; }
	string getType() { return _type; }
	void setTpye(string str) {  _type = str; }
	//
	float getZoomX() { return _zoomX; }
	void setZoomX(float x) { _zoomX = x; }

	float getZoomY() { return _zoomY; }
	void setZoomY(float y) { _zoomY = y; }

	bool getIsZoom() { return _isZoom; }
	void setIsZoom(bool is) { _isZoom = is; }

	
	void mousePoint();
};

