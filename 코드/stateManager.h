#pragma once

class enemy;
class playerManager;

class stateManager
{
private:
protected:
	playerManager* _player;
public:
	virtual stateManager* inputHandle(enemy* enemy) = 0;
	virtual void update(enemy* enemy) = 0;
	virtual void enter(enemy* enemy) = 0;
	virtual void exit(enemy* enemy) = 0;

	void linkPlayer(playerManager* player) { _player = player; }
	playerManager* getPlayer() { return _player; }

};

