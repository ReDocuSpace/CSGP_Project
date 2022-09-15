#include "SceneManager.h"

void SceneManager::SceneInit()
{
}


void SceneManager::OnUpdate()
{
	if (currentContent) 
	{ 
		currentContent->OnUpdate(); 
	}
}

void SceneManager::OnRender()
{
	if (currentContent)
	{
		currentContent->OnRender();
	}
		
}

void SceneManager::SceneRelease()
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

void SceneManager::AddScene(string sceneName, IScene* scene)
{
	if (gameDic.find(sceneName) != gameDic.end()) return;

	gameDic.insert(pair<string, IScene*>(sceneName, scene));
	scene->OnInit();
}

void SceneManager::ChangeScene(string sceneName)
{
	if (gameDic.find(sceneName) == gameDic.end()) return;

	if (currentContent)
	{
		currentContent->OnRelease();
	}

	currentContent = gameDic[sceneName];
	currentContent->OnInit();
}
