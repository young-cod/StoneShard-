#pragma once
#include "image.h"


enum CTRL
{
	CTRL_SAVE,			//���̺�		
	CTRL_LOAD,			//�ε�
	CTRL_TERRAINDRAW,	//����
	CTRL_OBJDRAW,		//������Ʈ
	CTRL_ERASER,		//���찳
	CTRL_S_RECT,		//��Ʈ �����
	CTRL_TILESET_IV,		//Ÿ�ϼ���
	CTRL_TILESET_WALL,
	CTRL_TILESET_PLAYER,
	CTRL_TILESET_OBJECT,
	CTRL_TILESET_ENEMY,
	CTRL_TILESET_NONE,
	CTRL_END
};

class gameNode
{
private: 
	bool _managerInit;		//�Ŵ����� �ʱ�ȭ�Ҳ���

public:
	gameNode();
	virtual ~gameNode();

	int _ctrlSelect;


	//HRESULT�� ����ũ�μ���Ʈ ���� ����� ��ȯ�� �ε�
	//S_OK, E_FAIL, SUCCDED ������ ���â�� 
	//����� �ʱ�ȭ�� �ߵƴ��� �ƴ����� �����ش�
	virtual HRESULT init();			//�ʱ�ȭ ���� �Լ�
	virtual HRESULT init(bool managerInit);
	virtual void release();			//�޸� ���� ����
	virtual void update();			//���� ����
	virtual void render();			//�׸��� ����

	void setCtrlSelect(int num) { _ctrlSelect = num; }

	LRESULT MainProc(HWND, UINT, WPARAM, LPARAM);
};

