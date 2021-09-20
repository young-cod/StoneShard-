#include "stdafx.h"
#include "stage1.h"

HRESULT stage1::init()
{

	setup();

	_aStar = new aStar;
	_aStar->init("stage1");
	_aStar->stage1 = this;

	_ray = new rayCast;
	_ray->_stage1 = this;

	for (int i = 0; i < TILEX*TILEY; i++)
	{
		if (_tile[i].terrain == TR_WALL)_vision[i] = 1;
		else _vision[i] = 0;
	}
	_black = IMAGEMANAGER->findImage("black");

	return S_OK;
}


void stage1::release()
{
}

void stage1::update()
{
	if (!_player->getInit())_initCount++;
	if (_initCount > 30)
	{
		_player->setInit(true);
		if (_player->getInit())
		{
			_sCount++;
			if (_sCount % 7 == 0)
			{
				_sCount = 0;
				_player->getPlayer().img->setFrameX(_player->getPlayer().img->getFrameX() + 1);
				if (_player->getPlayer().img->getFrameX() >= _player->getPlayer().img->getMaxFrameX())
				{
					_player->getPlayer().img->setFrameX(_player->getPlayer().img->getMaxFrameX() - 1);
					_player->setImage(IMAGEMANAGER->findImage("player_dir"));
					_initCount = 0;
				}
			}
		}
	}
	if (PtInRect(&nextScene, MOUSEMANAGER->getMouse()))
	{
		if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
		{
			SCENEMANAGER->changeScene("stage2");
		}
	}

	if (!objClick && KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
	{
		result = _aStar->PathFind(_player->getidX(), _player->getidY(), MOUSEMANAGER->getMouse().x / TILEWIDTH, MOUSEMANAGER->getMouse().y / TILEHEIGHT);

		for (int i = 0; i < result.size(); ++i)
		{
			RECT rc;
			rc = RectMake(result[i].first * 26, result[i].second * 26, TILESIZEX, TILESIZEY);
			D2DRENDER->DrawRectangle(rc, false, D2DDEFAULTBRUSH::Red);
		}
	}
	aPath();

	_player->update();
	_rayResult = _ray->rayOn(TILEX, TILEY, _player->getX(), _player->getY(), _vision);
	visionSet();
	objectControl();


	CAMERAMANAGER->updateCameraIndex(_player->getidX(), _player->getidY());
	UI->update();
}

void stage1::render()
{
	_map->mapRender(0, 0);

	//오브젝트
	for (int i = 0; i < _vObject.size(); ++i)
	{
		if (_vObject[i].type == NO_F)_vObject[i].img->objRender(_vObject[i].x, _vObject[i].y, true);
		else _vObject[i].img->objRender_F(
			_vObject[i].x, _vObject[i].y,
			_vObject[i].frameX, _vObject[i].img->getFrameY(),
			_vObject[i].img->getFrameWidth(), _vObject[i].img->getFrameHeight());
	}
	//플레이어
	_player->render(_player->getidX(), _player->getidY());
	//타일
	for (int i = 0; i < TILEX*TILEY; ++i)
	{
		_tileImage->tileRender(_tile[i].rc.left, _tile[i].rc.top,
			_tile[i].terrainX, _tile[i].terrainY, _tile[i].sizeX, _tile[i].sizeY);
		if (KEYMANAGER->isToggleKey('P'))
		{
			if (_view[i] == 1)_black->uiRender(false, _tile[i].rc.left, _tile[i].rc.top, 0.f);
			else if (_view[i] == 2)_black->uiRender(false, _tile[i].rc.left, _tile[i].rc.top, 0.3f);
			else _black->uiRender(false, _tile[i].rc.left, _tile[i].rc.top, 1.f);
		}
	}

	//비젼
	//적
	//마우스
	if (objClick)MOUSEMANAGER->setMouseImg(IMAGEMANAGER->findImage("mouse_hand"));
	else MOUSEMANAGER->setMouseImg(IMAGEMANAGER->findImage("mouse_basic"));

	if (KEYMANAGER->isToggleKey(VK_TAB))
	{
		/*for (int i = 0; i < _vObject.size(); ++i)
		{
			D2DRENDER->DrawRectangle(_vObject[i].rc, false, D2DDEFAULTBRUSH::White);
		}*/
		_ray->render();
		/*for (int i = 0; i < TILEX*TILEY; i++)
		{
			if (PtInRect(&_tile[i].rc, MOUSEMANAGER->getMouse()))
			{
				D2DRENDER->FillRectangle(_tile[i].rc, D2DDEFAULTBRUSH::White);
			}
			D2DRENDER->DrawRectangle(_tile[i].rc, false, D2DDEFAULTBRUSH::White,0.2f);
		}*/
	}
	D2DRENDER->DrawRectangle(nextScene, false, D2DDEFAULTBRUSH::White);

	UI->render();
}

void stage1::setup()
{
	//맵 관련
	_map = IMAGEMANAGER->findImage("stage1");
	_tileImage = IMAGEMANAGER->findImage("stage1Tile");
	nextScene = RectMake(30, 270, 40, 40);
	_player = new playerManager;
	_player->init();

	//씬 들어갈때 플레이어 관련 
	_initCount = 0;
	_sCount = 0;

	load();

	CAMERAMANAGER->setX(156);
	CAMERAMANAGER->setY(466);
	CAMERAMANAGER->setMapCamera(726, 752);

	CAMERAMANAGER->setZoomX(WINSIZEX / 3);
	CAMERAMANAGER->setZoomY(WINSIZEY / 3);


}

void stage1::load()
{
	HANDLE file;
	DWORD read;

	string name = "stage1";
	string arr = name;

	arr.append("save");

	file = CreateFile(arr.c_str(), GENERIC_READ, NULL, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

	ReadFile(file, _tile, sizeof(tagTile)*TILEX*TILEY, &read, NULL);
	CloseHandle(file);

	string arr2;
	arr2 = name;
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
			_player->setIdX(i%TILEX);
			_player->setIdY(i / TILEX);
		}
	}
}


