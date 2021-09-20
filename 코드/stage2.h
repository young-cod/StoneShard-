#pragma once
#include "gameNode.h"
#include "mapmap.h"	
#include "playerManager.h"
#include "aStar.h"


class stage2 : public gameNode
{
private:
	//맵 관련
	image* _map;
	int x, y;
	//타일 관련
	image* _sample;
	tagTile _tile[TILEX*TILEY];

	//오브젝트 관련
	vector<tagCurrentObj> _vObject;
	bool objClick;

	//플레이어 관련
	playerManager* _player;

	//에이스타 관련
	aStar* _aStar;
	vector<pair<int, int>> result;
	int _countPath;

	//마우스 관련
	//보스 관련
	int initY;
public:
	HRESULT init();
	void release();
	void update();
	void render();

	void setUp();
	void load();

	void objectControl();
	void objectFrame();
	RECT objectRectSet(tagCurrentObj obj);

	void aPath();

	IMAGETYPE typeSet(int type);
	bool isValidTile(int x, int y);
};

