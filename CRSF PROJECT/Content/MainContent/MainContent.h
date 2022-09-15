#pragma once
#include "../../FrameWork/Interface/IGameContent.h"
#include "../../FrameWork/Interface/IScene.h"

class MainContent : public IGameContent
{
	enum class _EMainMode
	{
		NONE,
		READY,
		SELECT,
		CHOICE
	};

	enum class _EGameList
	{
		NONE,
		SNAKE,
		ROADRUNNER,
		GAME2,
		GAME3,
		GAME4,
		GAME5,
		GAME6,
		GAME7,
		EXIT,
	};

	_EMainMode mainMode;
	_EGameList gameList;

	// press
	float pressTimer;
	bool pressMessage;
	bool pressTrigger;

public:
	virtual void OnInit() override;
	virtual void OnRelease() override;
	virtual void OnRender() override;
	virtual void OnUpdate() override;
	
	// 기능 나누기
	void NoneRender();
	void ReadyRender();
	void SelectRender();
	void ChoiceRender();

	// 기능 나누기
	void NoneUpdate();
	void ReadyUpdate();
	void SelectUpdate();
	void ChoiceUpdate();

	void LogoRender();

};

