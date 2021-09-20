#pragma once
#include "image.h"


enum CTRL
{
	CTRL_SAVE,			//세이브		
	CTRL_LOAD,			//로드
	CTRL_TERRAINDRAW,	//지형
	CTRL_OBJDRAW,		//오브젝트
	CTRL_ERASER,		//지우개
	CTRL_S_RECT,		//렉트 만들기
	CTRL_TILESET_IV,		//타일설정
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
	bool _managerInit;		//매니저들 초기화할꺼니

public:
	gameNode();
	virtual ~gameNode();

	int _ctrlSelect;


	//HRESULT는 마이크로소프트 전용 디버깅 반환자 인데
	//S_OK, E_FAIL, SUCCDED 등으로 출력창에 
	//제대로 초기화가 잘됐는지 아닌지를 보여준다
	virtual HRESULT init();			//초기화 전용 함수
	virtual HRESULT init(bool managerInit);
	virtual void release();			//메모리 해제 전용
	virtual void update();			//연산 전용
	virtual void render();			//그리기 전용

	void setCtrlSelect(int num) { _ctrlSelect = num; }

	LRESULT MainProc(HWND, UINT, WPARAM, LPARAM);
};

