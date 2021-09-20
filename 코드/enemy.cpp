#include "stdafx.h"
#include "enemy.h"

HRESULT enemy::init(image * img, int x, int y)
{
	setup();

	_archon.img = img;
	_archon.x = x;
	_archon.y = y;
	_archon.count = 0;
	_archon.frameX = 1;

	return S_OK;
}

void enemy::release()
{
}

void enemy::update()
{
}

void enemy::render()
{
	_archon.img->objRender_F(_archon.x, _archon.y,
		_archon.frameX, _archon.img->getFrameY(),
		_archon.img->getFrameWidth(), _archon.img->getFrameHeight());

	_archon.statueL.img->objRender_F(_archon.statueL.x, _archon.statueL.y, _archon.statueL.frameX, _archon.statueL.img->getFrameY(),
		_archon.statueL.img->getFrameWidth(), _archon.statueL.img->getFrameHeight());

	_archon.statueR.img->objRender_F(_archon.statueR.x, _archon.statueR.y, _archon.statueR.frameX, _archon.statueR.img->getFrameY(),
		_archon.statueR.img->getFrameWidth(), _archon.statueR.img->getFrameHeight());

	for (int i = 0; i < _vUndead.size(); i++)
	{
		_vUndead[i].img->objRender_F(_vUndead[i].x, _vUndead[i].y, _vUndead[i].frameX, _vUndead[i].img->getFrameY(),
			_vUndead[i].img->getFrameWidth(), _vUndead[i].img->getFrameHeight());
	}
}

void enemy::setup()
{
	imageSet();
}

void enemy::setUndead(int x, int y)
{
	tagUndead undead;
	undead.x = x;
	undead.y = y;
	undead.count = 0;
	undead.frameX = 0;
	undead.img = IMAGEMANAGER->findImage("undead_anim");

	_vUndead.push_back(undead);
}

void enemy::imageSet()
{
	//archon 관련
	IMAGEMANAGER->addFrameImage("archon_birth", L"image/inGame/stage2/birth_17x1.png",17, 1);
	IMAGEMANAGER->addFrameImage("archon_birth_effect", L"image/inGame/stage2/e_birth_0_21x1.png", 21, 1);
	IMAGEMANAGER->addFrameImage("archon_in_effect", L"image/inGame/stage2/e_birth_full_14x1.png", 14, 1);

	//statueL 관련
	IMAGEMANAGER->addFrameImage("statueL", L"image/inGame/stage2/statue_L_21x1.png", 21, 1);
	IMAGEMANAGER->addFrameImage("statue_bloodpool_cast", L"image/inGame/stage2/s_statue_bloodpool_cast_39x1.png", 39, 1);
	IMAGEMANAGER->addFrameImage("statue_bloodpool_mark_start",L"image/inGame/stage2/s_bloodpoolmark_start_7x1.png", 7, 1);
	IMAGEMANAGER->addFrameImage("statue_bloodpool_mark_loop", L"image/inGame/stage2/s_bloodpoolmark_loop_19x1.png", 19, 1);
	IMAGEMANAGER->addFrameImage("statue_bloodpool_start", L"image/inGame/stage2/s_bloodpool_start_15x1.png", 15, 1);
	IMAGEMANAGER->addFrameImage("statue_bloodpool_loop", L"image/inGame/stage2/s_bloodpool_loop_24x1.png", 24, 1);
	IMAGEMANAGER->addFrameImage("statue_bloodpool_end", L"image/inGame/stage2/s_bloodpool_end_9x1.png", 9, 1);
	IMAGEMANAGER->addFrameImage("statue_arrow_cast", L"image/inGame/stage2/s_statue_bloodarrow_spawn_27x1.png", 27, 1);
	IMAGEMANAGER->addFrameImage("statue_arrow", L"image/inGame/stage2/s_statue_bloodarrow_4x1.png", 4, 1);
	IMAGEMANAGER->addFrameImage("statue_arrow_hit", L"image/inGame/stage2/s_statue_bloodarrow_hit_5x1.png", 5, 1);

	//statueR 관련
	IMAGEMANAGER->addFrameImage("statue_healundead", L"image/inGame/stage2/s_statue_healundead_15x1.png", 15, 1);
	IMAGEMANAGER->addFrameImage("statue_spawnundead", L"image/inGame/stage2/s_statue_spawnundead_14x1.png", 14, 1);
	IMAGEMANAGER->addFrameImage("undead_anim", L"image/inGame/stage2/zombie_anim_38x1.png", 38, 1);
}
