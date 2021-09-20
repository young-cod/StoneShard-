#include "stdafx.h"
#include "uiManager.h"
#include "playerManager.h"

HRESULT uiManager::init()
{
	imageSet();
	setup();

	return S_OK;
}

void uiManager::release()
{
}

void uiManager::update()
{
	buttonControl();
}

void uiManager::render()
{
	buttonRender();
	_noabilities.img->uiRender(true, _noabilities.rc.left, _noabilities.rc.top);
}

void uiManager::setup()
{
	_player = new playerManager;
	_player->init();
}

void uiManager::imageSet()
{
	IMAGEMANAGER->addImage("ui_noabilities", L"image/UI/abilities/s_ui_noabilities.png");
	
	_noabilities.img = IMAGEMANAGER->findImage("ui_noabilities");
	_noabilities.rc = RectMakeCenter(WINSIZEX / 2, WINSIZEY - _noabilities.img->getHeight() / 2 - 3, _noabilities.img->getWidth(), _noabilities.img->getHeight());

	buttonSet();

	//캐릭터 메뉴 (바디)
	IMAGEMANAGER->addImage("s_body", L"image/UI/character_menu/s_character_skeleton_body.png");
	IMAGEMANAGER->addImage("ui_character_menu2_line", L"image/UI/character_menu/characterMenu2_line.png");
	_characterMenu.line = IMAGEMANAGER->findImage("ui_character_menu2_line");
	_character_body.img = IMAGEMANAGER->findImage("s_body");
	_character_body.rc = RectMake(28, 292, _character_body.img->getWidth(), _character_body.img->getHeight());
}
