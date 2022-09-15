#pragma once
#include "../../FrameWork/Interface/IGameContent.h"
#include "../../FrameWork/SceneManager.h"

#include <map>
#include <string>

using namespace std;

class SnakeContent : public IGameContent
{
public:
	virtual void OnInit() override;

	virtual void OnRender() override;
	virtual void OnUpdate() override;

	virtual void OnRelease() override;

	void ChangeScene(string sceneName);
};


