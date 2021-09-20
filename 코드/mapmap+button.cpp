#include "stdafx.h"
#include "mapmap.h"

void mapmap::buttonSet()
{
	//지형 툴
	_btnPlay.rc = RectMake(_tool.terrain.rc.left + 35, _tool.terrain.rc.top + 291, 100, 26);
	_btnSave.rc = RectMake(_tool.terrain.rc.left + 168, _tool.terrain.rc.top + 290, 100, 26);
	_btnLoad.rc = RectMake(_tool.terrain.rc.left + 270, _tool.terrain.rc.top + 290, 100, 26);
	_btnMusic.rc = RectMake(_tool.terrain.rc.left + 372, _tool.terrain.rc.top + 290, 100, 26);
	
	for (int i = 0; i < MAPMAX; i++)
	{
		int num = i % 8;
		_btnMapList[i].img = IMAGEMANAGER->findImage("btnObjList");
		_btnMapList[i].rc = RectMake(_tool.terrain.rc.left + 40 + ((num / 8) * 100), _tool.terrain.rc.top + 40 + (num * 30), _btnMapList[i].img->getWidth(), _btnMapList[i].img->getHeight());
	}

	_btnMapList[0].name = "stage1";
	_btnMapList[1].name = "stage2";

	//옵젝 툴
	_btnObjPage.rc = RectMake(_tool.object.rc.left + 36, _tool.object.rc.top + 290, 100, 26);
	_btnObjSet.rc = RectMake(_tool.object.rc.left + 168, _tool.object.rc.top + 290, 100, 26);
	_btnEraser.rc = RectMake(_tool.object.rc.left + 270, _tool.object.rc.top + 290, 100, 26);
	_btnClear.rc = RectMake(_tool.object.rc.left + 372, _tool.object.rc.top + 290, 100, 26);

	_btnObjSelect.img = IMAGEMANAGER->findImage("btnWindow");
	_btnObjSelect.rc = RectMake(_tool.object.rc.left + 168, _tool.object.rc.top + 200, _btnObjSelect.img->getWidth(),_btnObjSelect.img->getHeight());
	_btnObjIV.rc = RectMake(_btnObjSelect.rc.left, _btnObjSelect.rc.top, _btnObjSelect.img->getWidth(),_btnObjSelect.img->getHeight()/6);
	_btnObjWALL.rc = RectMake(_btnObjSelect.rc.left, _btnObjSelect.rc.top+27, _btnObjSelect.img->getWidth(),_btnObjSelect.img->getHeight()/6);
	_btnObjPlayer.rc = RectMake(_btnObjSelect.rc.left, _btnObjSelect.rc.top+54, _btnObjSelect.img->getWidth(),_btnObjSelect.img->getHeight()/6);
	_btnObjObject.rc = RectMake(_btnObjSelect.rc.left, _btnObjSelect.rc.top+81, _btnObjSelect.img->getWidth(),_btnObjSelect.img->getHeight()/6);
	_btnObjEnemy.rc = RectMake(_btnObjSelect.rc.left, _btnObjSelect.rc.top+108, _btnObjSelect.img->getWidth(),_btnObjSelect.img->getHeight()/6);
	_btnObjNONE.rc = RectMake(_btnObjSelect.rc.left, _btnObjSelect.rc.top+ 135, _btnObjSelect.img->getWidth(),_btnObjSelect.img->getHeight()/6);
	
	for (int i = 0; i < OBJMAX; i++)
	{
		int num = i % 8;
		_btnObjList[i].img = IMAGEMANAGER->findImage("btnObjList");
		_btnObjList[i].rc = RectMake(_tool.object.rc.left + 40 + ((num / 8) * 100), _tool.object.rc.top + 40 + (num * 30), _btnObjList[i].img->getWidth(), _btnObjList[i].img->getHeight());
	}
	_btnObjList[0].name = "trap";
	_btnObjList[1].name = "torch";
	_btnObjList[2].name = "wood_door_L";
	_btnObjList[3].name = "wood_door_U";
	_btnObjList[4].name = "wood_door_LR";
	_btnObjList[5].name = "steel_door";
	_btnObjList[6].name = "box";
	_btnObjList[7].name = "s_twall1";
	_btnObjList[8].name = "s_twall2";
	_btnObjList[9].name = "steel_window";
	_btnObjList[10].name = "statue_L";
	_btnObjList[11].name = "statue_R";
	_btnObjList[12].name = "birth";
	_btnObjList[13].name = "e_birth0";
	_btnObjList[14].name = "e_birth_f";
	_btnObjList[15].name = "church_door";
	_btnObjList[16].name = "fly";
	_btnObjList[17].name = "church_bench0";
	_btnObjList[18].name = "church_bench1";
	_btnObjList[19].name = "church_bench2";
	_btnObjList[20].name = "church_bench3";
	_btnObjList[21].name = "church_bench4";
	_btnObjList[22].name = "church_bench5";
	_btnObjList[23].name = "church_bench6";
	_btnObjList[24].name = "church_bench7";
	_btnObjList[25].name = "corpse0";
	_btnObjList[26].name = "corpse1";
	_btnObjList[27].name = "windowLight_L";
	_btnObjList[28].name = "windowLight_R";
	_btnObjList[29].name = "playerr";
	_btnObjList[30].name = "anim";
	_btnObjList[31].name = "pool_cast";

	_btnObjList[0].imgType = S_TRAP;
	_btnObjList[1].imgType = S_TORCH;
	_btnObjList[2].imgType = S_DOOR_L;
	_btnObjList[3].imgType = S_DOOR;
	_btnObjList[4].imgType = S_DOOR_LR;
	_btnObjList[5].imgType = S_DOOR;
	_btnObjList[6].imgType = S_BOX;
	_btnObjList[7].imgType = NO_F;
	_btnObjList[8].imgType = NO_F;
	_btnObjList[9].imgType = NO_F;
	_btnObjList[10].imgType = S_STATUE_L;
	_btnObjList[11].imgType = S_STATUE_R;
	_btnObjList[12].imgType = S_STATUE_R;
	_btnObjList[13].imgType = S_B1_EFFECT;
	_btnObjList[14].imgType = S_B1_EFFECT;
	_btnObjList[15].imgType = S_DOOR_LR;
	_btnObjList[16].imgType = S_FLY;
	_btnObjList[17].imgType = NO_F;
	_btnObjList[18].imgType = NO_F;
	_btnObjList[19].imgType = NO_F;
	_btnObjList[20].imgType = NO_F;
	_btnObjList[21].imgType = NO_F;
	_btnObjList[22].imgType = NO_F;
	_btnObjList[23].imgType = NO_F;
	_btnObjList[24].imgType = NO_F;
	_btnObjList[25].imgType = NO_F;
	_btnObjList[26].imgType = NO_F;
	_btnObjList[27].imgType = NO_F;
	_btnObjList[28].imgType = NO_F;
	_btnObjList[29].imgType = NO_F;
	_btnObjList[30].imgType = S_TRAP;
	_btnObjList[31].imgType = S_TRAP;
}

