#pragma once
#include "../../../FrameWork/Interface/IScene.h"
#include "../TetrisContent.h"

class TetrisTitle : public IScene
{
	enum class _ETETRIS_STATE
	{
		START,
		END
	};

	_ETETRIS_STATE gameState = _ETETRIS_STATE::START;

	TetrisContent* content;
public:
	virtual void OnInit() override;
	virtual void OnRender() override;
	virtual void OnUpdate() override;
	virtual void OnRelease() override;

	TetrisTitle(TetrisContent* content) { this->content = content; };
};

