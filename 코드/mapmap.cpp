#include "stdafx.h"
#include "mapmap.h"

HRESULT mapmap::init()
{
	setup();

	sCount = 0;
	poolC = 0;
	return S_OK;
}

void mapmap::release()
{
}

void mapmap::update()
{
	cameraControl();
	openTool();
	setMap();
	objectFrame();
	mouseDetailControl();
	light->setAlpha(light->getAlpha() - 0.0015f);
	if (light->getAlpha() <= 0.2f)light->setAlpha(0.3f);


	//==========================================
	/*sCount++;
	if (sCount % 4== 0)
	{
		sCount = 0;
		statueEffect->setFrameX(statueEffect->getFrameX() + 1);
		if (statueEffect->getFrameX() >= statueEffect->getMaxFrameX())
		{
			poolC++;
			if(poolC==1)statueEffect = IMAGEMANAGER->findImage("healundead");
			else if(poolC==2)statueEffect = IMAGEMANAGER->findImage("spawnundead");
			else if(poolC==3)statueEffect = IMAGEMANAGER->findImage("arrow_hit");
			else if(poolC==4)statueEffect = IMAGEMANAGER->findImage("pool_cast");
			if (poolC <= 4)statueEffect->setFrameX(0);
			else statueEffect->setFrameX(statueEffect->getMaxFrameX());
		}
	}*/
}

void mapmap::render()
{
	//맵 관련
	_map->mapRender(0, 0);
	//맵 타일
	for (int i = 0; i < TILEX*TILEY; ++i)
	{
		if (_tile[i].terrain == TR_INVISIBLE)_sampleImg->cutRender(_tile[i].rc.left, _tile[i].rc.top, _tile[i].terrainX, _tile[i].terrainY, _tile[i].sizeX, _tile[i].sizeY, 0.5f);
		else _sampleImg->cutRender(_tile[i].rc.left, _tile[i].rc.top, _tile[i].terrainX, _tile[i].terrainY, _tile[i].sizeX, _tile[i].sizeY);

	}
	//오브젝트
	for (int i = 0; i < _vObjList.size(); i++)
	{
		if (_vObjList.empty())return;
		if (_vObjList[i].type == NO_F)_vObjList[i].img->objRender(_vObjList[i].x, _vObjList[i].y, true);
		else _vObjList[i].img->objRender_F(_vObjList[i].x, _vObjList[i].y,
			_vObjList[i].frameX, _vObjList[i].img->getFrameY(),
			_vObjList[i].img->getFrameWidth(), _vObjList[i].img->getFrameHeight());
	}
	//격자
	if (KEYMANAGER->isToggleKey(VK_TAB))
		for (int i = 0; i < TILEX* TILEY; ++i)
		{
			if (_tile[i].terrain == TR_INVISIBLE)D2DRENDER->DrawRectangle(_tile[i].rc, false, D2DDEFAULTBRUSH::Blue, 0.5f);
			else if (_tile[i].terrain == TR_WALL) D2DRENDER->DrawRectangle(_tile[i].rc, false, D2DDEFAULTBRUSH::Red, 0.5f);
			else if (_tile[i].terrain == TR_PLAYER)D2DRENDER->DrawRectangle(_tile[i].rc, false, D2DDEFAULTBRUSH::Yellow, 2.5f);
			else if (_tile[i].terrain == TR_OBJ)D2DRENDER->DrawRectangle(_tile[i].rc, false, D2DDEFAULTBRUSH::Green, 2.5f);
			else if (_tile[i].terrain == TR_ENEMY)D2DRENDER->DrawRectangle(_tile[i].rc, false, D2DDEFAULTBRUSH::Purple, 2.5f);
			else D2DRENDER->DrawRectangle(_tile[i].rc, false, D2DDEFAULTBRUSH::White, 0.1f);
		}

	//툴 관련
	if (_tool.TR_isOpen)
	{
		_tool.terrain.img->uiRender(true,_tool.terrain.rc.left, _tool.terrain.rc.top);
		for (int i = 0; i < SAMPLETILEX*SAMPLETILEY; ++i)
		{
			_sampleImg->uiRender_F(true, _sampleTile[i].rc.left, _sampleTile[i].rc.top,
				_sampleTile[i].frameX, _sampleTile[i].frameY,
				_sampleImg->getFrameWidth(), _sampleImg->getFrameHeight());
			if (PtInRect(&_sampleTile[i].rc, _ptMouse))D2DRENDER->DrawRectangle(_sampleTile[i].rc, true, D2DDEFAULTBRUSH::White);
			else D2DRENDER->DrawRectangle(_sampleTile[i].rc, true, D2DDEFAULTBRUSH::Black);
		}
		D2DRENDER->DrawRectangle(_dragMouse.rc, true, D2DDEFAULTBRUSH::White, 2.f);
	}

	if (_tool.OBJ_isOpen)
	{
		_tool.object.img->uiRender(true, _tool.object.rc.left, _tool.object.rc.top);

		if (_object.imgType == NO_F) _object.img->sampleRender(0, 0);
		else _object.img->sampleRender_F(0, 0, _object.frameX, _object.img->getFrameY(), _object.img->getFrameWidth(), _object.img->getFrameHeight());

		int midX, midY; //중점
		midX = (_tool.object.objRc.left + _tool.object.objRc.right) / 2;
		midY = (_tool.object.objRc.top + _tool.object.objRc.bottom) / 2;

		sampleRender(_object, midX, midY);
	}
	buttonRender();
	//마우스 커서 관련
	if (!_tool.OBJ_isOpen && !_tool.TR_isOpen)MOUSEMANAGER->render();
	if (_currentObj.img && _ctrlSelect != CTRL_TERRAINDRAW)
	{
		if (_currentObj.type == NO_F)_currentObj.img->uiRender(true, _ptMouse.x, _ptMouse.y);
		else _currentObj.img->uiRender_F(true, _ptMouse.x, _ptMouse.y,
			_currentObj.frameX, _currentObj.img->getFrameY(),
			_currentObj.img->getFrameWidth(), _currentObj.img->getFrameHeight());

	}
	//EFFECTMANAGER->render();
	RECT rc;
	rc = RectMakeCenter(MOUSEMANAGER->getMouse().x, MOUSEMANAGER->getMouse().y, 20, 20);
	D2DRENDER->DrawRectangle(rc, false);
}

