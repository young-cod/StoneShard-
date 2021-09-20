#pragma once
#include "gameNode.h"
#include <vector>

struct tagStatue
{
	image* img;
	float x, y;
	int count;
	int frameX;
	int hp;
};

struct tagArchon
{
	image* img;
	float x, y;
	int count;
	int frameX;
	tagStatue statueL;
	tagStatue statueR;
};

struct tagUndead
{
	image* img;
	int x, y;
	int count;
	int frameX;
};
class enemy :public gameNode
{
private:
	vector<tagUndead> _vUndead;
	vector<tagUndead>::iterator _viUndead;
private:
	tagArchon _archon;
	
public:
	HRESULT init(image* img, int x, int y);
	void release();
	void update();
	void render();

	void setup();

	void setStatueL(int x, int y) { _archon.statueL.x = x; _archon.statueL.y = y; }
	void setStatueR(int x, int y) { _archon.statueL.x = x; _archon.statueL.y = y; }

	void setUndead(int x, int y);

	void imageSet();

};

