#pragma once
#include "../../../FrameWork/Interface/IScene.h"
#include "../SnakeContent.h"

#include <vector>

using namespace std;

class SnakeStage : public IScene
{
	SnakeContent* content;

	int SnakeWidth;
	int SnakeHeight;

	// Á¡¼ö
	int score;
	float time;
	int life;

	enum class E_DIRECT {
		NONE,
		LEFT,
		RIGHT,
		UP,
		DOWN,
	};

	struct _SActor
	{
		int m_x;
		int m_y;
		const char* shape;
	};

	_SActor player;
	
	vector<_SActor> tailList;

	_SActor tail;
	_SActor item;

	float timeSpeed;

	E_DIRECT direct;

public:
	void OnInit();
	void OnRender();
	void OnUpdate();
	void OnRelease();

	SnakeStage(SnakeContent* _content)
	{
		
		content = _content;
	}

private:
	void KeyCode();
	void TimeUpdate();

	void GameInit();

	bool ScreenCollider(int x, int y, bool sp = false /*Special Characters */);

	bool CheckGameOver();


};

