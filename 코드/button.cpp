#include "stdafx.h"
#include "button.h"

button::button()
	:_isClick(false)
{
}

button::~button()
{
}

HRESULT button::init()
{
	return S_OK;
}

HRESULT button::init(image * img)
{
	_img = img;
	_isClick = false;
	return S_OK;
}

void button::release()
{
}

void button::update()
{
}

void button::render()
{
}

void button::imageSet()
{
}
