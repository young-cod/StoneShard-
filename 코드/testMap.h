#pragma once
#include "gameNode.h"

struct tagNemo
{
	RECT rc;
	int type;
};

class testMap : public gameNode
{
private:
	treeNode* _treeNode;
	tagNemo _tile[SIZE_ARR_Y][SIZE_ARR_X];

	int arr[SIZE_ARR_Y][SIZE_ARR_X];

	int x, y;

public:
	testMap() {};
	~testMap() {};

	HRESULT init();
	void release();
	void update();
	void render();

	void makeTree(treeNode* node);
	void makeConnect(treeNode* node);
};
