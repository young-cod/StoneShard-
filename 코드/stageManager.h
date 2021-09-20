#pragma once

#include "aStar.h"
#include "rayCast.h"
#include "mapmap.h"

#include "gameNode.h"
#include "title.h"
#include "stage1.h"
#include "stage2.h"


class stageManager : public gameNode
{
private:

public:
	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

	void sceneSet();
	void fontSet();
	void imageSet();
	void soundSet();

};
