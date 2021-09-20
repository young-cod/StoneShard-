#include "stdafx.h"
#include "playerManager.h"

playerManager::playerManager()
{
}

playerManager::~playerManager()
{
}

HRESULT playerManager::init()
{
	imageSet();
	playerSet();

	return S_OK;
}

void playerManager::release()
{
}

void playerManager::update()
{
	if (_player.init)
	{
		_player.count++;
		if (_player.count % 7 == 0)
		{
			_player.count = 0;
			_player.img->setFrameX(_player.img->getFrameX() + 1);
			if (_player.img->getFrameX() >= _player.img->getMaxFrameX())
			{
				_player.img->setFrameX(_player.img->getMaxFrameX() - 1);
				_player.img = IMAGEMANAGER->findImage("player3");
			}
		}
	}
	if (_player.img == IMAGEMANAGER->findImage("player3"))
	{
		if (_player.dir == LEFT)_player.img->setFrameX(0);
		else _player.img->setFrameX(1);
	}
}

void playerManager::render()
{
	_player.img->playerRender(_player.x, _player.y);
	D2DRENDER->DrawRectangle(_player.rc, false, D2DDEFAULTBRUSH::Yellow);
}

void playerManager::render(int idX, int idY)
{
	_player.img->playerRender_F(false, idX * 26 + 3, idY * 26 - 15, _player.img->getFrameX(), _player.img->getFrameY(), _player.img->getFrameWidth(), _player.img->getFrameHeight());
	//_player.img->playerRender_F(false, idX, idY, _player.img->getFrameX(), _player.img->getFrameY(), _player.img->getFrameWidth(), _player.img->getFrameHeight());
}

void playerManager::playerSet()
{
	_player.img = IMAGEMANAGER->findImage("player2");
	_player.count = 0;
	_player.x = WINSIZEX / 2;
	_player.y = WINSIZEY / 2;

	_player.speed = 10.f;

	_player.idX = _player.x / 26;
	_player.idY = _player.y / 26;
	_player.rc = RectMake(_player.x, _player.y, _player.img->getWidth(), _player.img->getHeight());

	_player.SP = 0;
	_player.level = 1;
	_player.strength = 10;
	_player.agility = 10;
	_player.perception = 10;
	_player.vitality = 10;
	_player.willpower = 10;
	_player.hunger = 0;
	_player.thirst = 0;
	_player.intoxication = 0;
	_player.pain = 0;
	_player.immunity = 80;
	_player.morale = 0;
	_player.sanity = 80;
	_player.dir = LEFT;

	_player.init = false;
}

void playerManager::imageSet()
{
	IMAGEMANAGER->addImage("player", L"image/player/s_player_2.png");
	IMAGEMANAGER->addFrameImage("player2", L"image/player/verren_sleep_9x1.png", 9, 1);
	IMAGEMANAGER->addFrameImage("player3", L"image/player/verren_direction.png", 2, 1);
}

void playerManager::visionSet()
{/*
	if (_player.vision.size() > 625)_player.vision.clear();
	int i, j, radius;
	radius = 25;
	for (i = 0; i < radius; i++) {
		for (j = 0; j < radius; j++) {
			(radius*radius / 4.0 > (i + 0.5 - radius / 2.0)*(i + 0.5 - radius / 2.0) + (j + 0.5 - radius / 2.0)*(j + 0.5 - radius / 2.0)) ?
				_vision.attribute = WHITE : _vision.attribute = MIDDLE;
			_vision.idX = _player.idX + 13 + j;
			_vision.idY = _player.idY + i;

			_player.vision.push_back(_vision);
		}
	}*/
}

void playerManager::click()
{
}

void playerManager::move(float x, float y)
{
	int xx = x * 26;
	int yy = y * 26;

	//xÃà
	if (xx > _player.x)_player.x += _player.speed + TIMEMANAGER->getElapsedTime();
	else if (xx < _player.x)_player.x -= _player.speed + TIMEMANAGER->getElapsedTime();
		
	//yÃà
	if (yy > _player.y)_player.y += _player.speed + TIMEMANAGER->getElapsedTime();
	else if (yy < _player.y)_player.y -= _player.speed + TIMEMANAGER->getElapsedTime();

	_player.idX = _player.x / 26;
	_player.idY = _player.y / 26;
}

