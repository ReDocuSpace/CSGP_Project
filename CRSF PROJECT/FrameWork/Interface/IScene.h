#pragma once
#include "IGameContent.h"
class IScene
{
public:
	virtual void OnInit() = 0;
	virtual void OnRender() = 0;
	virtual void OnUpdate() = 0;
	virtual void OnRelease() = 0;
	
};