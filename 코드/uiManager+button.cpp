#include "stdafx.h"
#include "uiManager.h"
#include "playerManager.h"


void uiManager::buttonSet()
{
	//이미지 셋=========================================================================================================
	//인벤토리
	IMAGEMANAGER->addImage("ui_inventory", L"image/UI/s_inventory.png");
	_inven.img = IMAGEMANAGER->findImage("ui_inventory");
	//캐릭터 메뉴
	IMAGEMANAGER->addImage("ui_character_menu", L"image/UI/character_menu/s_character_menu.png");
	IMAGEMANAGER->addImage("ui_character_face", L"image/player/s_verren.png");
	_characterMenu.img = IMAGEMANAGER->findImage("ui_character_menu");
	_characterMenu.face = IMAGEMANAGER->findImage("ui_character_face");

	IMAGEMANAGER->addImage("ui_character_menu1_0", L"image/UI/character_menu/s_charbutton01_0.png");
	IMAGEMANAGER->addImage("ui_character_menu1_1", L"image/UI/character_menu/s_charbutton01_1.png");
	IMAGEMANAGER->addImage("ui_character_menu1_2", L"image/UI/character_menu/s_charbutton01_2.png");

	IMAGEMANAGER->addImage("ui_character_menu2_0", L"image/UI/character_menu/s_charbutton02_0.png");
	IMAGEMANAGER->addImage("ui_character_menu2_1", L"image/UI/character_menu/s_charbutton02_1.png");
	IMAGEMANAGER->addImage("ui_character_menu2_2", L"image/UI/character_menu/s_charbutton02_2.png");

	IMAGEMANAGER->addImage("ui_character_menu3_0", L"image/UI/character_menu/s_charbutton03_0.png");
	IMAGEMANAGER->addImage("ui_character_menu3_1", L"image/UI/character_menu/s_charbutton03_1.png");
	IMAGEMANAGER->addImage("ui_character_menu3_2", L"image/UI/character_menu/s_charbutton03_2.png");

	IMAGEMANAGER->addImage("ui_character_menu4_0", L"image/UI/character_menu/s_charbutton04_0.png");
	IMAGEMANAGER->addImage("ui_character_menu4_1", L"image/UI/character_menu/s_charbutton04_1.png");
	IMAGEMANAGER->addImage("ui_character_menu4_2", L"image/UI/character_menu/s_charbutton04_2.png");

	//어빌리티 툴 관련
	IMAGEMANAGER->addImage("btnInven0", L"image/UI/abilities/s_gui_button_inventory_0.png");
	IMAGEMANAGER->addImage("btnInven1", L"image/UI/abilities/s_gui_button_inventory_1.png");
	IMAGEMANAGER->addImage("btnInven2", L"image/UI/abilities/s_gui_button_inventory_2.png");

	IMAGEMANAGER->addImage("btnChar0", L"image/UI/abilities/s_gui_button_char_0.png");
	IMAGEMANAGER->addImage("btnChar1", L"image/UI/abilities/s_gui_button_char_1.png");
	IMAGEMANAGER->addImage("btnChar2", L"image/UI/abilities/s_gui_button_char_2.png");

	IMAGEMANAGER->addImage("btnSkill0", L"image/UI/abilities/s_gui_button_skills_0.png");
	IMAGEMANAGER->addImage("btnSkill1", L"image/UI/abilities/s_gui_button_skills_1.png");
	IMAGEMANAGER->addImage("btnSkill2", L"image/UI/abilities/s_gui_button_skills_2.png");

	IMAGEMANAGER->addImage("btnQuest0", L"image/UI/abilities/s_gui_button_quests_0.png");
	IMAGEMANAGER->addImage("btnQuest1", L"image/UI/abilities/s_gui_button_quests_1.png");
	IMAGEMANAGER->addImage("btnQuest2", L"image/UI/abilities/s_gui_button_quests_2.png");

	IMAGEMANAGER->addImage("btnAction0", L"image/UI/abilities/s_gui_button_actions_0.png");
	IMAGEMANAGER->addImage("btnAction1", L"image/UI/abilities/s_gui_button_actions_1.png");
	IMAGEMANAGER->addImage("btnAction2", L"image/UI/abilities/s_gui_button_actions_2.png");

	IMAGEMANAGER->addImage("btnSkip0", L"image/UI/abilities/s_gui_button_skipturn_0.png");
	IMAGEMANAGER->addImage("btnSkip1", L"image/UI/abilities/s_gui_button_skipturn_1.png");
	IMAGEMANAGER->addImage("btnSkip2", L"image/UI/abilities/s_gui_button_skipturn_2.png");

	IMAGEMANAGER->addImage("btnSetting0", L"image/UI/abilities/s_gui_button_settings_0.png");
	IMAGEMANAGER->addImage("btnSetting1", L"image/UI/abilities/s_gui_button_settings_1.png");
	IMAGEMANAGER->addImage("btnSetting2", L"image/UI/abilities/s_gui_button_settings_2.png");

	_characterMenu1 = new button;
	_characterMenu2 = new button;
	_characterMenu3 = new button;
	_characterMenu4 = new button;

	_characterSP = new button;
	_characterStrength = new button;
	_characterAgility = new button;
	_characterPerception = new button;
	_characterVitality = new button;
	_characterWillpower = new button;

	_char_hunger = new button;
	_char_thirst = new button;
	_char_intoxication = new button;
	_char_pain = new button;
	_char_immunity = new button;

	_char_morale = new button;
	_char_sanity = new button;

	_char_trouble = new button;

	_btnInven = new button;
	_btnCharacterMenu = new button;
	_btnAbilities = new button;
	_btnQuests = new button;
	_btnModesAndActions = new button;
	_btnSkipTurn = new button;
	_btnGameMenu = new button;

	_characterMenu1->init(IMAGEMANAGER->findImage("ui_character_menu1_0"));
	_characterMenu2->init(IMAGEMANAGER->findImage("ui_character_menu2_0"));
	_characterMenu3->init(IMAGEMANAGER->findImage("ui_character_menu3_0"));
	_characterMenu4->init(IMAGEMANAGER->findImage("ui_character_menu4_0"));

	_btnInven->init(IMAGEMANAGER->findImage("btnInven0"));
	_btnCharacterMenu->init(IMAGEMANAGER->findImage("btnChar0"));
	_btnAbilities->init(IMAGEMANAGER->findImage("btnSkill0"));
	_btnQuests->init(IMAGEMANAGER->findImage("btnQuest0"));
	_btnModesAndActions->init(IMAGEMANAGER->findImage("btnAction0"));
	_btnSkipTurn->init(IMAGEMANAGER->findImage("btnSkip0"));
	_btnGameMenu->init(IMAGEMANAGER->findImage("btnSetting0"));


	//렉트 셋===========================================================================================================================
	//인벤토리
	_inven.rc = RectMake(WINSIZEX - _inven.img->getWidth(), 0, _inven.img->getWidth(), _inven.img->getHeight());
	//캐릭터 메뉴
	_characterMenu.rc = RectMake(0, 0, _characterMenu.img->getWidth(), _characterMenu.img->getHeight());
	_characterMenu1->setRECT(RectMake(26, 268, _characterMenu1->getImage()->getWidth(), _characterMenu1->getImage()->getHeight()));
	_characterMenu2->setRECT(RectMake(_characterMenu1->getRECT().right, 268, _characterMenu2->getImage()->getWidth(), _characterMenu2->getImage()->getHeight()));
	_characterMenu3->setRECT(RectMake(_characterMenu2->getRECT().right, 268, _characterMenu3->getImage()->getWidth(), _characterMenu3->getImage()->getHeight()));
	_characterMenu4->setRECT(RectMake(_characterMenu3->getRECT().right, 268, _characterMenu4->getImage()->getWidth(), _characterMenu4->getImage()->getHeight()));

	_characterSP->setRECT(RectMake(67, 216, 88, 17));
	_characterStrength->setRECT(RectMake(162, 185, 153, 16));
	_characterAgility->setRECT(RectMake(162, 201, 153, 16));
	_characterPerception->setRECT(RectMake(162, 217, 153, 16));
	_characterVitality->setRECT(RectMake(162, 233, 153, 16));
	_characterWillpower->setRECT(RectMake(162, 249, 153, 16));

	_char_hunger->setRECT(RectMake(189, 317, 105, 12));
	_char_thirst->setRECT(RectMake(189, 330, 105, 12));
	_char_intoxication->setRECT(RectMake(189, 343, 105, 12));
	_char_pain->setRECT(RectMake(189, 356, 105, 12));
	_char_immunity->setRECT(RectMake(189, 369, 105, 12));

	_char_morale->setRECT(RectMake(189,405,105,12));
	_char_sanity->setRECT(RectMake(189,417,105,12));

	_char_trouble->setRECT(RectMake(189, 455, 105, 12));

	//어빌리티 툴 관련
	_btnInven->setRECT(RectMake(_noabilities.rc.left + 44, WINSIZEY - _noabilities.img->getHeight() + 29, _btnInven->getImage()->getWidth(), _btnInven->getImage()->getHeight()));
	_btnCharacterMenu->setRECT(RectMake(_noabilities.rc.left + 65, WINSIZEY - _noabilities.img->getHeight() + 29, _btnCharacterMenu->getImage()->getWidth(), _btnCharacterMenu->getImage()->getHeight()));
	_btnAbilities->setRECT(RectMake(_noabilities.rc.left + 86, WINSIZEY - _noabilities.img->getHeight() + 29, _btnAbilities->getImage()->getWidth(), _btnAbilities->getImage()->getHeight()));
	_btnQuests->setRECT(RectMake(_noabilities.rc.left + 107, WINSIZEY - _noabilities.img->getHeight() + 29, _btnQuests->getImage()->getWidth(), _btnQuests->getImage()->getHeight()));
	_btnModesAndActions->setRECT(RectMake(_noabilities.rc.left + 531, WINSIZEY - _noabilities.img->getHeight() + 29, _btnModesAndActions->getImage()->getWidth(), _btnModesAndActions->getImage()->getHeight()));
	_btnSkipTurn->setRECT(RectMake(_noabilities.rc.left + 563, WINSIZEY - _noabilities.img->getHeight() + 29, _btnSkipTurn->getImage()->getWidth(), _btnSkipTurn->getImage()->getHeight()));
	_btnGameMenu->setRECT(RectMake(_noabilities.rc.left + 584, WINSIZEY - _noabilities.img->getHeight() + 29, _btnGameMenu->getImage()->getWidth(), _btnGameMenu->getImage()->getHeight()));

}