void mapmap::setup()
{
	setImage();
	memset(&_vObjList, 0, sizeof(_vObjList));
	_objectSize = 0;
	_map = IMAGEMANAGER->findImage("stage1");
	_dragMouse.isDrag = false;

	_tool.terrain.img = IMAGEMANAGER->findImage("mapTool");
	_tool.terrain.rc = RectMake(5, 120, _tool.terrain.img->getWidth(), _tool.terrain.img->getHeight());
	_tool.terrain.page = 0;
	_tool.terrain.pageMax = MAPMAX / 7 + 1;

	_tool.object.img = IMAGEMANAGER->findImage("mapTool2");
	_tool.object.rc = RectMake(WINSIZEX / 2 + 5, 120, _tool.object.img->getWidth(), _tool.object.img->getHeight());
	_tool.object.objRc = RectMake(_tool.object.rc.left + 145, _tool.object.rc.top + 33, 324, 246);
	_tool.object.page = 0;
	_tool.object.pageMax = OBJMAX / 7 + 1;

	//맵 타일 셋팅
	for (int i = 0; i < TILEY; ++i)
	{
		for (int j = 0; j < TILEX; ++j)
		{
			SetRect(&_tile[i*TILEX + j].rc,
				j*TILESIZEX,
				i*TILESIZEY,
				j*TILESIZEX + TILESIZEX,
				i*TILESIZEY + TILESIZEY);
		}
	}

	for (int i = 0; i < TILEX *TILEY; i++)
	{
		_tile[i].terrainX = 0;
		_tile[i].terrainY = 0;
		_tile[i].terrain = TR_NORMAL;
		_tile[i].sizeX = TILESIZEX;
		_tile[i].sizeY = TILESIZEY;
		_tile[i].isMove = true;
		_tile[i].imgType = NO_F;
	}

	//샘플 타일 셋팅
	for (int i = 0; i < SAMPLETILEY; ++i)
	{
		for (int j = 0; j < SAMPLETILEX; ++j)
		{
			_sampleTile[i*SAMPLETILEX + j].frameX = j;
			_sampleTile[i*SAMPLETILEX + j].frameY = i;

			SetRect(&_sampleTile[i*SAMPLETILEX + j].rc,
				_tool.terrain.rc.left + 163 + (j*TILESIZEX) + 1,
				_tool.terrain.rc.top + 39 + (i*TILESIZEY) + 1,
				_tool.terrain.rc.left + 163 + (j*TILESIZEX + TILESIZEX),
				_tool.terrain.rc.top + 39 + (i*TILESIZEY + TILESIZEY));
		}
	}
	buttonSet();
}

