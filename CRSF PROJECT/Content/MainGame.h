#pragma once
#include "../FrameWork/Interface/IGameContent.h"

class MainGame
{
	IGameContent* mainContent;
	IGameContent* snakeContent;

public:
	void OnInit();
	void OnRelease();
	void OnUpdate();
	void OnRender();
};