void uiManager::buttonControl()
{
	abilMenuButton();

	//인벤토리
	if (KEYMANAGER->isOnceKeyDown('I'))
	{
		if (_inven.isOpen)_inven.isOpen = false;
		else _inven.isOpen = true;
	}
	if (_inven.isOpen)invenMenuButton();
	//캐릭터 메뉴
	if (KEYMANAGER->isOnceKeyDown('C'))
	{
		if (_characterMenu.isOpen)_characterMenu.isOpen = false;
		else _characterMenu.isOpen = true;
	}
	if (_characterMenu.isOpen)charMenuButton();

	//어빌리티 툴 관련


}

void uiManager::buttonRender()
{

	//인벤
	if (_inven.isOpen && !_btnGameMenu->getIsClick())_inven.img->uiRender(true, _inven.rc.left, _inven.rc.top);
	//캐릭터 메뉴
	if (_characterMenu.isOpen && !_btnGameMenu->getIsClick())
	{
		_characterMenu.img->uiRender(true, _characterMenu.rc.left, _characterMenu.rc.top);
		_characterMenu.face->uiRender(true, 28, 183);

		D2DRENDER->RenderText(72, 186, L"베렌", D2D1COLOR::White, 1.f, 11, DWRITE_TEXT_ALIGNMENT_LEADING, L"StoneshardFont_new");
		D2DRENDER->RenderText(72, 202, L"유물 사냥꾼", D2D1COLOR::BurlyWood, 1.f, 10, DWRITE_TEXT_ALIGNMENT_LEADING, L"StoneshardFont_new");

		if (PtInRect(&_characterSP->getRECT(), _ptMouse)) D2DRENDER->FillRectangle(_characterSP->getRECT(), D2D1COLOR::BurlyWood, 0.1f);
		D2DRENDER->RenderTextField(
			_characterSP->getRECT().left + 5, _characterSP->getRECT().top - 1,
			L"SP : ",
			D2D1COLOR::BurlyWood,
			12,
			_characterSP->getWidth(), _characterSP->getHeight(),
			1.f, DWRITE_TEXT_ALIGNMENT_LEADING,
			L"StoneshardFont_new");
		D2DRENDER->RenderTextField(
			_characterSP->getRECT().left + 30, _characterSP->getRECT().top - 1,
			ConvertStoWS(to_string(_player->getPlayer().SP)),
			D2D1COLOR::White,
			12,
			_characterSP->getWidth(), _characterSP->getHeight(),
			1.f, DWRITE_TEXT_ALIGNMENT_LEADING,
			L"StoneshardFont_new");

		D2DRENDER->RenderText(30, 237, L"레벨 ", D2D1COLOR::BurlyWood, 1.f, 12, DWRITE_TEXT_ALIGNMENT_LEADING, L"StoneshardFont_new");
		D2DRENDER->RenderText(60, 237, ConvertStoWS(to_string(_player->getPlayer().level)), D2D1COLOR::White, 1.f, 12, DWRITE_TEXT_ALIGNMENT_LEADING, L"StoneshardFont_new");

		if (PtInRect(&_characterStrength->getRECT(), _ptMouse)) D2DRENDER->FillRectangle(_characterStrength->getRECT(), D2D1COLOR::BurlyWood, 0.1f);
		D2DRENDER->RenderTextField(
			_characterStrength->getRECT().left, _characterStrength->getRECT().top,
			L"근력",
			D2D1COLOR::BurlyWood,
			11,
			_characterStrength->getWidth(), _characterStrength->getHeight(),
			1.f, DWRITE_TEXT_ALIGNMENT_LEADING,
			L"StoneshardFont_new");
		D2DRENDER->RenderTextField(
			_characterStrength->getRECT().left - 5, _characterStrength->getRECT().top,
			ConvertStoWS(to_string(_player->getPlayer().strength)),
			D2D1COLOR::White,
			12,
			_characterStrength->getWidth(), _characterStrength->getHeight(),
			1.f, DWRITE_TEXT_ALIGNMENT_TRAILING,
			L"StoneshardFont_new");

		if (PtInRect(&_characterAgility->getRECT(), _ptMouse)) D2DRENDER->FillRectangle(_characterAgility->getRECT(), D2D1COLOR::BurlyWood, 0.1f);
		D2DRENDER->RenderTextField(
			_characterAgility->getRECT().left, _characterAgility->getRECT().top,
			L"민첩성",
			D2D1COLOR::BurlyWood,
			11,
			_characterAgility->getWidth(), _characterAgility->getHeight(),
			1.f, DWRITE_TEXT_ALIGNMENT_LEADING,
			L"StoneshardFont_new");
		D2DRENDER->RenderTextField(
			_characterAgility->getRECT().left - 5, _characterAgility->getRECT().top,
			ConvertStoWS(to_string(_player->getPlayer().agility)),
			D2D1COLOR::White,
			12,
			_characterAgility->getWidth(), _characterAgility->getHeight(),
			1.f, DWRITE_TEXT_ALIGNMENT_TRAILING,
			L"StoneshardFont_new");

		if (PtInRect(&_characterPerception->getRECT(), _ptMouse)) D2DRENDER->FillRectangle(_characterPerception->getRECT(), D2D1COLOR::BurlyWood, 0.1f);
		D2DRENDER->RenderTextField(
			_characterPerception->getRECT().left, _characterPerception->getRECT().top,
			L"통찰력",
			D2D1COLOR::BurlyWood,
			11,
			_characterPerception->getWidth(), _characterPerception->getHeight(),
			1.f, DWRITE_TEXT_ALIGNMENT_LEADING,
			L"StoneshardFont_new");
		D2DRENDER->RenderTextField(
			_characterPerception->getRECT().left - 5, _characterPerception->getRECT().top,
			ConvertStoWS(to_string(_player->getPlayer().perception)),
			D2D1COLOR::White,
			12,
			_characterPerception->getWidth(), _characterPerception->getHeight(),
			1.f, DWRITE_TEXT_ALIGNMENT_TRAILING,
			L"StoneshardFont_new");

		if (PtInRect(&_characterVitality->getRECT(), _ptMouse)) D2DRENDER->FillRectangle(_characterVitality->getRECT(), D2D1COLOR::BurlyWood, 0.1f);
		D2DRENDER->RenderTextField(
			_characterVitality->getRECT().left, _characterVitality->getRECT().top,
			L"생명력",
			D2D1COLOR::BurlyWood,
			11,
			_characterVitality->getWidth(), _characterVitality->getHeight(),
			1.f, DWRITE_TEXT_ALIGNMENT_LEADING,
			L"StoneshardFont_new");
		D2DRENDER->RenderTextField(
			_characterVitality->getRECT().left - 5, _characterVitality->getRECT().top,
			ConvertStoWS(to_string(_player->getPlayer().vitality)),
			D2D1COLOR::White,
			12,
			_characterVitality->getWidth(), _characterVitality->getHeight(),
			1.f, DWRITE_TEXT_ALIGNMENT_TRAILING,
			L"StoneshardFont_new");

		if (PtInRect(&_characterWillpower->getRECT(), _ptMouse)) D2DRENDER->FillRectangle(_characterWillpower->getRECT(), D2D1COLOR::BurlyWood, 0.1f);
		D2DRENDER->RenderTextField(
			_characterWillpower->getRECT().left, _characterWillpower->getRECT().top,
			L"의지력",
			D2D1COLOR::BurlyWood,
			11,
			_characterWillpower->getWidth(), _characterWillpower->getHeight(),
			1.f, DWRITE_TEXT_ALIGNMENT_LEADING,
			L"StoneshardFont_new");
		D2DRENDER->RenderTextField(
			_characterWillpower->getRECT().left - 5, _characterWillpower->getRECT().top,
			ConvertStoWS(to_string(_player->getPlayer().willpower)),
			D2D1COLOR::White,
			12,
			_characterWillpower->getWidth(), _characterWillpower->getHeight(),
			1.f, DWRITE_TEXT_ALIGNMENT_TRAILING,
			L"StoneshardFont_new");

		_characterMenu1->getImage()->uiRender(true, _characterMenu1->getRECT().left, _characterMenu1->getRECT().top);

		_characterMenu2->getImage()->uiRender(true, _characterMenu2->getRECT().left, _characterMenu2->getRECT().top);
		if (_characterMenu2->getIsClick())
		{
			D2DRENDER->RenderText(230, 295, L"체력", 11, D2DDEFAULTBRUSH::White, DWRITE_TEXT_ALIGNMENT_CENTER, L"StoneshardFont_new");
			if (PtInRect(&_char_hunger->getRECT(), _ptMouse))D2DRENDER->FillRectangle(_char_hunger->getRECT(), D2D1COLOR::BurlyWood, 0.1f);
			D2DRENDER->RenderTextField(_char_hunger->getRECT().left, _char_hunger->getRECT().top,
				L"공복", D2D1COLOR::BurlyWood, 10,
				_char_hunger->getRECT().right - _char_hunger->getRECT().left, _char_hunger->getRECT().bottom - _char_hunger->getRECT().top,
				1.f, DWRITE_TEXT_ALIGNMENT_LEADING,
				L"StoneshardFont_new");
			string str = to_string(_player->getPlayer().hunger);
			str.append("%");
			D2DRENDER->RenderTextField(
				_char_hunger->getRECT().left, _char_hunger->getRECT().top,
				ConvertStoWS(str),
				D2D1COLOR::White,
				10,
				_char_hunger->getWidth(), _char_hunger->getHeight(),
				1.f, DWRITE_TEXT_ALIGNMENT_TRAILING,
				L"StoneshardFont_new");
			if (PtInRect(&_char_thirst->getRECT(), _ptMouse))D2DRENDER->FillRectangle(_char_thirst->getRECT(), D2D1COLOR::BurlyWood, 0.1f);
			D2DRENDER->RenderTextField(_char_thirst->getRECT().left, _char_thirst->getRECT().top,
				L"갈증", D2D1COLOR::BurlyWood, 10,
				_char_thirst->getRECT().right - _char_thirst->getRECT().left, _char_thirst->getRECT().bottom - _char_thirst->getRECT().top,
				1.f, DWRITE_TEXT_ALIGNMENT_LEADING,
				L"StoneshardFont_new");
			str = to_string(_player->getPlayer().thirst);
			str.append("%");
			D2DRENDER->RenderTextField(
				_char_thirst->getRECT().left, _char_thirst->getRECT().top,
				ConvertStoWS(str),
				D2D1COLOR::White,
				10,
				_char_thirst->getWidth(), _char_thirst->getHeight(),
				1.f, DWRITE_TEXT_ALIGNMENT_TRAILING,
				L"StoneshardFont_new");
			if (PtInRect(&_char_intoxication->getRECT(), _ptMouse))D2DRENDER->FillRectangle(_char_intoxication->getRECT(), D2D1COLOR::BurlyWood, 0.1f);
			D2DRENDER->RenderTextField(_char_intoxication->getRECT().left, _char_intoxication->getRECT().top,
				L"중독", D2D1COLOR::BurlyWood, 10,
				_char_intoxication->getRECT().right - _char_intoxication->getRECT().left, _char_intoxication->getRECT().bottom - _char_intoxication->getRECT().top,
				1.f, DWRITE_TEXT_ALIGNMENT_LEADING,
				L"StoneshardFont_new");
			 str = to_string(_player->getPlayer().intoxication);
			str.append("%");
			D2DRENDER->RenderTextField(
				_char_intoxication->getRECT().left, _char_intoxication->getRECT().top,
				ConvertStoWS(str),
				D2D1COLOR::White,
				10,
				_char_intoxication->getWidth(), _char_intoxication->getHeight(),
				1.f, DWRITE_TEXT_ALIGNMENT_TRAILING,
				L"StoneshardFont_new");
			if (PtInRect(&_char_pain->getRECT(), _ptMouse))D2DRENDER->FillRectangle(_char_pain->getRECT(), D2D1COLOR::BurlyWood, 0.1f);
			D2DRENDER->RenderTextField(_char_pain->getRECT().left, _char_pain->getRECT().top,
				L"고통", D2D1COLOR::BurlyWood, 10,
				_char_pain->getRECT().right - _char_pain->getRECT().left, _char_pain->getRECT().bottom - _char_pain->getRECT().top,
				1.f, DWRITE_TEXT_ALIGNMENT_LEADING,
				L"StoneshardFont_new");
			 str = to_string(_player->getPlayer().pain);
			str.append("%");
			D2DRENDER->RenderTextField(
				_char_pain->getRECT().left, _char_pain->getRECT().top,
				ConvertStoWS(str),
				D2D1COLOR::White,
				10,
				_char_pain->getWidth(), _char_pain->getHeight(),
				1.f, DWRITE_TEXT_ALIGNMENT_TRAILING,
				L"StoneshardFont_new");
			if (PtInRect(&_char_immunity->getRECT(), _ptMouse))D2DRENDER->FillRectangle(_char_immunity->getRECT(), D2D1COLOR::BurlyWood, 0.1f);
			D2DRENDER->RenderTextField(_char_immunity->getRECT().left, _char_immunity->getRECT().top,
				L"면역력", D2D1COLOR::BurlyWood, 10,
				_char_immunity->getRECT().right - _char_immunity->getRECT().left, _char_immunity->getRECT().bottom - _char_immunity->getRECT().top,
				1.f, DWRITE_TEXT_ALIGNMENT_LEADING,
				L"StoneshardFont_new");
			 str = to_string(_player->getPlayer().immunity);
			str.append("%");
			D2DRENDER->RenderTextField(
				_char_immunity->getRECT().left, _char_immunity->getRECT().top,
				ConvertStoWS(str),
				D2D1COLOR::White,
				10,
				_char_immunity->getWidth(), _char_immunity->getHeight(),
				1.f, DWRITE_TEXT_ALIGNMENT_TRAILING,
				L"StoneshardFont_new");
			D2DRENDER->RenderText(225, 380, L"정신력", 11, D2DDEFAULTBRUSH::White, DWRITE_TEXT_ALIGNMENT_CENTER, L"StoneshardFont_new");
			if (PtInRect(&_char_morale->getRECT(), _ptMouse))D2DRENDER->FillRectangle(_char_morale->getRECT(), D2D1COLOR::BurlyWood, 0.1f);
			D2DRENDER->RenderTextField(_char_morale->getRECT().left, _char_morale->getRECT().top,
				L"사기", D2D1COLOR::BurlyWood, 10,
				_char_morale->getRECT().right - _char_morale->getRECT().left, _char_morale->getRECT().bottom - _char_morale->getRECT().top,
				1.f, DWRITE_TEXT_ALIGNMENT_LEADING,
				L"StoneshardFont_new");
			 str = to_string(_player->getPlayer().morale);
			str.append("%");
			D2DRENDER->RenderTextField(
				_char_morale->getRECT().left, _char_morale->getRECT().top,
				ConvertStoWS(str),
				D2D1COLOR::White,
				10,
				_char_morale->getWidth(), _char_morale->getHeight(),
				1.f, DWRITE_TEXT_ALIGNMENT_TRAILING,
				L"StoneshardFont_new");
			if (PtInRect(&_char_sanity->getRECT(), _ptMouse))D2DRENDER->FillRectangle(_char_sanity->getRECT(), D2D1COLOR::BurlyWood, 0.1f);
			D2DRENDER->RenderTextField(_char_sanity->getRECT().left, _char_sanity->getRECT().top,
				L"이성", D2D1COLOR::BurlyWood, 10,
				_char_sanity->getRECT().right - _char_sanity->getRECT().left, _char_sanity->getRECT().bottom - _char_sanity->getRECT().top,
				1.f, DWRITE_TEXT_ALIGNMENT_LEADING,
				L"StoneshardFont_new");
			 str = to_string(_player->getPlayer().sanity);
			str.append("%");
			D2DRENDER->RenderTextField(
				_char_sanity->getRECT().left, _char_sanity->getRECT().top,
				ConvertStoWS(str),
				D2D1COLOR::White,
				10,
				_char_sanity->getWidth(), _char_sanity->getHeight(),
				1.f, DWRITE_TEXT_ALIGNMENT_TRAILING,
				L"StoneshardFont_new");
			D2DRENDER->RenderText(230, 430, L"질병", 11, D2DDEFAULTBRUSH::White, DWRITE_TEXT_ALIGNMENT_CENTER, L"StoneshardFont_new");
			if (PtInRect(&_char_trouble->getRECT(), _ptMouse))D2DRENDER->FillRectangle(_char_trouble->getRECT(), D2D1COLOR::BurlyWood, 0.1f);
			//이상없음 부분에 문자열 받아서 넣기
			D2DRENDER->RenderTextField(_char_trouble->getRECT().left, _char_trouble->getRECT().top,
				L"이상없음", D2D1COLOR::BurlyWood, 10,
				_char_trouble->getRECT().right - _char_trouble->getRECT().left, _char_trouble->getRECT().bottom - _char_trouble->getRECT().top,
				1.f, DWRITE_TEXT_ALIGNMENT_LEADING,
				L"StoneshardFont_new");
			_characterMenu.line->uiRender(true, 185, 293);
			_character_body.img->uiRender(true, _character_body.rc.left, _character_body.rc.top);
		}

		_characterMenu3->getImage()->uiRender(true, _characterMenu3->getRECT().left, _characterMenu3->getRECT().top);

		_characterMenu4->getImage()->uiRender(true, _characterMenu4->getRECT().left, _characterMenu4->getRECT().top);
	}
	//어빌리티 툴 관련
	_btnInven->getImage()->uiRender(true, _btnInven->getRECT().left, _btnInven->getRECT().top);
	_btnCharacterMenu->getImage()->uiRender(true, _btnCharacterMenu->getRECT().left, _btnCharacterMenu->getRECT().top);
	_btnAbilities->getImage()->uiRender(true, _btnAbilities->getRECT().left, _btnAbilities->getRECT().top);
	_btnQuests->getImage()->uiRender(true, _btnQuests->getRECT().left, _btnQuests->getRECT().top);
	_btnModesAndActions->getImage()->uiRender(true, _btnModesAndActions->getRECT().left, _btnModesAndActions->getRECT().top);
	_btnSkipTurn->getImage()->uiRender(true, _btnSkipTurn->getRECT().left, _btnSkipTurn->getRECT().top);
	_btnGameMenu->getImage()->uiRender(true, _btnGameMenu->getRECT().left, _btnGameMenu->getRECT().top);

}