void mapmap::setImage()
{
	//맵 관련
	IMAGEMANAGER->addImage("stage1", L"image/inGame/stage1/stage1.png");
	IMAGEMANAGER->addImage("stage2", L"image/inGame/stage2/stage2.png");
	_map = IMAGEMANAGER->findImage("stage1");
	_currentMap = "stage1";

	//타일 셋 관련
	IMAGEMANAGER->addFrameImage("stage1Tile", L"image/inGame/stage1/stage1Tile_11x9.png", 11, 9);
	IMAGEMANAGER->addFrameImage("stage2Tile", L"image/inGame/stage2/stage2Tile_11x9.png", 11, 9);
	_sampleImg = IMAGEMANAGER->findImage("stage1Tile");

	//UI 관련
	IMAGEMANAGER->addImage("mapTool", L"image/UI/mapTool.png");
	IMAGEMANAGER->addImage("mapTool2", L"image/UI/mapTool2.png");
	IMAGEMANAGER->addImage("btnObjList", L"image/UI/btnObjList.png");
	IMAGEMANAGER->addImage("btnWindow", L"image/UI/button_Window.png");

	//오브젝트 관련
	IMAGEMANAGER->addFrameImage("wood_door_L", L"image/inGame/stage1/wood_door_L_6x1.png", 6, 1);
	IMAGEMANAGER->addFrameImage("wood_door_U", L"image/inGame/stage1/wood_door_U_6x1.png", 6, 1);
	IMAGEMANAGER->addFrameImage("wood_door_LR", L"image/inGame/stage1/wood_door_LR_7x1.png", 7, 1);
	IMAGEMANAGER->addFrameImage("wood_door_LR(2)", L"image/inGame/stage1/wood_door_LR_7x1(2).png", 7, 1);
	IMAGEMANAGER->addFrameImage("steel_door", L"image/inGame/stage1/steel_door_6x1.png", 6, 1);
	IMAGEMANAGER->addFrameImage("box", L"image/inGame/stage1/box_23x1.png", 23, 1);
	IMAGEMANAGER->addFrameImage("trap", L"image/inGame/stage1/trap_8x1.png", 8, 1);
	IMAGEMANAGER->addFrameImage("torch", L"image/inGame/stage1/torch_7x1.png", 7, 1);
	IMAGEMANAGER->addImage("s_twall1", L"image/inGame/stage1/s_twall1.png");
	IMAGEMANAGER->addImage("s_twall2", L"image/inGame/stage1/s_twall2.png");
	IMAGEMANAGER->addImage("steel_window", L"image/inGame/stage1/steel_window.png");
	IMAGEMANAGER->addFrameImage("statue_L", L"image/inGame/stage2/statue_L_21x1.png", 21, 1);
	IMAGEMANAGER->addFrameImage("statue_R", L"image/inGame/stage2/statue_R_21x1.png", 21, 1);
	IMAGEMANAGER->addFrameImage("birth", L"image/inGame/stage2/birth_17x1.png", 17, 1);
	IMAGEMANAGER->addFrameImage("e_birth0", L"image/inGame/stage2/e_birth_0_21x1.png", 21, 1);
	IMAGEMANAGER->addFrameImage("e_birth_f", L"image/inGame/stage2/e_birth_full_14x1.png", 14, 1);
	IMAGEMANAGER->addFrameImage("church_door", L"image/inGame/stage2/church_door_7x1.png", 7, 1);
	IMAGEMANAGER->addFrameImage("fly", L"image/inGame/stage2/fly_4x1.png", 4, 1);
	IMAGEMANAGER->addImage("church_bench0", L"image/inGame/stage2/church_bench0.png");
	IMAGEMANAGER->addImage("church_bench1", L"image/inGame/stage2/church_bench1.png");
	IMAGEMANAGER->addImage("church_bench2", L"image/inGame/stage2/church_bench2.png");
	IMAGEMANAGER->addImage("church_bench3", L"image/inGame/stage2/church_bench3.png");
	IMAGEMANAGER->addImage("church_bench4", L"image/inGame/stage2/church_bench4.png");
	IMAGEMANAGER->addImage("church_bench5", L"image/inGame/stage2/church_bench5.png");
	IMAGEMANAGER->addImage("church_bench6", L"image/inGame/stage2/church_bench6.png");
	IMAGEMANAGER->addImage("church_bench7", L"image/inGame/stage2/church_bench7.png");
	IMAGEMANAGER->addImage("corpse0", L"image/inGame/stage2/s_corpse0.png");
	IMAGEMANAGER->addImage("corpse1", L"image/inGame/stage2/s_corpse1.png");
	IMAGEMANAGER->addImage("windowLight_L", L"image/inGame/stage2/s_windowLight_LL.png");
	IMAGEMANAGER->addImage("windowLight_R", L"image/inGame/stage2/s_windowLight_RR.png");
	IMAGEMANAGER->addImage("playerr", L"image/player/s_player_0.png");
	IMAGEMANAGER->addFrameImage("anim", L"image/zombie_anim_38x1.png", 38, 1);
	IMAGEMANAGER->addFrameImage("pool_cast", L"image/s_statue_bloodpool_cast_39x1.png", 39, 1);
	IMAGEMANAGER->addFrameImage("pool_mark_start", L"image/s_bloodpoolmark_start_7x1.png", 7, 1);
	IMAGEMANAGER->addFrameImage("pool_mark_loop", L"image/s_bloodpoolmark_loop_19x1.png", 19, 1);
	IMAGEMANAGER->addFrameImage("pool_attack_start", L"image/s_bloodpool_start_15x1.png", 15, 1);
	IMAGEMANAGER->addFrameImage("pool_attack_loop", L"image/s_bloodpool_loop_24x1.png", 24, 1);
	IMAGEMANAGER->addFrameImage("pool_attack_end", L"image/s_bloodpool_end_9x1.png", 9, 1);
	IMAGEMANAGER->addFrameImage("arrow_cast", L"image/s_statue_bloodarrow_spawn_27x1.png",27, 1);
	IMAGEMANAGER->addFrameImage("healundead", L"image/s_statue_healundead_15x1.png",15, 1);
	IMAGEMANAGER->addFrameImage("spawnundead", L"image/s_statue_spawnundead_14x1.png",14, 1);
	IMAGEMANAGER->addFrameImage("arrow_hit", L"image/s_statue_bloodarrow_hit_5x1.png",5, 1);


	IMAGEMANAGER->addImage("light", L"image/light.png");

	light = IMAGEMANAGER->findImage("light");


	_object.img = IMAGEMANAGER->findImage("trap");
	_object.name = "trap";
	_object.imgType = S_TRAP;
	_object.frameX = 1;
	_object.count = 0;
	_object.imgType = S_TRAP;

}

