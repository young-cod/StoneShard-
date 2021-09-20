#include "stdafx.h"
#include "aStar.h"
#include "stage1.h"
#include "stage2.h"
/*******************************************************************
* A* �˰��� �⺻ ����
* 1.���۳��, ����� ���ϱ�
* 2.���۳�带 ��������Ʈ�� �߰�
* 3.��������Ʈ���� f���� ���� ���� ��带 �ϳ� ������
* 4. 3������ ������ ��尡 ������ ������ �˻�
* 5. 4������ ������ ������ �˰����� ����
* 6. 4������ �ٸ��� ���� ��忡�� �ֺ� ����� g, h, f���� ����Ͽ� ��������Ʈ�� �߰�
* 6-1. ��������Ʈ�� �̹� �ִ� ���� �߰����� �ʴ´�
* 6-2. �̹� ��������Ʈ�� ���� ��� f���� �� ������ �����Ѵ�.
* 6-3. �̹� ��������Ʈ�� ���� ��� ���� ��������Ʈ�� �߰��Ѵ�
* 7. 5���� �ɶ����� �ݺ�
* 8. ��������Ʈ�� ��尡 �� 1�������ٸ� ���Ž�� ����
*
* ���̽�Ÿ���� ����ϴ� ������ �������� ��
* x, y, f, g, h, parentNode
********************************************************************/

void aStar::init(string scene)
{
	_currentScene = scene;
}

vector<pair<int, int>> aStar::PathFind(int startX, int startY, int endX, int endY)
{
	vector<pair<int, int>> result;
	Clear();
	_delay = 0;
	_isLand = true;
	_startNode = new NODE();
	_startNode->x = startX;
	_startNode->y = startY;
	_startNode->parentNode = nullptr;
	
	_endNode = new NODE();
	_endNode->x = endX;
	_endNode->y = endY;
	_endNode->parentNode = nullptr;

	_openList.push_back(_startNode);

	while (_openList.empty() == false)
	{
		NODE *curNode;
		int minIdx = GetMinOpenListNode();
		curNode = _openList[minIdx];
		_openList.erase(_openList.begin() + minIdx);
		if (curNode->x == _endNode->x && curNode->y == _endNode->y)
		{
			while (curNode->parentNode != nullptr)
			{
				result.push_back({ curNode->x, curNode->y });
				curNode = curNode->parentNode;
			}
			return result;
		}

		_closeList.push_back(curNode);
		AddOpenList(curNode);
	}

	return result;
}

void aStar::Clear()
{
	for (int i = 0; i < _openList.size(); i++)
	{
		SAFE_DELETE(_openList[i]);
	}
	for (int i = 0; i < _closeList.size(); i++)
	{
		SAFE_DELETE(_closeList[i]);
	}
	_openList.clear();
	_closeList.clear();
	vector<NODE*>().swap(_openList);
	vector<NODE*>().swap(_closeList);
}

void aStar::AddOpenList(NODE* node)
{
	int startX = node->x - 1;
	int startY = node->y - 1;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{

			int curX = startX + i;
			int curY = startY + j;
			if (IsValidNode(curX, curY) == false) continue;
			if (curX < 0 || curX == 50 || curY < 0 || curY == 50) continue;
			if (IsExistCloseList(curX, curY) == true) continue;

			float h = GetDistanceM(_endNode->x, _endNode->y, curX, curY);
			float g = node->g + CalcG(node->x, node->y, curX, curY);
			float f = h + g;
			int openListIdx = IsExistOpenList(curX, curY);
			if (openListIdx != -1)
			{
				if (_openList[openListIdx]->f > f)
				{
					_openList[openListIdx]->f = f;
					_openList[openListIdx]->g = g;
					_openList[openListIdx]->h = h;
					_openList[openListIdx]->parentNode = node;
				}
			}
			else
			{
				NODE* newNode = new NODE();
				newNode->x = curX;
				newNode->y = curY;
				newNode->g = g;
				newNode->h = h;
				newNode->f = f;
				newNode->parentNode = node;
				_openList.push_back(newNode);
			}
		}
	}
}

bool aStar::IsExistCloseList(int x, int y)
{
	for (int i = 0; i < _closeList.size(); i++)
	{
		if (_closeList[i]->x == x && _closeList[i]->y == y)
		{
			return true;
		}
	}
	return false;
}

int aStar::IsExistOpenList(int x, int y)
{
	for (int i = 0; i < _openList.size(); i++)
	{
		if (_openList[i]->x == x && _openList[i]->y == y)
		{
			return i;
		}
	}
	return -1;
}

bool aStar::IsValidNode(int x, int y)
{
	if(_currentScene == "stage1")return stage1->isValidTile(x, y);
	else if(_currentScene == "stage2") return stage2->isValidTile(x, y);
}

int aStar::GetMinOpenListNode()
{
	int idx = -1;
	float f = 5000;
	for (int i = 0; i < _openList.size(); i++)
	{
		if (f > _openList[i]->f)
		{
			idx = i;
			f = _openList[i]->f;
		}
	}
	return idx;
}


void aStar::SortOpenList()
{
}

float aStar::CalcG(int startX, int startY, int endX, int endY)
{
	int deltaX = startX - endX;
	int deltaY = startY - endY;
	float result = sqrt(deltaX * deltaX + deltaY * deltaY);
	return result;
}