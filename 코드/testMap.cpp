#include "stdafx.h"
#include "testMap.h"


HRESULT testMap::init()
{
	x = 0;
	y = 0;
	_treeNode = new treeNode;
	//Ã¹ ¸ÊÅ©±â
	_treeNode->setInfo(tagMatrix(0, 0, SIZE_ARR_X, SIZE_ARR_Y));
	_treeNode->setParentNode(NULL);


	for (int i = 0; i < SIZE_ARR_Y; i++)
	{
		for (int j = 0; j < SIZE_ARR_X; j++)
		{
			SetRect(&_tile[i][j].rc,
				(j * 32/2),
				(i * 32/2),
				(j * 32/2) + 32/2,
				(i * 32/2) + 32/2);

			_tile[i][j].type = 0;
		}
	}

	memset(_tile, 0, sizeof((*_tile)[SIZE_ARR_X]));
	memset(arr, 0, sizeof(arr));

	makeTree(_treeNode);

	while (1)
	{
		makeConnect(_treeNode);
		if (_treeNode->getLeftNode()->getRoomInfo().width > 0)break;
	}

	
	return S_OK;
}

void testMap::release()
{
}

void testMap::update()
{
	
	if (KEYMANAGER->isStayKeyDown(VK_LEFT))
	{
		x -= 5.f;
	}if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
	{
		x += 5.f;
	}if (KEYMANAGER->isStayKeyDown(VK_UP))
	{
		y -= 5.f;
	}if (KEYMANAGER->isStayKeyDown(VK_DOWN))
	{
		y += 5.f;
	}
	CAMERAMANAGER->updateCameraStone(x, y);

	if (KEYMANAGER->isOnceKeyDown('R'))
	{
		memset(_tile, 0, sizeof((*_tile)[SIZE_ARR_X]));
		memset(arr, 0, sizeof(arr));

		makeTree(_treeNode);

		while (1)
		{
			makeConnect(_treeNode);
			if (_treeNode->getLeftNode()->getRoomInfo().width > 0)break;
		}
	}
}

void testMap::render()
{
	for (int i = 0; i < SIZE_ARR_Y; i++)
	{
		for (int j = 0; j < SIZE_ARR_X; j++)
		{
			if (arr[i][j] == 1)
			{
				D2DRENDER->DrawRectangle(_tile[i][j].rc, false, D2DDEFAULTBRUSH::Red);
			}
			else if (arr[i][j] == 2)
			{
				D2DRENDER->DrawRectangle(_tile[i][j].rc, false, D2DDEFAULTBRUSH::Blue);
			}
			else
			{
				D2DRENDER->DrawRectangle(_tile[i][j].rc, false, D2DDEFAULTBRUSH::Yellow);
			}

		}
	}
}


void testMap::makeTree(treeNode * node)
{
	tagMatrix mat1, mat2;

	int direction;
	int type = RND->getInt(2);

	float cutRatio = RND->getFromIntTo(40, 60);

	if (type == 0)
	{
		direction = HORIZONTAL;
		int cut = (node->getInfo().width - node->getInfo().x)	*(cutRatio / 100);
		mat1.x = node->getInfo().x;
		mat1.y = node->getInfo().y;
		mat1.width = node->getInfo().width - cut;
		mat1.height = node->getInfo().height;

		mat2.x = node->getInfo().width - cut;
		mat2.y = node->getInfo().y;
		mat2.width = node->getInfo().width;
		mat2.height = node->getInfo().height;

		
	}
	else
	{
		direction = VERTICAL;
		int cut = (node->getInfo().height - node->getInfo().y)*(cutRatio / 100);
		mat1.x = node->getInfo().x;
		mat1.y = node->getInfo().y;
		mat1.width = node->getInfo().width;
		mat1.height = node->getInfo().height - cut;

		mat2.x = node->getInfo().x;
		mat2.y = node->getInfo().height - cut;
		mat2.width = node->getInfo().width;
		mat2.height = node->getInfo().height;

	}
	if (mat1.width - mat1.x < 10 ||
		mat1.height - mat1.y < 10 ||
		mat2.width - mat2.x < 10 ||
		mat2.height - mat2.y < 10)
	{
		int left = 3;//RND->getFromIntTo(1, 5);
		int right = 3;//RND->getFromIntTo(1, 5);
		int top = 3;//RND->getFromIntTo(1, 5);
		int bottom = 3;//RND->getFromIntTo(1, 5);

		for (int i = node->getInfo().y + top; i < node->getInfo().height - bottom; i++)
		{
			for (int j = node->getInfo().x + left; j < node->getInfo().width - right; j++)
			{
				_tile[i][j].type = 1;
				arr[i][j] = 1;
			}
		}
		node->setRoomInfo(tagMatrix(
			node->getInfo().x + left,
			node->getInfo().y + top,
			node->getInfo().width - right,
			node->getInfo().height - bottom));
		return;
	}
	node->makeLeftTree(new treeNode);
	node->getLeftNode()->setInfo(mat1);
	node->getLeftNode()->setParentNode(node);
	node->getLeftNode()->setDirection(direction);
	makeTree(node->getLeftNode());

	node->makeRightTree(new treeNode);
	node->getRightNode()->setInfo(mat2);
	node->getRightNode()->setParentNode(node);
	node->getRightNode()->setDirection(direction);
	makeTree(node->getRightNode());
	return;
}

void testMap::makeConnect(treeNode * node)
{
	if (!node->getLeftNode())
	{
		if (node->getParentNode()->getLeftNode() == node)node->makeConnection(arr);
		return;
	}
	else if (node->getRoomInfo().width>0)
	{
		if (!node->getParentNode())return;
		if (node->getParentNode()->getLeftNode() == node)node->makeConnection(arr);
		return;
	}
	else
	{
		makeConnect(node->getLeftNode());
		makeConnect(node->getRightNode());
	}
}
