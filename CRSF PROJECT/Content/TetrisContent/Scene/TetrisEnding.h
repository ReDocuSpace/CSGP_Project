#pragma once
#include "../../../FrameWork/Interface/IScene.h"
#include "../TetrisContent.h"

class TetrisEnding : public IScene
{
	TetrisContent* content;
public:
	virtual void OnInit() override;
	virtual void OnRender() override;
	virtual void OnUpdate() override;
	virtual void OnRelease() override;

	TetrisEnding(TetrisContent* content) { this->content = content; };
};

