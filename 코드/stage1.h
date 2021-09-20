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
	//��׶��� ��
	image* _map;

	//Ÿ��
	tagTile _tile[TILEX*TILEY];
	image* _tileImage;

	//������Ʈ
	vector<tagCurrentObj> _vObject;

	//�÷��̾�
	playerManager* _player;
	int _initCount;
	int _sCount;

	//���̽�Ÿ
	aStar* _aStar;
	int _countPath;
	vector<pair<int, int>> result;

	//���콺
	bool objClick;

	//����
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

