#include "stdafx.h"
#include "mouseManager.h"

HRESULT mouseManager::init()
{
	imageSet();

	_mouse = IMAGEMANAGER->findImage("mouse_basic");
	_area = IMAGEMANAGER->findImage("mouse_area");

	return S_OK;
}

void mouseManager::release()
{
}

void mouseManager::update()
{
	if (CAMERAMANAGER->getIsZoom())
	{
		_xyMouse.x = _ptMouse.x /1.5 + CAMERAMANAGER->getX();
		_xyMouse.y = _ptMouse.y /1.5 + CAMERAMANAGER->getY();
	}
	else
	{
		_xyMouse.x = _ptMouse.x + CAMERAMANAGER->getX();
		_xyMouse.y = _ptMouse.y + CAMERAMANAGER->getY();
	}
}

void mouseManager::render()
{
	_mouse->render(_ptMouse.x, _ptMouse.y);
	_area->uiRender_F(false,_xyMouse.x /26* 26, _xyMouse.y / 26 * 26, _area->getFrameX(), _area->getFrameY(), _area->getFrameWidth(), _area->getFrameHeight());
}

void mouseManager::imageSet()
{
	IMAGEMANAGER->addImage("mouse_basic", L"image/UI/cursor/basic.png");
	IMAGEMANAGER->addImage("mouse_battle", L"image/UI/cursor/battle.png");
	IMAGEMANAGER->addImage("mouse_door", L"image/UI/cursor/s_cursor_door_0.png");
	IMAGEMANAGER->addImage("mouse_hand", L"image/UI/cursor/s_cursor_hand_0.png");
	IMAGEMANAGER->addFrameImage("mouse_area", L"image/inGame/stage1/cursor_area_2x1.png", 2, 1);
}

void mouseManager::click()
{

}
