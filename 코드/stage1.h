#pragma once
#include "gameNode.h"
#include "mapmap.h"
#include "aStar.h"
#include "rayCast.h"
#include "playerManager.h"
#include <algorithm>


class stage1 : public gameNode
{
private:
	//백그라운드 맵
	image* _map;

	//타일
	tagTile _tile[TILEX*TILEY];
	image* _tileImage;

	//오브젝트
	vector<tagCurrentObj> _vObject;

	//플레이어
	playerManager* _player;
	int _initCount;
	int _sCount;

	//에이스타
	aStar* _aStar;
	int _countPath;
	vector<pair<int, int>> result;

	//마우스
	bool objClick;

	//레이
	rayCast* _ray;
	image* _black;
	int _vision[TILEX*TILEY];
	int _view[TILEX*TILEY];
	vector<int> _rayResult;

	RECT nextScene;


public:
	HRESULT init();
	void release();
	void update();
	void render();

	void setup();
	void load();

	void aPath();
	void visionSet();
	void objectControl();
	void objectFrame();
	RECT objectRectSet(tagCurrentObj obj);


	IMAGETYPE typeSet(int type);
	bool isValidTile(int x, int y);

};

