#pragma once
#include "singletonBase.h"

class gameNode;

class sceneManager : public singletonBase<sceneManager>
{
public:
	typedef map<string, gameNode*>			 mapSceneList;
	typedef map<string, gameNode*>::iterator mapSceneIter;

private:
	static gameNode* _currentScene;
	mapSceneList _mSceneList;

	string _currentSceneName;


public:
	sceneManager();
	~sceneManager();

	HRESULT init();
	void release();
	void update();
	void render();

	gameNode* addScene(string sceneName, gameNode* scene);

	HRESULT changeScene(string sceneName);

	bool isCurrentScene(string sceneName)
	{
		if (_currentSceneName == sceneName) return true;
		else return false;
	}

	string getSceneName() { return _currentSceneName; }
	gameNode* getScene() { return _currentScene; }
};