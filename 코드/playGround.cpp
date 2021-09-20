#include "stdafx.h"
#include "playGround.h"

#pragma comment(linker,"/entry:WinMainCRTStartup /subsystem:console")


playGround::playGround()
{

}


playGround::~playGround()
{
}

//초기화 함수
HRESULT playGround::init()
{
	gameNode::init(true);;

	_stageManager = new stageManager;
	_stageManager->init();

	//ShowCursor(false);
	return S_OK;
}

//메모리 해제
void playGround::release()
{

}

//연산
void playGround::update()
{
	gameNode::update();

	MOUSEMANAGER->update();
	
	_stageManager->update();

}

//그리기 전용
void playGround::render()
{
	//백버퍼 초기화
	D2DRENDER->BeginRender(D2D1::ColorF::Black);

	CAMERAMANAGER->render();
	_stageManager->render();
	MOUSEMANAGER->render();
	/*D2DRENDER->RenderText(10,0,ConvertStoWS(to_string(TIMEMANAGER->getframe())),30,D2DDEFAULTBRUSH::Yellow);
	D2DRENDER->RenderText(10,30,ConvertStoWS(to_string(TIMEMANAGER->getWorldTime())),30,D2DDEFAULTBRUSH::Yellow);
	D2DRENDER->RenderText(10,60,ConvertStoWS(to_string(TIMEMANAGER->getElapsedTime())),30,D2DDEFAULTBRUSH::Yellow);*/
	//백버퍼에 그린 내용들을 화면에 뿌려라~
	D2DRENDER->EndRender();
}