void mapmap::buttonRender()
{
	if (_tool.TR_isOpen)
	{
		int num = (MAPMAX - (_tool.terrain.page * 8) < 8) ? MAPMAX : (_tool.terrain.page * 8) + 8;

		for (int i = (_tool.terrain.page * 8); i < num; i++)
		{
			_btnMapList[i].img->uiRender(true, _btnMapList[i].rc.left, _btnMapList[i].rc.top);

			D2DRENDER->RenderTextField(
				_btnMapList[i].rc.left, _btnMapList[i].rc.top,
				ConvertStoWS(_btnMapList[i].name),
				14,
				_btnMapList[i].rc.right - _btnMapList[i].rc.left, _btnMapList[i].rc.bottom - _btnMapList[i].rc.top,
				D2DDEFAULTBRUSH::White,
				DWRITE_TEXT_ALIGNMENT_CENTER,
				L"StoneshardFont_new");

			if (PtInRect(&_btnMapList[i].rc, _ptMouse)) D2DRENDER->DrawRectangle(_btnMapList[i].rc, true, D2DDEFAULTBRUSH::White);
			else  D2DRENDER->DrawRectangle(_btnMapList[i].rc, true);
		}

		D2DRENDER->RenderTextField(
			_btnPlay.rc.left, _btnPlay.rc.top,
			L"PLAY",
			14,
			_btnPlay.rc.right - _btnPlay.rc.left, _btnPlay.rc.bottom - _btnPlay.rc.top,
			D2DDEFAULTBRUSH::White,
			DWRITE_TEXT_ALIGNMENT_CENTER,
			L"StoneshardFont_new");

		D2DRENDER->RenderTextField(
			_btnSave.rc.left, _btnSave.rc.top,
			L"Save",
			14,
			_btnSave.rc.right - _btnSave.rc.left, _btnSave.rc.bottom - _btnSave.rc.top,
			D2DDEFAULTBRUSH::White,
			DWRITE_TEXT_ALIGNMENT_CENTER,
			L"StoneshardFont_new");

		D2DRENDER->RenderTextField(
			_btnLoad.rc.left, _btnLoad.rc.top,
			L"Load",
			14,
			_btnLoad.rc.right - _btnLoad.rc.left, _btnLoad.rc.bottom - _btnLoad.rc.top,
			D2DDEFAULTBRUSH::White,
			DWRITE_TEXT_ALIGNMENT_CENTER,
			L"StoneshardFont_new");

		D2DRENDER->RenderTextField(
			_btnMusic.rc.left, _btnMusic.rc.top,
			L"MusicSet",
			14,
			_btnMusic.rc.right - _btnMusic.rc.left, _btnMusic.rc.bottom - _btnMusic.rc.top,
			D2DDEFAULTBRUSH::White,
			DWRITE_TEXT_ALIGNMENT_CENTER,
			L"StoneshardFont_new");

		if (PtInRect(&_btnPlay.rc, _ptMouse)) D2DRENDER->DrawRectangle(_btnPlay.rc, true, D2DDEFAULTBRUSH::White);
		else  D2DRENDER->DrawRectangle(_btnPlay.rc, true);

		if (PtInRect(&_btnSave.rc, _ptMouse)) D2DRENDER->DrawRectangle(_btnSave.rc, true, D2DDEFAULTBRUSH::White);
		else  D2DRENDER->DrawRectangle(_btnSave.rc, true);

		if (PtInRect(&_btnLoad.rc, _ptMouse)) D2DRENDER->DrawRectangle(_btnLoad.rc, true, D2DDEFAULTBRUSH::White);
		else  D2DRENDER->DrawRectangle(_btnLoad.rc, true);

		if (PtInRect(&_btnMusic.rc, _ptMouse)) D2DRENDER->DrawRectangle(_btnMusic.rc, true, D2DDEFAULTBRUSH::White);
		else  D2DRENDER->DrawRectangle(_btnMusic.rc, true);

	}

	if (_tool.OBJ_isOpen)
	{
		int num = (OBJMAX - (_tool.object.page * 8) < 8) ? OBJMAX : (_tool.object.page * 8) + 8;

		for (int i = (_tool.object.page * 8); i < num; i++)
		{
			_btnObjList[i].img->uiRender(true, _btnObjList[i].rc.left, _btnObjList[i].rc.top);

			D2DRENDER->RenderTextField(
				_btnObjList[i].rc.left, _btnObjList[i].rc.top,
				ConvertStoWS(_btnObjList[i].name),
				14,
				_btnObjList[i].rc.right - _btnObjList[i].rc.left, _btnObjList[i].rc.bottom - _btnObjList[i].rc.top,
				D2DDEFAULTBRUSH::White,
				DWRITE_TEXT_ALIGNMENT_CENTER,
				L"StoneshardFont_new");

			if (PtInRect(&_btnObjList[i].rc, _ptMouse)) D2DRENDER->DrawRectangle(_btnObjList[i].rc, true, D2DDEFAULTBRUSH::White);
			else  D2DRENDER->DrawRectangle(_btnObjList[i].rc, true);
		}

		D2DRENDER->RenderTextField(
			_btnObjPage.rc.left, _btnObjPage.rc.top,
			L"NEXT",
			14,
			_btnObjPage.rc.right - _btnObjPage.rc.left, _btnObjPage.rc.bottom - _btnObjPage.rc.top,
			D2DDEFAULTBRUSH::White,
			DWRITE_TEXT_ALIGNMENT_CENTER,
			L"StoneshardFont_new");

		D2DRENDER->RenderTextField(
			_btnObjSet.rc.left, _btnObjSet.rc.top,
			L"tileTypeSet",
			14,
			_btnObjSet.rc.right - _btnObjSet.rc.left, _btnObjSet.rc.bottom - _btnObjSet.rc.top,
			D2DDEFAULTBRUSH::White,
			DWRITE_TEXT_ALIGNMENT_CENTER,
			L"StoneshardFont_new");

		D2DRENDER->RenderTextField(
			_btnEraser.rc.left, _btnEraser.rc.top,
			L"Eraser",
			14,
			_btnEraser.rc.right - _btnEraser.rc.left, _btnEraser.rc.bottom - _btnEraser.rc.top,
			D2DDEFAULTBRUSH::White,
			DWRITE_TEXT_ALIGNMENT_CENTER,
			L"StoneshardFont_new");

		D2DRENDER->RenderTextField(
			_btnClear.rc.left, _btnClear.rc.top,
			L"Clear",
			14,
			_btnClear.rc.right - _btnClear.rc.left, _btnClear.rc.bottom - _btnClear.rc.top,
			D2DDEFAULTBRUSH::White,
			DWRITE_TEXT_ALIGNMENT_CENTER,
			L"StoneshardFont_new");

		if (_btnObjSet.click)
		{
			_btnObjSelect.img->uiRender(true,_btnObjSelect.rc.left, _btnObjSelect.rc.top);

			if (PtInRect(&_btnObjIV.rc, _ptMouse)) D2DRENDER->DrawRectangle(_btnObjIV.rc, true, D2DDEFAULTBRUSH::White);
			if (PtInRect(&_btnObjWALL.rc, _ptMouse)) D2DRENDER->DrawRectangle(_btnObjWALL.rc, true, D2DDEFAULTBRUSH::White);
			if (PtInRect(&_btnObjPlayer.rc, _ptMouse)) D2DRENDER->DrawRectangle(_btnObjPlayer.rc, true, D2DDEFAULTBRUSH::White);
			if (PtInRect(&_btnObjObject.rc, _ptMouse)) D2DRENDER->DrawRectangle(_btnObjObject.rc, true, D2DDEFAULTBRUSH::White);
			if (PtInRect(&_btnObjEnemy.rc, _ptMouse)) D2DRENDER->DrawRectangle(_btnObjEnemy.rc, true, D2DDEFAULTBRUSH::White);
			if (PtInRect(&_btnObjNONE.rc, _ptMouse)) D2DRENDER->DrawRectangle(_btnObjNONE.rc, true, D2DDEFAULTBRUSH::White);

			D2DRENDER->RenderTextField(
				_btnObjIV.rc.left, _btnObjIV.rc.top,
				L"invisible Type",
				14,
				_btnObjIV.rc.right - _btnObjIV.rc.left, _btnObjIV.rc.bottom - _btnObjIV.rc.top,
				D2DDEFAULTBRUSH::White,
				DWRITE_TEXT_ALIGNMENT_CENTER,
				L"StoneshardFont_new");

			D2DRENDER->RenderTextField(
				_btnObjWALL.rc.left, _btnObjWALL.rc.top,
				L"wall Type",
				14,
				_btnObjWALL.rc.right - _btnObjWALL.rc.left, _btnObjWALL.rc.bottom - _btnObjWALL.rc.top,
				D2DDEFAULTBRUSH::White,
				DWRITE_TEXT_ALIGNMENT_CENTER,
				L"StoneshardFont_new");

			D2DRENDER->RenderTextField(
				_btnObjPlayer.rc.left, _btnObjPlayer.rc.top,
				L"player Type",
				14,
				_btnObjPlayer.rc.right - _btnObjPlayer.rc.left, _btnObjPlayer.rc.bottom - _btnObjPlayer.rc.top,
				D2DDEFAULTBRUSH::White,
				DWRITE_TEXT_ALIGNMENT_CENTER,
				L"StoneshardFont_new");

			D2DRENDER->RenderTextField(
				_btnObjObject.rc.left, _btnObjObject.rc.top,
				L"object Type",
				14,
				_btnObjObject.rc.right - _btnObjObject.rc.left, _btnObjObject.rc.bottom - _btnObjObject.rc.top,
				D2DDEFAULTBRUSH::White,
				DWRITE_TEXT_ALIGNMENT_CENTER,
				L"StoneshardFont_new");

			D2DRENDER->RenderTextField(
				_btnObjEnemy.rc.left, _btnObjEnemy.rc.top,
				L"enemy Type",
				14,
				_btnObjEnemy.rc.right - _btnObjEnemy.rc.left, _btnObjEnemy.rc.bottom - _btnObjEnemy.rc.top,
				D2DDEFAULTBRUSH::White,
				DWRITE_TEXT_ALIGNMENT_CENTER,
				L"StoneshardFont_new");
			
			D2DRENDER->RenderTextField(
				_btnObjNONE.rc.left, _btnObjNONE.rc.top,
				L"none Type",
				14,
				_btnObjNONE.rc.right - _btnObjNONE.rc.left, _btnObjNONE.rc.bottom - _btnObjNONE.rc.top,
				D2DDEFAULTBRUSH::White,
				DWRITE_TEXT_ALIGNMENT_CENTER,
				L"StoneshardFont_new");
		}
		else
		{
			if (PtInRect(&_tool.object.objRc, _ptMouse)) D2DRENDER->DrawRectangle(_tool.object.objRc, true, D2DDEFAULTBRUSH::White);
			else  D2DRENDER->DrawRectangle(_tool.object.objRc, true);

			if (PtInRect(&_btnObjPage.rc, _ptMouse)) D2DRENDER->DrawRectangle(_btnObjPage.rc, true, D2DDEFAULTBRUSH::White);
			else  D2DRENDER->DrawRectangle(_btnObjPage.rc, true);

			if (PtInRect(&_btnObjSet.rc, _ptMouse)) D2DRENDER->DrawRectangle(_btnObjSet.rc, true, D2DDEFAULTBRUSH::White);
			else  D2DRENDER->DrawRectangle(_btnObjSet.rc, true);

			if (PtInRect(&_btnEraser.rc, _ptMouse)) D2DRENDER->DrawRectangle(_btnEraser.rc, true, D2DDEFAULTBRUSH::White);
			else  D2DRENDER->DrawRectangle(_btnEraser.rc, true);

			if (PtInRect(&_btnClear.rc, _ptMouse)) D2DRENDER->DrawRectangle(_btnClear.rc, true, D2DDEFAULTBRUSH::White);
			else  D2DRENDER->DrawRectangle(_btnClear.rc, true);
		}
	}

}

