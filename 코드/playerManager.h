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
	//�÷��̾� ���� �� ���� �� ����
	int SP;				//���� ����Ʈ
	int level;			//����
	int strength;		//�ٷ�
	int agility;		//��ø��
	int perception;		//������
	int vitality;		//�����
	int willpower;		//������
	int hunger;			//����
	int thirst;			//����
	int intoxication;	//�ߵ�
	int pain;			//����
	int	immunity;		//�鿪��
	int morale;			//���
	int sanity;			//�̼�
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

	//���ͼ���
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