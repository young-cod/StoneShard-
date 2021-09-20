#include "stdafx.h"
#include "testMap.h"

void treeNode::makeConnection(int(*arr)[SIZE_ARR_X])
{
	if (_roomInfo.x < NULL)return;

	float num = 50;

	if (_direction == VERTICAL)
	{
		int initX = _roomInfo.width;
		int initY = _roomInfo.y * (num / 100) + _roomInfo.height * (num / 100);

		for (int i = initX; arr[initY][i] != 1; i++)
		{
			if (i > SIZE_ARR_X-1)break;
			arr[initY][i] = 2;
		}
	}

	if (_direction == HORIZONTAL)
	{
		int initX = _roomInfo.x * (num / 100) + _roomInfo.width * (num / 100);
		int initY = _roomInfo.height;

		for (int i = initY; arr[i][initX] != 1; i++)
		{
			if (i > SIZE_ARR_X - 1)break;
			arr[i][initX] = 2;
		}

		/*int i = initY;
		while (1)
		{
			if (arr[i][initX] == 1 || i > 59)break;
			arr[i][initX] = 2;
			i++;
		}*/

	}
	_connect = true;
	if (!_parentNode->getParentNode())return;
	_parentNode->setRoomInfo(_parentNode->getRightNode()->getRoomInfo());
	if (_parentNode != _parentNode->_parentNode->getLeftNode())return;
	else
	{
		_parentNode->makeConnection(arr);
	}
}
