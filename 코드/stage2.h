#pragma once
#include "gameNode.h"
#include "mapmap.h"	
#include "playerManager.h"
#include "aStar.h"


class stage2 : public gameNode
{
private:
	//�� ����
	image* _map;
	int x, y;
	//Ÿ�� ����
	image* _sample;
	tagTile _tile[TILEX*TILEY];

	//������Ʈ ����
	vector<tagCurrentObj> _vObject;
	bool objClick;

	//�÷��̾� ����
	playerManager* _player;

	//���̽�Ÿ ����
	aStar* _aStar;
	vector<pair<int, int>> result;
	int _countPath;

	//���콺 ����
	//���� ����
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

