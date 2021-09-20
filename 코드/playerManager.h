#pragma once
#include "gameNode.h"

enum DIR
{
	LEFT, RIGHT
};

struct tagPlayer
{
	image* img;
	RECT rc;
	RECT shadow;
	int x, y;
	int idX, idY;
	int count;
	float speed;
	//플레이어 스텟 및 레벨 및 상태
	int SP;				//스텟 포인트
	int level;			//레벨
	int strength;		//근력
	int agility;		//민첩성
	int perception;		//통찰력
	int vitality;		//생명력
	int willpower;		//의지력
	int hunger;			//공복
	int thirst;			//갈증
	int intoxication;	//중독
	int pain;			//고통
	int	immunity;		//면역력
	int morale;			//사기
	int sanity;			//이성
	DIR dir;

	bool init;
};

struct tagVTile
{
	RECT rc;
	int x, y;
	int currentX;
	int currentY;
	bool isVision = false;;
};

class playerManager : public gameNode
{
private:
	tagPlayer _player;

public:
	playerManager();
	~playerManager();

	HRESULT init();
	void release();
	void update();
	void render();
	void render(int idX, int idY);

	void playerSet();
	void imageSet();

	void visionSet();

	void click();

	void move(float x, float y);

	//게터세터
	tagPlayer getPlayer() { return _player; }
	int getX() { return _player.x; }
	int getY() { return _player.y; }
	int getidX() { return _player.idX; }
	void setIdX(int index) { _player.idX = index; }
	int getidY() { return _player.idY; }
	void setIdY(int index) { _player.idY = index; }
	void setDir(DIR dir) { _player.dir = dir; }
	void setImage(image* img) { _player.img = img; }

	bool getInit() { return _player.init; }
	void setInit(bool is) { _player.init = is; }
	
	void setPosition()
	{
		_player.x = 52;
		_player.y = 52;
		_player.rc = RectMakeCenter(_player.x, _player.y, 20, 20);
	};

	void setPosition(int x, int y)
	{
		_player.x = x*26;
		_player.y = y*26;
		_player.idX = x;
		_player.idY = y;
		_player.rc = RectMakeCenter(_player.x, _player.y, 20, 20);
	};

	void setPosition(POINT pt)
	{
		_player.x = pt.x;
		_player.y = pt.y;
		_player.rc = RectMakeCenter(_player.x, _player.y, 20, 20);
	}

};