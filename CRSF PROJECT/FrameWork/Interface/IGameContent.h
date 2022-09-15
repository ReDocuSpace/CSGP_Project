#pragma once

#include "IScene.h"

class IGameContent
{
	//IScene


public:
	virtual void OnInit() = 0;
	virtual void OnRelease() = 0;
	virtual void OnRender() = 0;
	virtual void OnUpdate() = 0;
};

