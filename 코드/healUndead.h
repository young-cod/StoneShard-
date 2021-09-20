#pragma once
#include "stateManager.h"

class enemy;

class healUndead : public stateManager
{
private:
	int _count;
public:
	virtual stateManager* inputHandle(enemy* boss);
	virtual void update(enemy* boss);
	virtual void enter(enemy* boss);
	virtual void exit(enemy* boss);
};

