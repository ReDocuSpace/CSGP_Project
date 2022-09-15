#include "ContentManager.h"

void ContentManager::SceneInit()
{
	gameStart = true;
}


void ContentManager::OnUpdate()
{
	if (currentContent)
	{
		currentContent->OnUpdate();
	}
}

void ContentManager::OnRender()
{
	if (currentContent)
	{
		currentContent->OnRender();
	}

}

void ContentManager::SceneRelease()
{
	if (currentContent)
	{
		currentContent->OnRelease();
	}

	for (itGameDic = gameDic.begin(); itGameDic != gameDic.end(); itGameDic++)
	{
		delete itGameDic->second;
		itGameDic->second = nullptr;
	}

	gameDic.clear();
}

void ContentManager::AddContent(string contentName, IGameContent* content)
{
	if (gameDic.find(contentName) != gameDic.end()) return;

	gameDic.insert(pair<string, IGameContent*>(contentName, content));
}

void ContentManager::ChangeContent(string contentName)
{
	if (gameDic.find(contentName) == gameDic.end()) return;

	if (currentContent)
	{
		currentContent->OnRelease();
	}

	currentContent = gameDic[contentName];
	currentContent->OnInit();
}

void ContentManager::GameExit()
{
	gameStart = false;
}
