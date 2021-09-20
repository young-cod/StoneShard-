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
	//F == �� �Ÿ� ��� (TotalCost)
	//G == ���������κ��� ���� ������ ��κ��(CostFromStart)
	//H == ������κ��� ���������� ��κ��(CostToGoal)

	float _totalCost;
	float _costFromStart;
	float _costToGoal;

	bool _isOpen;//�����ִ� Ÿ������ ����

	tileInfo* _parentNode; //���� ���� Ÿ�� (��� ���ŵǴ� Ÿ��)

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

	//============ ���� ���� ������ & ������ ===============
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

