#pragma once
#include "../../FrameWork/Interface/IGameContent.h"
#include "../../FrameWork/SceneManager.h"

class TetrisContent : public IGameContent
{
	SceneManager* sceneManager;

public:
	virtual void OnInit() override;

	virtual void OnRender() override;
	virtual void OnUpdate() override;

	virtual void OnRelease() override;

	void ChangeScene(string scene);

};

