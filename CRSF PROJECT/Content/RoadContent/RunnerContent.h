#pragma once
#include "../../FrameWork/Interface/IGameContent.h"
#include "../../FrameWork/SceneManager.h"

using namespace std;

class RunnerContent : public IGameContent
{
#define MAP_SIZE_X 38
#define MAP_SIZE_Y 4

	enum class E_DIRECT {
		NONE,
		LEFT,
		RIGHT,
		UP,
		DOWN,
	};

	struct _SRunnerActor
	{
		
		int x;
		int y;
		int width = 3;
		int height = 3;
		bool shape[3][3] = {
			{1,1,0},
			{0,1,1},
			{1,1,0}
		};
		bool alive = false;
	};

	int mapHeight;
	
	char mapDesignUp[MAP_SIZE_Y][MAP_SIZE_X];
	char mapDesignDown[MAP_SIZE_Y][MAP_SIZE_X];


	const int limitSpeed = 10;

	E_DIRECT direct;

	_SRunnerActor player;

	_SRunnerActor enermy[10];

	int speed = 0;

public:
	virtual void OnInit();
	virtual void OnRelease();
	virtual void OnRender();
	virtual void OnUpdate();

private:
	void KeyCode();
	void MoveRunner();
	void MoveMapping();
};

 