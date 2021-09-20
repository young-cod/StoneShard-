#include "stdafx.h"
#include "stage2.h"

HRESULT stage2::init()
{
	setUp();
	objClick = false;
	_player->setImage(IMAGEMANAGER->findImage("player_dir"));

	_aStar = new aStar;
	_aStar->stage2 = this;
	_aStar->init("stage2");
	_countPath = 0;

	x = y = 0;
	CAMERAMANAGER->setTpye("stage2");
	return S_OK;
}

void stage2::release()
{
}

void stage2::update()
{
	if (!objClick && KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
	{
		result = _aStar->PathFind(_player->getidX(), _player->getidY(), MOUSEMANAGER->getMouse().x / TILEWIDTH, MOUSEMANAGER->getMouse().y / TILEHEIGHT);
	}
	objectControl();
	aPath();
	CAMERAMANAGER->updateCameraIndex(_player->getidX(), _player->getidY());
}

void stage2::render()
{
	//맵 관련
	_map->mapRender(0, 5);
	for (int i = 0; i < TILEX*TILEY; i++)
	{
		if (_tile[i].terrain == TR_PLAYER)D2DRENDER->DrawRectangle(_tile[i].rc, false, D2DDEFAULTBRUSH::White);
		else if (_tile[i].terrain == TR_WALL)D2DRENDER->DrawRectangle(_tile[i].rc, false, D2DDEFAULTBRUSH::White);
	}
	//오브젝트 관련
	for (int i = 0; i < _vObject.size(); ++i)
	{
		if (_vObject[i].type != NO_F)_vObject[i].img->objRender_F(
			_vObject[i].x, _vObject[i].y,
			_vObject[i].frameX, _vObject[i].img->getFrameY(),
			_vObject[i].img->getFrameWidth(), _vObject[i].img->getFrameHeight());
		else _vObject[i].img->objRender(_vObject[i].x, _vObject[i].y, true);
	}
	//플레이어 관련
	_player->render(_player->getidX(), _player->getidY());
	//마우스 관련
	//보스 관련
	//이펙트 관련
}

void stage2::setUp()
{
	_map = IMAGEMANAGER->findImage("stage2");
	_sample = IMAGEMANAGER->findImage("stage2Tile");

	_player = new playerManager;
	_player->init();

	CAMERAMANAGER->setMapCamera(700, 700);

	CAMERAMANAGER->setZoomX(WINSIZEX / 3);
	CAMERAMANAGER->setZoomY(WINSIZEY / 3);

	load();
}

void stage2::load()
{
	HANDLE file;
	DWORD read;

	file = CreateFile("stage2save", GENERIC_READ, NULL, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	ReadFile(file, _tile, sizeof(tagTile)*TILEX*TILEY, &read, NULL);
	CloseHandle(file);

	string arr2;
	arr2 = "stage2";
	arr2.append("오브젝트");

	int size = INIDATA->loadDataInt(arr2.c_str(), "사이즈", "사이즈");
	for (int i = 0; i < size; ++i)
	{
		string arr = "오브젝트";
		arr.append(to_string(i));

		tagCurrentObj info;
		info.count = INIDATA->loadDataInt(arr2.c_str(), arr.c_str(), "count");
		info.frameX = INIDATA->loadDataInt(arr2.c_str(), arr.c_str(), "frameX");
		info.type = typeSet(INIDATA->loadDataInt(arr2.c_str(), arr.c_str(), "type"));
		info.x = INIDATA->loadDataInt(arr2.c_str(), arr.c_str(), "X");
		info.y = INIDATA->loadDataInt(arr2.c_str(), arr.c_str(), "Y");
		info.name = INIDATA->loadDataStr(arr2.c_str(), arr.c_str(), "name");
		info.img = IMAGEMANAGER->findImage(info.name);
		info.is = false;
		if (info.type != NO_F)info.rc = objectRectSet(info);
		else info.rc = RectMake(info.x, info.y, info.img->getWidth(), info.img->getHeight());
		info.frameOn = false;
		_vObject.push_back(info);

	}

	for (int i = 0; i < TILEX*TILEY; ++i)
	{
		if (_tile[i].terrain == TR_PLAYER)
		{
			_player->setIdX(i % TILEX);
			_player->setIdY(i / TILEX);
		}
		if (_tile[i].terrain == TR_OBJ)
		{
			initY = _tile[i].terrainY;
		}
	}

}

void stage2::objectControl()
{
	for (int i = 0; i < _vObject.size(); ++i)
	{
		if (_vObject[i].type != S_FLY && PtInRect(&_vObject[i].rc, MOUSEMANAGER->getMouse()))
		{
			objClick = true;
			if (!_vObject[i].frameOn)_vObject[i].frameX = 0;
			else if (_vObject[i].frameX == _vObject[i].img->getMaxFrameX())  _vObject[i].frameX = _vObject[i].img->getMaxFrameX() - 2;
			if (objClick && KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
			{
				_vObject[i].frameOn = true;
			}
			break;
		}
		else
		{
			if (_vObject[i].type != S_FLY & !_vObject[i].frameOn) _vObject[i].frameX = 1;
			objClick = false;
		}
	}
	objectFrame();
}

void stage2::objectFrame()
{
	for (int i = 0; i < _vObject.size(); i++)
	{
		switch (_vObject[i].type)
		{
		case S_DOOR_LR:
			break;
		case S_STATUE_L:
			break;
		case S_STATUE_R:
			break;
		case S_FLY:
			_vObject[i].count++;
			if (_vObject[i].count % 7 == 0)
			{
				_vObject[i].frameX++;
				if (_vObject[i].frameX >= _vObject[i].img->getMaxFrameX())_vObject[i].frameX = 0;
			}
			break;
		}
	}
}

RECT stage2::objectRectSet(tagCurrentObj obj)
{
	switch (obj.type)
	{
	case S_DOOR_LR:
		return RectMake(obj.x + 7, obj.y + 1, 44, 62);
		break;
	case S_STATUE_L:
		return RectMake(obj.x + 45, obj.y + 1, 61, 138);
		break;
	case S_STATUE_R:
		return RectMake(obj.x + 20, obj.y + 1, 60, 140);
		break;
	default:
		return RectMake(1, 1, 1, 1);
		break;
	}
}

void stage2::aPath()
{
	_countPath++;
	if (_countPath % 10 == 0 && !result.empty())
	{
		for (int i = result.size() - 1; i > -1; --i)
		{
			_player->setIdX(result[i].first);
			_player->setIdY(result[i].second);

			result.erase(result.begin() + i);
			break;
		}
	}
}

IMAGETYPE stage2::typeSet(int type)
{
	switch (type)
	{
	case S_DOOR_LR:
		return S_DOOR_LR;
		break;
	case S_STATUE_L:
		return S_STATUE_L;
		break;
	case S_STATUE_R:
		return S_STATUE_R;
		break;
	case S_FLY:
		return S_FLY;
		break;
	default:
		break;
	}
}

bool stage2::isValidTile(int x, int y)
{
	if (_tile[y * TILEX + x].terrain == TR_WALL)
		return false;
	return true;
}