void mapmap::setMap()
{

	if (!_tool.TR_isOpen && !_tool.OBJ_isOpen)
	{
		if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
		{
			switch (_ctrlSelect)
			{
			case CTRL_OBJDRAW:
				_currentObj.x = MOUSEMANAGER->getMouse().x;
				_currentObj.y = MOUSEMANAGER->getMouse().y;
				_currentObj.frameOn = false;

				_vObjList.push_back(_currentObj);
				break;
			case CTRL_TILESET_IV:
				selectTileSet(MOUSEMANAGER->getMouse().x / TILESIZEX, MOUSEMANAGER->getMouse().y / TILESIZEY);
				break;
			case CTRL_TILESET_WALL:
				selectTileSet(MOUSEMANAGER->getMouse().x / TILESIZEX, MOUSEMANAGER->getMouse().y / TILESIZEY);
				break;
			case CTRL_TILESET_PLAYER:
				selectTileSet(MOUSEMANAGER->getMouse().x / TILESIZEX, MOUSEMANAGER->getMouse().y / TILESIZEY);
				break;
			case CTRL_TILESET_OBJECT:
				selectTileSet(MOUSEMANAGER->getMouse().x / TILESIZEX, MOUSEMANAGER->getMouse().y / TILESIZEY);
				break;
			case CTRL_TILESET_ENEMY:
				selectTileSet(MOUSEMANAGER->getMouse().x / TILESIZEX, MOUSEMANAGER->getMouse().y / TILESIZEY);
				break;
			case CTRL_TILESET_NONE:
				selectTileSet(MOUSEMANAGER->getMouse().x / TILESIZEX, MOUSEMANAGER->getMouse().y / TILESIZEY);
				break;
			}
		}
		if (KEYMANAGER->isOnceKeyDown(VK_SPACE))
		{
			switch (_ctrlSelect)
			{
			case CTRL_OBJDRAW:
				_currentObj.x = MOUSEMANAGER->getMouse().x;
				_currentObj.y = MOUSEMANAGER->getMouse().y;
				_currentObj.frameOn = false;

				_vObjList.push_back(_currentObj);
				break;
			case CTRL_TILESET_IV:
				selectTileSet(MOUSEMANAGER->getMouse().x / TILESIZEX, MOUSEMANAGER->getMouse().y / TILESIZEY);
				break;
			case CTRL_TILESET_WALL:
				selectTileSet(MOUSEMANAGER->getMouse().x / TILESIZEX, MOUSEMANAGER->getMouse().y / TILESIZEY);
				break;
			case CTRL_TILESET_PLAYER:
				selectTileSet(MOUSEMANAGER->getMouse().x / TILESIZEX, MOUSEMANAGER->getMouse().y / TILESIZEY);
				break;
			case CTRL_TILESET_OBJECT:
				selectTileSet(MOUSEMANAGER->getMouse().x / TILESIZEX, MOUSEMANAGER->getMouse().y / TILESIZEY);
				break;
			case CTRL_TILESET_ENEMY:
				selectTileSet(MOUSEMANAGER->getMouse().x / TILESIZEX, MOUSEMANAGER->getMouse().y / TILESIZEY);
				break;
			case CTRL_TILESET_NONE:
				selectTileSet(MOUSEMANAGER->getMouse().x / TILESIZEX, MOUSEMANAGER->getMouse().y / TILESIZEY);
				break;
			}
		}
		if (KEYMANAGER->isStayKeyDown(VK_LBUTTON))
		{
			int current = (MOUSEMANAGER->getMouse().y / TILESIZEX)*TILEX + (MOUSEMANAGER->getMouse().x / TILESIZEY);

			int sizeX = (_dragMouse.currentEndX + 1 - _dragMouse.currentStartX);
			int sizeY = (_dragMouse.currentEndY + 1 - _dragMouse.currentStartY);

			switch (_ctrlSelect)
			{
			case CTRL_TERRAINDRAW:
				for (int i = 0; i < sizeY; ++i)
				{
					for (int j = 0; j < sizeX; ++j)
					{
						_tile[i*TILEX + current + j].terrainX = _dragMouse.currentStartX + j;
						_tile[i*TILEX + current + j].terrainY = _dragMouse.currentStartY + i;
						_tile[i*TILEX + current + j].terrain = TR_SET;
					}
				}
			}
		}

	}
}

