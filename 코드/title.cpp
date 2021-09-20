#include "stdafx.h"
#include "title.h"

HRESULT title::init()
{
	imageSet();
	buttonSet();

	return S_OK;
}

void title::release()
{
}

void title::update()
{
	_timer++;

	frameSet();
	//CAMERAMANAGER->mousePoint();

	if (_timer > 300)
	{
		if (PtInRect(&_play[0].rc, _ptMouse) && KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
		{
			SCENEMANAGER->changeScene("mapmap");
		}
	}

}

void title::render()
{
	if (_timer <= 100)
	{
		_start.img->setAlpha(_start.img->getAlpha() - 0.01f);
		_start.img->render(_start.rc.left, _start.rc.top);
	}
	else if (_timer > 100 && _timer <= 200)
	{
		_logo_one.img->setAlpha(_logo_one.img->getAlpha() - 0.01f);
		_logo_one.img->render(_logo_one.rc.left, _logo_one.rc.top);
	}
	else if (_timer > 200 && _timer <= 300)
	{
		_logo_two.img->setAlpha(_logo_two.img->getAlpha() - 0.01f);
		_logo_two.img->render(_logo_two.rc.left, _logo_two.rc.top);
	}
	else
	{
		mainRender();
		buttonRender();
		D2DRENDER->DrawRectangle(_play[0].rc, false, D2DDEFAULTBRUSH::White);
	}
}

void title::imageSet()
{
	IMAGEMANAGER->addImage("start", L"image/title/start.png");
	IMAGEMANAGER->addImage("logo_one", L"image/title/logo_one.png");
	IMAGEMANAGER->addImage("logo_two", L"image/title/logo_two.png");

	_start.img = IMAGEMANAGER->findImage("start");
	_start.rc = RectMakeCenter(WINSIZEX / 2, WINSIZEY / 2, _start.img->getWidth(), _start.img->getHeight());
	_logo_one.img = IMAGEMANAGER->findImage("logo_one");
	_logo_one.rc = RectMakeCenter(WINSIZEX / 2, WINSIZEY / 2, _logo_one.img->getWidth(), _logo_one.img->getHeight());
	_logo_two.img = IMAGEMANAGER->findImage("logo_two");
	_logo_two.rc = RectMakeCenter(WINSIZEX / 2, WINSIZEY / 2, _logo_two.img->getWidth(), _logo_two.img->getHeight());

	IMAGEMANAGER->addFrameImage("loading", L"image/title/loading_26x1.png", 26, 1);

	IMAGEMANAGER->addImage("main", L"image/title/main.png");
	IMAGEMANAGER->addFrameImage("mainSword", L"image/title/mainSword_6x1.png", 6, 1);
	IMAGEMANAGER->addFrameImage("stoneshard", L"image/title/stoneshard_30x1.png", 30, 1);
	IMAGEMANAGER->addFrameImage("stoneEffect", L"image/title/stoneEffect_6x1.png", 6, 1);

	IMAGEMANAGER->addFrameImage("mainHammer", L"image/title/mainHammer_6x1.png", 6, 1);
	IMAGEMANAGER->addFrameImage("nameLogo", L"image/title/nameLogo_10x1.png", 10, 1);

	_main = IMAGEMANAGER->findImage("main");
	_stoneShard.img = IMAGEMANAGER->findImage("stoneshard");
	_stoneShard.left = 160;
	_stoneShard.top = 305;
	_stoneEffect.img = IMAGEMANAGER->findImage("stoneEffect");
	_stoneEffect.left = 80;
	_stoneEffect.top = 292;
	_nameLogo.img = IMAGEMANAGER->findImage("nameLogo");
	_nameLogo.left = 770;
	_nameLogo.top = 100;
	_hammer.img = IMAGEMANAGER->findImage("mainHammer");
	_hammer.left = 0;
	_hammer.top = 423;
	_sword.img = IMAGEMANAGER->findImage("mainSword");
	_sword.left = 296;
	_sword.top = 344;
}

void title::frameSet()
{
	_stoneShard.count++;
	if (_stoneShard.count % 5 == 0)
	{
		_stoneShard.img->setFrameX(_stoneShard.img->getFrameX() + 1);
		if (_stoneShard.img->getFrameX() >= _stoneShard.img->getMaxFrameX())
		{
			_stoneShard.img->setFrameX(0);
		}
		_stoneShard.count = 0;
	}
	_stoneEffect.count++;
	if (_stoneEffect.count % 5 == 0)
	{
		_stoneEffect.img->setFrameX(_stoneEffect.img->getFrameX() + 1);
		if (_stoneEffect.img->getFrameX() >= _stoneEffect.img->getMaxFrameX())
		{
			_stoneEffect.img->setFrameX(0);
		}
		_stoneEffect.count = 0;
	}

	if (_timer > 301)
	{
		_nameLogo.count++;
		if (_nameLogo.count % 5 == 0)
		{
			_nameLogo.img->setFrameX(_nameLogo.img->getFrameX() + 1);
			if (_nameLogo.img->getFrameX() >= _nameLogo.img->getMaxFrameX())
			{
				_nameLogo.img->setFrameX(_nameLogo.img->getMaxFrameX() - 1);
			}
			_nameLogo.count = 0;
		}
	}
	_hammer.count++;
	if (_hammer.count % 5 == 0)
	{
		_hammer.img->setFrameX(_hammer.img->getFrameX() + 1);
		if (_hammer.img->getFrameX() >= _hammer.img->getMaxFrameX())
		{
			_hammer.img->setFrameX(0);
		}
		_hammer.count = 0;
	}
	_sword.count++;
	if (_sword.count % 5 == 0)
	{
		_sword.img->setFrameX(_sword.img->getFrameX() + 1);
		if (_sword.img->getFrameX() >= _sword.img->getMaxFrameX())
		{
			_sword.img->setFrameX(0);
		}
		_sword.count = 0;
	}
}

void title::buttonSet()
{
	IMAGEMANAGER->addImage("button1", L"image/title/button1.png", 180, 37);
	IMAGEMANAGER->addImage("button2", L"image/title/button2.png", 180, 37);
	IMAGEMANAGER->addImage("button3", L"image/title/button3.png", 180, 37);

	_play[0].img = IMAGEMANAGER->findImage("button1");
	_play[1].img = IMAGEMANAGER->findImage("button2");
	_play[2].img = IMAGEMANAGER->findImage("button3");

	_option[0].img = IMAGEMANAGER->findImage("button1");
	_option[1].img = IMAGEMANAGER->findImage("button2");
	_option[2].img = IMAGEMANAGER->findImage("button3");

	_god[0].img = IMAGEMANAGER->findImage("button1");
	_god[1].img = IMAGEMANAGER->findImage("button2");
	_god[2].img = IMAGEMANAGER->findImage("button3");

	_exit[0].img = IMAGEMANAGER->findImage("button1");
	_exit[1].img = IMAGEMANAGER->findImage("button2");
	_exit[2].img = IMAGEMANAGER->findImage("button3");

	for (int i = 0; i < 3; i++)
	{
		_play[i].left = 770;
		_play[i].top = 280;
		_play[i].rc = RectMake(_play[i].left, _play[i].top, _play[i].img->getWidth(), _play[i].img->getHeight());
		_option[i].left = 770;
		_option[i].top = 330;
		_option[i].rc = RectMake(_option[i].left, _option[i].top, _option[i].img->getWidth(), _option[i].img->getHeight());
		_god[i].left = 770;
		_god[i].top = 380;
		_god[i].rc = RectMake(_god[i].left, _god[i].top, _god[i].img->getWidth(), _god[i].img->getHeight());
		_exit[i].left = 770;
		_exit[i].top = 430;
		_exit[i].rc = RectMake(_exit[i].left, _exit[i].top, _exit[i].img->getWidth(), _exit[i].img->getHeight());
	}
}

void title::mainRender()
{
	_main->render(0, 113);

	_stoneShard.img->
		uiRender_F(true,
			_stoneShard.left, _stoneShard.top,
			_stoneShard.img->getFrameX(), _stoneShard.img->getFrameY(),
			_stoneShard.img->getFrameWidth(), _stoneShard.img->getFrameHeight()
		);
	_stoneEffect.img->
		uiRender_F(true,
			_stoneEffect.left, _stoneEffect.top,
			_stoneEffect.img->getFrameX(), _stoneEffect.img->getFrameY(),
			_stoneEffect.img->getFrameWidth(), _stoneEffect.img->getFrameHeight()
		);
	_nameLogo.img->
		uiRender_F(true,
			_nameLogo.left, _nameLogo.top,
			_nameLogo.img->getFrameX(), _nameLogo.img->getFrameY(),
			_nameLogo.img->getFrameWidth(), _nameLogo.img->getFrameHeight(),
			1.f, 1.3f, 1.3f
		);
	_hammer.img->
		uiRender_F(true,
			_hammer.left, _hammer.top,
			_hammer.img->getFrameX(), _hammer.img->getFrameY(),
			_hammer.img->getFrameWidth(), _hammer.img->getFrameHeight()
		);
	_sword.img->
		uiRender_F(true,
			_sword.left, _sword.top,
			_sword.img->getFrameX(), _sword.img->getFrameY(),
			_sword.img->getFrameWidth(), _sword.img->getFrameHeight()
		);
}

void title::buttonRender()
{
	_play[0].img->render(_play[0].left, _play[0].top);
	D2DRENDER->RenderTextField(
		_play[0].left, _play[0].top,
		L"플레이",
		16,
		_play[0].img->getWidth(), _play[0].img->getHeight(),
		D2DDEFAULTBRUSH::White,
		DWRITE_TEXT_ALIGNMENT_CENTER,
		L"StoneshardFont_new"
	);
	_option[0].img->render(_option[0].left, _option[0].top);
	D2DRENDER->RenderTextField(
		_option[0].left, _option[0].top,
		L"설정",
		16,
		_option[0].img->getWidth(), _option[0].img->getHeight(),
		D2DDEFAULTBRUSH::White,
		DWRITE_TEXT_ALIGNMENT_CENTER,
		L"StoneshardFont_new"
	);
	_god[0].img->render(_god[0].left, _god[0].top);
	D2DRENDER->RenderTextField(
		_god[0].left, _god[0].top,
		L"제작자",
		16,
		_god[0].img->getWidth(), _god[0].img->getHeight(),
		D2DDEFAULTBRUSH::White,
		DWRITE_TEXT_ALIGNMENT_CENTER,
		L"StoneshardFont_new"
	);
	_exit[0].img->render(_exit[0].left, _exit[0].top);
	D2DRENDER->RenderTextField(
		_exit[0].left, _exit[0].top,
		L"종료",
		16,
		_exit[0].img->getWidth(), _exit[0].img->getHeight(),
		D2DDEFAULTBRUSH::White,
		DWRITE_TEXT_ALIGNMENT_CENTER,
		L"StoneshardFont_new"
	);
}
