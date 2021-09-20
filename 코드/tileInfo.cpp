#include "stdafx.h"
#include "tileInfo.h"
#include "aStar.h"

//¸â¹ö ÀÌ´Ï¼È¶óÀÌÁî
tileInfo::tileInfo()
	: _totalCost(0), _costFromStart(0),
	_costToGoal(0), _parentNode(NULL),
	_idX(0), _idY(0), _isOpen(true)
{
}


tileInfo::~tileInfo()
{

}

HRESULT tileInfo::init(int idX, int idY)
{
	
	_center = PointMake(idX * TILEWIDTH + (TILEWIDTH / 2),
		idY * TILEHEIGHT + (TILEHEIGHT / 2));

	_color = D2D1COLOR::Green;

	_idX = idX;
	_idY = idY;
	_rc = RectMakeCenter(_center.x, _center.y, TILEWIDTH, TILEHEIGHT);

	return S_OK;
}

void tileInfo::release()
{

}

void tileInfo::update()
{

}

void tileInfo::render()
{
	D2DRENDER->FillRectangle(_rc, _color ,1.f);

	D2DRENDER->DrawRectangle(_rc, _color);
}