void uiManager::charMenuButton()
{
	if (PtInRect(&_characterMenu1->getRECT(), _ptMouse))
	{
		if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))	_characterMenu1->setImage(IMAGEMANAGER->findImage("ui_character_menu1_1"));
		if (KEYMANAGER->isOnceKeyUp(VK_LBUTTON))
		{
			_characterMenu1->setImage(IMAGEMANAGER->findImage("ui_character_menu1_2"));
			_characterMenu2->setImage(IMAGEMANAGER->findImage("ui_character_menu2_0"));
			_characterMenu3->setImage(IMAGEMANAGER->findImage("ui_character_menu3_0"));
			_characterMenu4->setImage(IMAGEMANAGER->findImage("ui_character_menu4_0"));

			_characterMenu1->setIsClick(true);
			_characterMenu2->setIsClick(false);
			_characterMenu3->setIsClick(false);
			_characterMenu4->setIsClick(false);
		}
	}

	if (PtInRect(&_characterMenu2->getRECT(), _ptMouse))
	{
		if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))	_characterMenu2->setImage(IMAGEMANAGER->findImage("ui_character_menu2_1"));
		if (KEYMANAGER->isOnceKeyUp(VK_LBUTTON))
		{
			_characterMenu1->setImage(IMAGEMANAGER->findImage("ui_character_menu1_0"));
			_characterMenu2->setImage(IMAGEMANAGER->findImage("ui_character_menu2_2"));
			_characterMenu3->setImage(IMAGEMANAGER->findImage("ui_character_menu3_0"));
			_characterMenu4->setImage(IMAGEMANAGER->findImage("ui_character_menu4_0"));

			_characterMenu1->setIsClick(false);
			_characterMenu2->setIsClick(true);
			_characterMenu3->setIsClick(false);
			_characterMenu4->setIsClick(false);
		}
	}
	if (PtInRect(&_characterMenu3->getRECT(), _ptMouse))
	{
		if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))	_characterMenu3->setImage(IMAGEMANAGER->findImage("ui_character_menu3_1"));
		if (KEYMANAGER->isOnceKeyUp(VK_LBUTTON))
		{
			_characterMenu1->setImage(IMAGEMANAGER->findImage("ui_character_menu1_0"));
			_characterMenu2->setImage(IMAGEMANAGER->findImage("ui_character_menu2_0"));
			_characterMenu3->setImage(IMAGEMANAGER->findImage("ui_character_menu3_2"));
			_characterMenu4->setImage(IMAGEMANAGER->findImage("ui_character_menu4_0"));

			_characterMenu1->setIsClick(false);
			_characterMenu2->setIsClick(false);
			_characterMenu3->setIsClick(true);
			_characterMenu4->setIsClick(false);
		}
	}
	if (PtInRect(&_characterMenu4->getRECT(), _ptMouse))
	{
		if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))	_characterMenu4->setImage(IMAGEMANAGER->findImage("ui_character_menu4_1"));
		if (KEYMANAGER->isOnceKeyUp(VK_LBUTTON))
		{
			_characterMenu1->setImage(IMAGEMANAGER->findImage("ui_character_menu1_0"));
			_characterMenu2->setImage(IMAGEMANAGER->findImage("ui_character_menu2_0"));
			_characterMenu3->setImage(IMAGEMANAGER->findImage("ui_character_menu3_0"));
			_characterMenu4->setImage(IMAGEMANAGER->findImage("ui_character_menu4_2"));

			_characterMenu1->setIsClick(false);
			_characterMenu2->setIsClick(false);
			_characterMenu3->setIsClick(false);
			_characterMenu4->setIsClick(true);
		}
	}
}