void mapmap::buttonControl()
{
	if (_tool.TR_isOpen)
	{
		//맵 선택 버튼
		int num = (MAPMAX - (_tool.terrain.page * 8) < 8) ? MAPMAX : (_tool.terrain.page * 8) + 8;

		for (int i = (_tool.terrain.page * 8); i < num; i++)
		{
			if (PtInRect(&_btnMapList[i].rc, _ptMouse))
			{
				if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
				{
					clear();
					_currentMap = _btnMapList[i].name;
					_map = IMAGEMANAGER->findImage(_currentMap);

					string arr = _currentMap;
					arr.append("Tile");
					_sampleImg = IMAGEMANAGER->findImage(arr);
				}
			}
		}
		//페이지 버튼
		//세이브 버튼
		if (PtInRect(&_btnSave.rc, _ptMouse))
		{
			if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
			{
				save();
			}
		}
		//로드 버튼
		if (PtInRect(&_btnLoad.rc, _ptMouse))
		{
			if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
			{
				load();
			}
		}
		//플레이 버튼
		if (PtInRect(&_btnPlay.rc, _ptMouse))
		{
			if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
			{
				SCENEMANAGER->changeScene(_currentMap);
			}
		}
	}
	if (_tool.OBJ_isOpen)
	{
		int num = (OBJMAX - (_tool.object.page * 8) < 8) ? OBJMAX : (_tool.object.page * 8) + 8;

		for (int i = (_tool.object.page * 8); i < num; i++)
		{
			if (PtInRect(&_btnObjList[i].rc, _ptMouse))
			{
				if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
				{
					_object.img = IMAGEMANAGER->findImage(_btnObjList[i].name);
					_object.name = _btnObjList[i].name;
					_object.imgType = _btnObjList[i].imgType;
					_currentObj.frameX = imgFrameSelect(_btnObjList[i].imgType);
				}
			}
		}
		//이미지 선택
		if (PtInRect(&_tool.object.objRc, _ptMouse) && !_btnObjSet.click)
		{
			if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
			{
				_ctrlSelect = CTRL_OBJDRAW;

				_currentObj.img = _object.img;
				_currentObj.type = _object.imgType;
				_currentObj.name = _object.name;
			}
		}
		//페이지 버튼
		if (PtInRect(&_btnObjPage.rc, _ptMouse))
		{
			if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
			{
				_tool.object.page++;
				if (_tool.object.page >= _tool.object.pageMax)_tool.object.page = 0;
				cout << _tool.object.page << endl;
			}
		}
		//타일설정 버튼
		if (PtInRect(&_btnObjSet.rc, _ptMouse))
		{
			if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
			{
				if(_btnObjSet.click) _btnObjSet.click = false;
				else _btnObjSet.click = true;
			}
		}
		if (_btnObjSet.click)
		{
			if (PtInRect(&_btnObjIV.rc, _ptMouse))
			{
				if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
				{
					_ctrlSelect = CTRL_TILESET_IV;
					_btnObjSet.click = false;
				}
			}
			if (PtInRect(&_btnObjWALL.rc, _ptMouse))
			{
				if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
				{
					_ctrlSelect = CTRL_TILESET_WALL;
					_btnObjSet.click = false;
				}
			}
			if (PtInRect(&_btnObjPlayer.rc, _ptMouse))
			{
				if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
				{
					_ctrlSelect = CTRL_TILESET_PLAYER;
					_btnObjSet.click = false;
				}
			}
			if (PtInRect(&_btnObjObject.rc, _ptMouse))
			{
				if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
				{
					_ctrlSelect = CTRL_TILESET_OBJECT;
					_btnObjSet.click = false;
				}
			}
			if (PtInRect(&_btnObjEnemy.rc, _ptMouse))
			{
				if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
				{
					_ctrlSelect = CTRL_TILESET_ENEMY;
					_btnObjSet.click = false;
				}
			}
			if (PtInRect(&_btnObjNONE.rc, _ptMouse))
			{
				if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
				{
					_ctrlSelect = CTRL_TILESET_NONE;
					_btnObjSet.click = false;
				}
			}
		}
		//지우개 버튼
		if (PtInRect(&_btnEraser.rc, _ptMouse))
		{
			if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
			{
				_ctrlSelect = CTRL_ERASER;
			}
		}
		//클리어 버튼
		if (PtInRect(&_btnClear.rc, _ptMouse))
		{
			if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
			{
				clear();
			}
		}
	}
}
