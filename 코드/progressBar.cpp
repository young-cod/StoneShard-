#include "stdafx.h"
#include "progressBar.h"

progressBar::progressBar()
{
}

progressBar::~progressBar()
{
}

HRESULT progressBar::init(float x, float y, float width, float height)
{
	_x = x;
	_y = y;
	_width = width;

	_rc = RectMake(x, y, width, height);

	barTop = IMAGEMANAGER->addImage("hpfront", L"hpBarfront.png", 568, 50);
	barBottom = IMAGEMANAGER->addImage("hpback", L"hpBarback.png", 600, 50);
	//안되길래 가로세로 넣어봤습니다

	return S_OK;
}

void progressBar::release()
{
}

void progressBar::update()
{
	_rc = RectMakeCenter(_x, _y, barTop->getWidth(), barTop->getHeight());
}

void progressBar::render()
{
	barBottom->render(_rc.left,_rc.top);
	//추가했습니다
	barTop->barRender(_rc.left + 10, _rc.top, _width - 20);
	//===========
}

void progressBar::setGauge(float currentGauge, float maxGauge)
{
	_width = (currentGauge / maxGauge) * barBottom->getWidth();
}
