#pragma once
#include "../../../FrameWork/Interface/IScene.h"

#include "../SnakeContent.h"

class SnakeTitle : public IScene
{
	SnakeContent* content;

	enum class _ESNAKE_STATE
	{
		START,
	//	MULTI,
		END
	};

	_ESNAKE_STATE gameState;

public:
	virtual void OnInit();
	virtual void OnRender();
	virtual void OnUpdate();
	virtual void OnRelease();

	SnakeTitle(SnakeContent* _content) {
		content = _content;
		gameState = _ESNAKE_STATE::START;
	}
};

