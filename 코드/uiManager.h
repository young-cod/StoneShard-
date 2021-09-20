#pragma once
#include "singletonBase.h"
#include "button.h"

class playerManager;

struct tagUI
{
	image* img;
	image* face;
	RECT rc;
	bool isOpen;
	image* line;
};

class uiManager : public singletonBase<uiManager>
{
private:
	tagUI _noabilities;
	tagUI _inven;

	//===========================================================캐릭터 메뉴=======================================================================
	tagUI _characterMenu;
	button* _characterMenu3;
	button* _characterMenu4;
	button* _characterSP;
	button* _characterStrength;
	button* _characterAgility;
	button* _characterPerception;
	button* _characterVitality;
	button* _characterWillpower;
	//캐릭터 메뉴 -1-
	button* _characterMenu1;
	//캐릭터 메뉴 -2-
	button* _characterMenu2;
	tagUI _character_body;
	button* _char_hunger;
	button* _char_thirst;
	button* _char_intoxication;
	button* _char_pain;
	button* _char_immunity;
	button* _char_morale;
	button* _char_sanity;
	button* _char_trouble;
	//캐릭터 메뉴 -3-

	//===========================================================어빌리티 메뉴=======================================================================
	button* _btnInven;
	button* _btnCharacterMenu;
	button* _btnAbilities;
	button* _btnQuests;
	button* _btnModesAndActions;
	button* _btnSkipTurn;
	button* _btnGameMenu;



	playerManager* _player;
public:
	HRESULT init();
	void release();
	void update();
	void render();

	void setup();

	void imageSet();

	//버튼 관련
	void buttonSet();
	void buttonControl();
	void buttonRender();

	void charMenuButton();
	void invenMenuButton();
	void abilMenuButton();

	void linkPlayer(playerManager* player) { _player = player; }
};

