#include "stdafx.h"
#include "stageManager.h"

HRESULT stageManager::init()
{
	fontSet();
	imageSet();
	soundSet();
	SOUNDMANAGER->play("snd_title");
	sceneSet();


	return S_OK;
}

void stageManager::release()
{
}

void stageManager::update()
{
	SCENEMANAGER->update();

}

void stageManager::render()
{
	SCENEMANAGER->render();

}

void stageManager::sceneSet()
{
	SCENEMANAGER->addScene("mapmap", new mapmap);
	SCENEMANAGER->addScene("title", new title);
	SCENEMANAGER->addScene("stage1", new stage1);
	SCENEMANAGER->addScene("stage2", new stage2);
	SCENEMANAGER->addScene("ray", new rayCast);

	SCENEMANAGER->changeScene("ray");
}

void stageManager::fontSet()
{
	D2DRENDER->AddTextFormat(L"StoneshardFont_new");
}

void stageManager::imageSet()
{
	//맵 관련
	IMAGEMANAGER->addImage("stage1", L"image/inGame/stage1/stage1.png");

	//타일 셋 관련
	IMAGEMANAGER->addFrameImage("stage1Tile", L"image/inGame/stage1/stage1Tile_11x9.png", 11, 9);
	IMAGEMANAGER->addFrameImage("stage2Tile", L"image/inGame/stage2/stage2Tile_11x9.png", 11, 9);
	IMAGEMANAGER->addImage("black", L"image/blackTile.png");

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

	IMAGEMANAGER->addImage("light", L"image/light.png");
	//이펙트

	//플레이어 
	IMAGEMANAGER->addFrameImage("player_stand", L"image/player/verren_sleep_9x1.png", 9, 1);
	IMAGEMANAGER->addFrameImage("player_dir", L"image/player/verren_direction.png", 2, 1);
}

void stageManager::soundSet()
{
	SOUNDMANAGER->addSound("snd_title", "sound/title/snd_main_theme_original.ogg", true, true);
}
