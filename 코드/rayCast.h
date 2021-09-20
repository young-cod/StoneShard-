#pragma once
#include "gameNode.h"


#define TILETESTX 39
#define TILETESTY 23

#define TSIZE 26
#define BIT 5
#define TLENTH 8
#define PI 3.14159265359
#define P2 PI/2
#define P3 3*PI/2

#define RD 0.0174533
#define DR 57.2958

#define VULSIZE 60

class stage1;

enum AT
{
	WALL,
	VI,
	NONE
};

struct tagTestTile
{
	RECT rc;
	AT attribute;
	bool is;
};

struct tagTestPlayer
{
	RECT rc;
	int idX, idY;
	float x, y;
	float angle;
};

class rayCast : public gameNode
{
private:
	//===========
private:
	vector<int> _visionListH;
	vector<int> _visionListV;
	
	vector<int> result;

	tagTestTile _tile[TILETESTX*TILETESTY];
	tagTestPlayer _player;

	int _tileX, _tileY;

	POINT s;
	POINT ray[VULSIZE];

	POINT a[VULSIZE];
	POINT b[VULSIZE];
	int r;
	float rx, ry, ra, xo, yo;
	int dof;
	int mx, my, mp;
	vector<int> _mapMp;
	

public:
	stage1* _stage1;

	HRESULT init();
	void release();
	void update();
	void test();
	void render();

	vector<int> rayOn(int tileX, int tileY, int x, int y, int tile[]);
};