void stage1::aPath()
{

	_countPath++;
	if (_countPath % 10 == 0 && !result.empty())
	{
		for (int i = result.size() - 1; i > -1; --i)
		{
			if (_player->getidX() > result[i].first)_player->setDir(LEFT);
			else _player->setDir(RIGHT);

			_player->setPosition(result[i].first, result[i].second);

			result.erase(result.begin() + i);
			break;
		}
	}
}

void stage1::visionSet()
{
	for (int i = 0; i < TILEX*TILEY; i++)
	{
		if (_view[i] == 1 || _view[i] == 2)_view[i] = 2;
		else _view[i] = 0;
	}
	for (int i = 0; i < _rayResult.size(); ++i)
	{
		_view[_rayResult[i]] = 1;
	}
	_view[_player->getidY()* TILEX + _player->getidX()] = 1;
}

void stage1::objectControl()
{
	for (int i = 0; i < _vObject.size(); ++i)
	{
		if (PtInRect(&_vObject[i].rc, MOUSEMANAGER->getMouse()))
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
			if (!_vObject[i].frameOn) _vObject[i].frameX = 1;
			objClick = false;
		}
	}

	objectFrame();
}

void stage1::objectFrame()
{
	for (int i = 0; i < _vObject.size(); ++i)
	{
		if (_vObject[i].type == S_TORCH)
		{
			_vObject[i].count++;
			if (_vObject[i].count % 7 == 0)
			{
				_vObject[i].count = 0;
				_vObject[i].frameX++;
				if (_vObject[i].frameX >= _vObject[i].img->getMaxFrameX())_vObject[i].frameX = 0;
			}
		}
		if (_vObject[i].frameOn)
		{
			switch (_vObject[i].type)
			{
			case S_DOOR:
				_vObject[i].count++;
				if (_vObject[i].count % 7 == 0)
				{
					_vObject[i].count = 0;
					_vObject[i].frameX++;
					if (_vObject[i].frameX >= _vObject[i].img->getMaxFrameX() - 1)_vObject[i].frameX = _vObject[i].img->getMaxFrameX() - 2;
				}
				break;
			case S_DOOR_LR:
				_vObject[i].count++;
				if (_vObject[i].count % 7 == 0)
				{
					_vObject[i].count = 0;
					_vObject[i].frameX++;
					if (_vObject[i].frameX >= _vObject[i].img->getMaxFrameX())_vObject[i].frameX = _vObject[i].img->getMaxFrameX() - 1;
				}
				break;
			case S_TRAP:
				_vObject[i].count++;
				if (_vObject[i].count % 7 == 0)
				{
					_vObject[i].count = 0;
					_vObject[i].frameX++;
					if (_vObject[i].frameX >= _vObject[i].img->getMaxFrameX())_vObject[i].frameX = _vObject[i].img->getMaxFrameX() - 1;
				}
				break;
			case S_BOX:
				_vObject[i].count++;
				if (_vObject[i].count % 7 == 0)
				{
					_vObject[i].count = 0;
					_vObject[i].frameX++;
					if (_vObject[i].frameX >= _vObject[i].img->getMaxFrameX() - 1)_vObject[i].frameX = _vObject[i].img->getMaxFrameX() - 2;
				}
				break;
			case S_DOOR_L:
				_vObject[i].count++;
				if (_vObject[i].count % 7 == 0)
				{
					_vObject[i].count = 0;
					_vObject[i].frameX++;
					if (_vObject[i].frameX >= _vObject[i].img->getMaxFrameX() - 1)_vObject[i].frameX = _vObject[i].img->getMaxFrameX() - 2;
				}
				break;
			}
		}
	}
}

