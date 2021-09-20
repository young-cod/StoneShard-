#pragma once
#include "gameNode.h"

struct tagImageObject
{
	image* img;
	int left, top;
	int count;
	RECT rc;
	tagImageObject()
	{
		left = top = count = 0;
	}
};

struct tagMainButton
{
	RECT rc;
	image* img;
	int left, top;
	int count;
};

class title : public gameNode
{
private:
	tagImageObject _start;
	tagImageObject _logo_one;
	tagImageObject _logo_two;
	tagImageObject _loading;

	image* _main;
	tagImageObject _hammer;
	tagImageObject _sword;
	tagImageObject _nameLogo;
	tagMainButton _play[3];
	tagMainButton _option[3];
	tagMainButton _god[3];
	tagMainButton _exit[3];

	tagImageObject _stoneShard;
	tagImageObject _stoneEffect;

	int _timer=0;

public:
	title() {};
	~title() {};

	HRESULT init();
	void release();
	void update();
	void render();

	void imageSet();
	void frameSet();
	void buttonSet();


	void mainRender();
	void buttonRender();
};

