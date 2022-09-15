#pragma once
#include "singleton.h"
#include "Interface/IGameContent.h"

#include <map>
#include <string>

using namespace std;


class ContentManager : public singleton<ContentManager>
{

public:
	typedef map<string, IGameContent*> GameDictionary;

private:

	bool gameStart;

	IGameContent* currentContent;

	GameDictionary gameDic;
	GameDictionary::iterator itGameDic;

public:
	void SceneInit();

	void OnUpdate();
	void OnRender();

	void SceneRelease();

	void AddContent(string contentName, IGameContent* content);
	void ChangeContent(string contentName);

	void GameExit();

	bool GameState()
	{
		return gameStart;
	}

};

