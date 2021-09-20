#include "stdafx.h"
#include "playGround.h"

#pragma comment(linker,"/entry:WinMainCRTStartup /subsystem:console")


playGround::playGround()
{

}


playGround::~playGround()
{
}

//�ʱ�ȭ �Լ�
HRESULT playGround::init()
{
	gameNode::init(true);;

	_stageManager = new stageManager;
	_stageManager->init();

	//ShowCursor(false);
	return S_OK;
}

//�޸� ����
void playGround::release()
{

}

//����
void playGround::update()
{
	gameNode::update();

	MOUSEMANAGER->update();
	
	_stageManager->update();

}

//�׸��� ����
void playGround::render()
{
	//����� �ʱ�ȭ
	D2DRENDER->BeginRender(D2D1::ColorF::Black);

	CAMERAMANAGER->render();
	_stageManager->render();
	MOUSEMANAGER->render();
	/*D2DRENDER->RenderText(10,0,ConvertStoWS(to_string(TIMEMANAGER->getframe())),30,D2DDEFAULTBRUSH::Yellow);
	D2DRENDER->RenderText(10,30,ConvertStoWS(to_string(TIMEMANAGER->getWorldTime())),30,D2DDEFAULTBRUSH::Yellow);
	D2DRENDER->RenderText(10,60,ConvertStoWS(to_string(TIMEMANAGER->getElapsedTime())),30,D2DDEFAULTBRUSH::Yellow);*/
	//����ۿ� �׸� ������� ȭ�鿡 �ѷ���~
	D2DRENDER->EndRender();
}
