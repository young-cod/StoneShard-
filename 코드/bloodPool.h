#pragma once
#include "stateManager.h"

class enemy;

class archonBloodPool : public stateManager
{
private:
	int _count;
	int _timer = 0;

public:
	virtual stateManager* inputHandle(enemy* boss);
	virtual void update(enemy* boss);
	virtual void enter(enemy* boss);
	virtual void exit(enemy* boss);
};

