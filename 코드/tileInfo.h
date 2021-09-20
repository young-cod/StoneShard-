#pragma once
#include "gameNode.h"

#define TILEWIDTH 26
#define TILEHEIGHT 26

class tileInfo : public gameNode
{
private:
	int _idX;
	int _idY;

	POINT _center;
	RECT _rc;

	//F = G + H 
	//F == 총 거리 비용 (TotalCost)
	//G == 시작점으로부터 현재 노드까지 경로비용(CostFromStart)
	//H == 현재노드로부터 도착점까지 경로비용(CostToGoal)

	float _totalCost;
	float _costFromStart;
	float _costToGoal;

	bool _isOpen;//갈수있는 타일인지 유무

	tileInfo* _parentNode; //제일 상위 타일 (계속 갱신되는 타일)

	D2D1::ColorF::Enum _color;

	string _attribute;
public:
	tileInfo();
	~tileInfo();

	HRESULT init(int idX, int idY);
	void release();
	void update();
	void render();

	int getIdX() { return _idX; }
	int getIdY() { return _idY; }

	void setColor(D2D1::ColorF::Enum color)
	{
		_color = color;
	}

	RECT getRect() { return _rc; }

	//============ 편리를 위한 접근자 & 설정자 ===============
	void setCenter(POINT center) { _center = center; }
	POINT getCenter() { return _center; }

	void setAttribute(string str) { _attribute = str; }
	string getAttribute() { return _attribute; }

	void setTotalCost(float totalCost) { _totalCost = totalCost; }
	float getTotalCost() { return _totalCost; }

	void setCostFromStart(float costFromStart) { _costFromStart = costFromStart; }
	float getCostFromStart() { return _costFromStart; }


	void setCostToGoal(float costToGoal) { _costToGoal = costToGoal; }
	float getCostToGoal() { return _costToGoal; }

	void setParentNode(tileInfo* t) { _parentNode = t; }
	tileInfo* getParentNode() { return _parentNode; }

	void setIsOpen(bool isOpen) { _isOpen = isOpen; }
	bool getIsOpen() { return _isOpen; }

	void setIdX(int x) { _idX = x; }
	void setIdY(int y) { _idY = y; }
};