RECT stage1::objectRectSet(tagCurrentObj obj)
{
	switch (obj.type)
	{
	case S_DOOR:
		return RectMake(obj.x + 1, obj.y + 12, 26, 39);
		break;
	case S_DOOR_L:
		return  RectMake(obj.x + 1, obj.y + 1, 6, 50);
		break;
	case S_DOOR_LR:
		return RectMake(obj.x + 19, obj.y + 6, 46, 44);
		break;
	case S_TRAP:
		return  RectMake(obj.x, obj.y + 12, 27, 27);
		break;
	case S_BOX:
		return  RectMake(obj.x + 23, obj.y + 20, 22, 25);
		break;
	default:
		return RectMake(obj.x, obj.y, obj.img->getFrameWidth(), obj.img->getFrameHeight());
		break;
	}

}


IMAGETYPE stage1::typeSet(int type)
{
	switch (type)
	{
	case S_DOOR:
		return S_DOOR;
		break;
	case S_DOOR_LR:
		return S_DOOR_LR;
		break;
	case S_WINDOW:
		return S_WINDOW;
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
	case NO_F:
		return NO_F;
		break;
	}
}

bool stage1::isValidTile(int x, int y)
{
	if (_tile[y * TILEX + x].terrain == TR_WALL)
		return false;
	return true;
	//enum TERRAIN
	//{
	//	TR_NORMAL,
	//	TR_SET,
	//	WATER,
	//	TR_INVISIBLE,
	//	TR_WALL,
	//	TR_NONE,
	//	TR_PLAYER
	//};

	//struct tagTile
	//{
	//	string tileType;
	//	TERRAIN terrain;
	//	IMAGETYPE imgType;
	//	image* img;
	//	RECT rc;
	//	RECT checkRect;
	//	int terrainX;
	//	int terrainY;
	//	int sizeX;
	//	int sizeY;
	//	bool isMove;
	//};
}