void uiManager::invenMenuButton()
{
}

void uiManager::abilMenuButton()
{
	//게임메뉴 껏을때만
	if (!_btnGameMenu->getIsClick())
	{
		if (PtInRect(&_btnInven->getRECT(), _ptMouse))
		{
			if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))	_btnInven->setImage(IMAGEMANAGER->findImage("btnInven1"));
			if (KEYMANAGER->isOnceKeyUp(VK_LBUTTON))
			{
				if (_inven.isOpen)
				{
					_inven.isOpen = false;

					_btnInven->setImage(IMAGEMANAGER->findImage("btnInven0"));
					_btnAbilities->setImage(IMAGEMANAGER->findImage("btnSkill0"));

					_btnInven->setIsClick(false);
					_btnAbilities->setIsClick(false);
				}
				else
				{
					_inven.isOpen = true;

					_btnInven->setImage(IMAGEMANAGER->findImage("btnInven2"));
					_btnAbilities->setImage(IMAGEMANAGER->findImage("btnSkill0"));

					_btnInven->setIsClick(true);
					_btnAbilities->setIsClick(false);
				}
			}
		}
		if (PtInRect(&_btnCharacterMenu->getRECT(), _ptMouse))
		{
			if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))	_btnCharacterMenu->setImage(IMAGEMANAGER->findImage("btnChar1"));
			if (KEYMANAGER->isOnceKeyUp(VK_LBUTTON))
			{
				if (_characterMenu.isOpen)_characterMenu.isOpen = false;
				else _characterMenu.isOpen = true;

				_btnCharacterMenu->setImage(IMAGEMANAGER->findImage("btnChar2"));

				_btnCharacterMenu->setIsClick(true);
			}
		}
		if (PtInRect(&_btnAbilities->getRECT(), _ptMouse))
		{
			if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))	_btnAbilities->setImage(IMAGEMANAGER->findImage("btnSkill1"));
			if (KEYMANAGER->isOnceKeyUp(VK_LBUTTON))
			{
				_btnInven->setImage(IMAGEMANAGER->findImage("btnInven0"));
				_btnAbilities->setImage(IMAGEMANAGER->findImage("btnSkill2"));

				_btnInven->setIsClick(false);
				_btnAbilities->setIsClick(true);
			}
		}
		if (PtInRect(&_btnQuests->getRECT(), _ptMouse))
		{
			if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))	_btnQuests->setImage(IMAGEMANAGER->findImage("btnQuest1"));
			if (KEYMANAGER->isOnceKeyUp(VK_LBUTTON))
			{
				_btnQuests->setImage(IMAGEMANAGER->findImage("btnQuest2"));

				_btnQuests->setIsClick(true);
			}
		}
		if (PtInRect(&_btnModesAndActions->getRECT(), _ptMouse))
		{
			if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))	_btnModesAndActions->setImage(IMAGEMANAGER->findImage("btnAction1"));
			if (KEYMANAGER->isOnceKeyUp(VK_LBUTTON))
			{
				_btnModesAndActions->setImage(IMAGEMANAGER->findImage("btnAction2"));

				_btnModesAndActions->setIsClick(true);
			}
		}
		if (PtInRect(&_btnSkipTurn->getRECT(), _ptMouse))
		{
			if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))	_btnSkipTurn->setImage(IMAGEMANAGER->findImage("btnSkip1"));
			if (KEYMANAGER->isOnceKeyUp(VK_LBUTTON))
			{
				_btnSkipTurn->setImage(IMAGEMANAGER->findImage("btnSkip2"));

				_btnSkipTurn->setIsClick(true);
			}
		}
	}

	if (PtInRect(&_btnGameMenu->getRECT(), _ptMouse))
	{
		if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))	_btnGameMenu->setImage(IMAGEMANAGER->findImage("btnSetting1"));
		if (KEYMANAGER->isOnceKeyUp(VK_LBUTTON))
		{
			if (_btnGameMenu->getIsClick())
			{
				_btnGameMenu->setImage(IMAGEMANAGER->findImage("btnSetting0"));

				_btnGameMenu->setIsClick(false);
			}
			else
			{
				_btnGameMenu->setImage(IMAGEMANAGER->findImage("btnSetting2"));

				_btnInven->setIsClick(false);
				_btnCharacterMenu->setIsClick(false);
				_btnAbilities->setIsClick(false);
				_btnQuests->setIsClick(false);
				_btnModesAndActions->setIsClick(false);
				_btnSkipTurn->setIsClick(false);
				_btnGameMenu->setIsClick(true);
			}
		}
	}
}
