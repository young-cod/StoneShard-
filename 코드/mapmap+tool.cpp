#include "stdafx.h"
#include "mapmap.h"

void mapmap::openTool()
{
	//지형	
	if (KEYMANAGER->isOnceKeyDown('O'))
	{
		if (_tool.TR_isOpen)_tool.TR_isOpen = false;
		else
		{
			_ctrlSelect = CTRL_TERRAINDRAW;
			_tool.TR_isOpen = true;
		}
	}
	if (KEYMANAGER->isOnceKeyDown('P'))
	{
		if (_tool.OBJ_isOpen)_tool.OBJ_isOpen = false;
		else
		{
			_tool.OBJ_isOpen = _tool.OBJ_isOpen = true;
		}
	}
	
	if (_tool.TR_isOpen)dragField();
	buttonControl();
	//오브젝트	
}

void mapmap::dragField()
{
	for (int i = 0; i < SAMPLETILEX*SAMPLETILEY; i++)
	{
		if (PtInRect(&_sampleTile[i].rc, _ptMouse))
		{
			if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
			{

				_dragMouse.start.x = _sampleTile[i].rc.left;
				_dragMouse.start.y = _sampleTile[i].rc.top;
				_dragMouse.currentStartX = _sampleTile[i].frameX;
				_dragMouse.currentStartY = _sampleTile[i].frameY;
			}
			if (_leftButtonDown)
			{
				_dragMouse.end.x = _sampleTile[i].rc.right;
				_dragMouse.end.y = _sampleTile[i].rc.bottom;
				_dragMouse.currentEndX = _sampleTile[i].frameX;
				_dragMouse.currentEndY = _sampleTile[i].frameY;
			}
			if (KEYMANAGER->isOnceKeyUp(VK_LBUTTON))
			{
				_dragMouse.end.x = _sampleTile[i].rc.right;
				_dragMouse.end.y = _sampleTile[i].rc.bottom;
				_dragMouse.currentEndX = _sampleTile[i].frameX;
				_dragMouse.currentEndY = _sampleTile[i].frameY;
			}
			_dragMouse.rc = RectMakeDrag(_dragMouse.start.x, _dragMouse.start.y, _dragMouse.end.x, _dragMouse.end.y);
			if (_dragMouse.rc.right - _dragMouse.rc.left > TILESIZEX || 
				_dragMouse.rc.bottom - _dragMouse.rc.top > TILESIZEY)_dragMouse.isDrag = true;
			else _dragMouse.isDrag = false;
		}
	}
}