void mapmap::mapClipping()
{
}

void mapmap::cameraControl()
{
	if (KEYMANAGER->isStayKeyDown(VK_LEFT))_cX -= TILESIZEX;
	if (KEYMANAGER->isStayKeyDown(VK_RIGHT))_cX += TILESIZEX;
	if (KEYMANAGER->isStayKeyDown(VK_UP))_cY -= TILESIZEX;
	if (KEYMANAGER->isStayKeyDown(VK_DOWN))_cY += TILESIZEX;

	CAMERAMANAGER->updateCameraStone(_cX, _cY);
}

void mapmap::sampleRender(tagObject object, int x, int y)
{
	ID2D1Bitmap* bitmap;

	D2DRENDER->GetSampleBuffer()->GetBitmap(&bitmap);

	if (object.imgType == NO_F)
	{
		D2D1_RECT_F front = D2D1::RectF(x - object.img->getWidth() / 2, y - object.img->getHeight() / 2,
			x + object.img->getWidth() / 2, y + object.img->getHeight() / 2);
		D2D1_RECT_F back = D2D1::RectF(0, 0, object.img->getWidth(), object.img->getHeight());

		D2DRENDERTARGET->DrawBitmap(bitmap, front, 1.f, D2D1_BITMAP_INTERPOLATION_MODE_LINEAR, back);
	}
	else
	{
		D2D1_RECT_F front = D2D1::RectF(x - (object.img->getFrameWidth() / 2), y - (object.img->getFrameHeight() / 2),
			x + (object.img->getFrameWidth() / 2), y + (object.img->getFrameHeight() / 2));
		D2D1_RECT_F back = D2D1::RectF(0, 0, object.img->getFrameWidth(), object.img->getFrameHeight());

		D2DRENDERTARGET->DrawBitmap(bitmap, front, 1.f, D2D1_BITMAP_INTERPOLATION_MODE_LINEAR, back);
	}


}


