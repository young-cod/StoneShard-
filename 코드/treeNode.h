#pragma once

#define SIZE_ARR_X 50
#define SIZE_ARR_Y 50


struct tagMatrix
{
	float x, y;
	float width, height;

	tagMatrix(float _x, float _y, float _width, float _height)
	{
		x = _x, y = _y, width = _width, height = _height;
	}
	tagMatrix() {};
	~tagMatrix() {};
};

struct tagPass
{
	int type;
	int x, y;
};

enum DIRECTION
{
	VERTICAL,
	HORIZONTAL
};

class treeNode
{
private:
	treeNode* _leftNode;
	treeNode* _rightNode;
	treeNode* _parentNode;

	tagMatrix _info;
	tagMatrix _roomInfo;

	int _direction;
	bool _connect;

public:
	void makeLeftTree(treeNode *sub)
	{
		if (this->_leftNode != NULL)
		{
			this->_leftNode = NULL;
		}
		this->_leftNode = sub;
	}
	void makeRightTree(treeNode* sub)
	{
		if (this->_rightNode != NULL)
		{
			this->_rightNode = NULL;
		}
		this->_rightNode = sub;
	}

	void		makeConnection(int(*arr)[SIZE_ARR_X]);
	void		setInfo(tagMatrix sub) { _info = sub; }
	void		setParentNode(treeNode* sub) { _parentNode = sub; }
	void		setDirection(int dir) { _direction = dir; }
	void		setRoomInfo(tagMatrix sub) { _roomInfo = sub; }
	int			getDirection() { return _direction; }
	bool		getConnect() { return _connect; }

	tagMatrix	getRoomInfo() { return _roomInfo; }
	tagMatrix	getInfo() { return _info; }

	treeNode*	getParentNode() { return _parentNode; }
	treeNode*	getLeftNode() { return _leftNode; }
	treeNode*	getRightNode() { return _rightNode; }

	treeNode()
	{
		_connect = false;
		_leftNode = nullptr;
		_rightNode = nullptr;
		_parentNode = nullptr;
	}
};