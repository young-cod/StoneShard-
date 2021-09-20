#pragma once
#include "tileInfo.h"

class stage1;
class stage2;

class aStar
{
public:
	typedef struct tagNode {
		int x;
		int y;
		float g;
		float h;
		float f;
		bool isClose;
		tagNode* parentNode;
		bool operator == (tagNode right)
		{
			return (x == right.x && y == right.y);
		}
	}NODE;

private:
	vector<NODE*> _openList;
	vector<NODE*> _closeList;
	NODE* _curNode;
	NODE* _endNode;
	NODE* _startNode;
	bool _isLand;
	float _delay;

	string _currentScene;

public:
	void init(string scene);
	stage1* stage1;
	stage2* stage2;
	vector<pair<int, int>> PathFind(int startX, int startY, int endX, int endY);
	void Clear();
	void AddOpenList(NODE* node);
	bool IsExistCloseList(int x, int y);
	int IsExistOpenList(int x, int y);
	bool IsValidNode(int x, int y);
	int GetMinOpenListNode();
	void SortOpenList();
	float CalcG(int startX, int startY, int endX, int endY);
};