void mapmap::save()
{
	HANDLE file;
	DWORD write;

	string arr = _currentMap;
	string arr2 = "save";

	arr.append(arr2);
	file = CreateFile(arr.c_str(), GENERIC_WRITE, NULL, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
	WriteFile(file, _tile, sizeof(tagTile)*TILEX*TILEY, &write, NULL);
	CloseHandle(file);

	char objFrameX[128];
	char objCount[128];
	char objType[128];
	char objX[128];
	char objY[128];

	char objName[128];

	char objSize[128];

	for (int i = 0; i < _vObjList.size(); ++i)
	{
		objCount[127] = _itoa_s(_vObjList[i].count, objCount, sizeof(objCount), 10);
		objFrameX[127] = _itoa_s(_vObjList[i].frameX, objFrameX, sizeof(objFrameX), 10);
		objType[127] = _itoa_s(_vObjList[i].type, objType, sizeof(objType), 10);
		objX[127] = _itoa_s(_vObjList[i].x, objX, sizeof(objX), 10);
		objY[127] = _itoa_s(_vObjList[i].y, objY, sizeof(objY), 10);

		string arr = "오브젝트";
		arr.append(to_string(i));


		INIDATA->addData(arr.c_str(), "count", objCount);
		INIDATA->addData(arr.c_str(), "frameX", objFrameX);
		INIDATA->addData(arr.c_str(), "type", objType);
		INIDATA->addData(arr.c_str(), "X", objX);
		INIDATA->addData(arr.c_str(), "Y", objY);
		INIDATA->addData(arr.c_str(), "name", _vObjList[i].name.c_str());

		string arr2 = _currentMap;
		arr2.append("오브젝트");

		INIDATA->iniSave(arr2.c_str());
	}

	objSize[127] = _itoa_s(_vObjList.size(), objSize, sizeof(objSize), 10);

	string arr3 = _currentMap;
	arr3.append("오브젝트");

	INIDATA->addData("사이즈", "사이즈", objSize);
	INIDATA->iniSave(arr3.c_str());
}

void mapmap::load()
{
	_vObjList.clear();
	vector<tagCurrentObj>().swap(_vObjList);

	HANDLE file;
	DWORD read;

	string arr = _currentMap;
	arr.append("save");

	file = CreateFile(arr.c_str(), GENERIC_READ, NULL, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	ReadFile(file, _tile, sizeof(tagTile)*TILEX*TILEY, &read, NULL);
	CloseHandle(file);

	string arr3 = _currentMap;
	arr3.append("오브젝트");
	int size = INIDATA->loadDataInt(arr3.c_str(), "사이즈", "사이즈");
	for (int i = 0; i < size; ++i)
	{
		string arr = "오브젝트";
		arr.append(to_string(i));

		tagCurrentObj info;
		info.count = INIDATA->loadDataInt(arr3.c_str(), arr.c_str(), "count");
		info.frameX = INIDATA->loadDataInt(arr3.c_str(), arr.c_str(), "frameX");
		info.type = typeSet(INIDATA->loadDataInt(arr3.c_str(), arr.c_str(), "type"));
		info.x = INIDATA->loadDataInt(arr3.c_str(), arr.c_str(), "X");
		info.y = INIDATA->loadDataInt(arr3.c_str(), arr.c_str(), "Y");
		info.name = INIDATA->loadDataStr(arr3.c_str(), arr.c_str(), "name");
		info.img = IMAGEMANAGER->findImage(info.name);
		_vObjList.push_back(info);
	}

}

void mapmap::clear()
{
	//맵 타일 셋팅
	for (int i = 0; i < TILEY; ++i)
	{
		for (int j = 0; j < TILEX; ++j)
		{
			SetRect(&_tile[i*TILEX + j].rc,
				j*TILESIZEX,
				i*TILESIZEY,
				j*TILESIZEX + TILESIZEX,
				i*TILESIZEY + TILESIZEY);
		}
	}

	for (int i = 0; i < TILEX *TILEY; i++)
	{
		_tile[i].terrainX = 0;
		_tile[i].terrainY = 0;
		_tile[i].terrain = TR_NONE;
		_tile[i].sizeX = TILESIZEX;
		_tile[i].sizeY = TILESIZEY;
		_tile[i].imgType = NO_F;
	}

	_vObjList.clear();
	vector<tagCurrentObj>().swap(_vObjList);
}



TERRAIN mapmap::terrainSelect(int frameX, int frameY)
{
	return TERRAIN();
}

void mapmap::setTerrainRect(TERRAIN tr, int num)
{
}

OBJECT mapmap::objSelect(int frameX, int frameY)
{
	return OBJECT();
}

int mapmap::imgFrameSelect(IMAGETYPE type)
{
	switch (type)
	{
	case S_DOOR:
		return 1;
		break;
	case S_TRAP:
		return 1;
		break;
	case S_STATUE_L:
		return 1;
		break;
	case S_STATUE_R:
		return 1;
		break;
	default:
		return 0;
		break;
	}
}

void mapmap::setOBJ(int num)
{
}

void mapmap::objectFrame()
{
	if (_object.imgType == NO_F)_object.frameX = 0;
	else
	{
		_object.count++;
		if (_object.count % 7 == 0)
		{
			_object.count = 0;
			_object.frameX++;
			if (_object.frameX >= _object.img->getMaxFrameX())_object.frameX = 0;
		}
	}

	for (int i = 0; i < _vObjList.size(); ++i)
	{
		_vObjList[i].count++;
		if (_vObjList[i].count % 7 == 0)
		{
			_vObjList[i].frameX++;
			if (_vObjList[i].frameX >= _vObjList[i].img->getMaxFrameX())_vObjList[i].frameX = 0;
			_vObjList[i].count = 0;
		}
	}
}

IMAGETYPE mapmap::typeSet(int type)
{
	switch (type)
	{
	case S_DOOR:
		return S_DOOR;
		break;
	case S_TORCH:
		return S_TORCH;
		break;
	case S_TRAP:
		return S_TRAP;
		break;
	case S_BOX:
		return S_BOX;
		break;
	case S_FLY:
		return S_FLY;
		break;
	case S_STATUE_L:
		return S_STATUE_L;
		break;
	case S_STATUE_R:
		return S_STATUE_R;
		break;
	default:
		return NO_F;
		break;
	}
}

void mapmap::mouseDetailControl()
{
	if (KEYMANAGER->isOnceKeyDown('W'))_ptMouse.y -= 1.f;
	if (KEYMANAGER->isOnceKeyDown('S'))_ptMouse.y += 1.f;
	if (KEYMANAGER->isOnceKeyDown('A'))_ptMouse.x -= 1.f;
	if (KEYMANAGER->isOnceKeyDown('D'))_ptMouse.x += 1.f;
}

void mapmap::selectTileSet(int idX, int idY)
{
	if (_ctrlSelect == CTRL_TILESET_IV)
	{
		_tile[idY * TILEX + idX].terrain = TR_INVISIBLE;
	}
	else if (_ctrlSelect == CTRL_TILESET_WALL)
	{
		_tile[idY * TILEX + idX].terrain = TR_WALL;
	}
	else if (_ctrlSelect == CTRL_TILESET_PLAYER)
	{
		_tile[idY * TILEX + idX].terrain = TR_PLAYER;
	}
	else if (_ctrlSelect == CTRL_TILESET_OBJECT)
	{
		_tile[idY * TILEX + idX].terrain = TR_OBJ;
	}
	else if (_ctrlSelect == CTRL_TILESET_ENEMY)
	{
		_tile[idY * TILEX + idX].terrain = TR_ENEMY;
	}
	else if (_ctrlSelect == CTRL_TILESET_NONE)
	{
		_tile[idY * TILEX + idX].terrain = TR_NONE;
	}
}

void mapmap::deleteRect(int idX, int idY)
{
}
