#pragma once
#include "singleton.h"
#include "Interface/IScene.h"

#include <map>
#include <string>

using namespace std;

class SceneManager
{
public:
	typedef map<string, IScene*> GameDictionary;

private:

	bool gameStart;

	IScene* currentContent;

	GameDictionary gameDic;
	GameDictionary::iterator itGameDic;

public:
	void SceneInit();

	void OnUpdate();
	void OnRender();

	void SceneRelease();

	void AddScene(string sceneName, IScene* scene);
	void ChangeScene(string sceneName);


};

