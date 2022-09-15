#pragma once
#include "../../../FrameWork/Interface/IScene.h"
#include "../TetrisContent.h"

#include "Object/TetrisBlock.h"

class TetrisGame : public IScene
{
#define GAME_SIZE_X 12
#define GAME_SIZE_Y 23

	TetrisContent* content;

private:

	bool gameMap[GAME_SIZE_Y][GAME_SIZE_X] = {{0}};
	bool gameMap2P[GAME_SIZE_Y][GAME_SIZE_X] = { {0} };

	
	TetrisBlock* playBlock;
	TetrisBlock* aliveBlock;
	TetrisBlock* nextBlock;

	bool checkLine = false;

	int score = 0;
	int score_point = 100;

public:
	virtual void OnInit() override;
	virtual void OnRender() override;
	virtual void OnUpdate() override;
	virtual void OnRelease() override;

	bool MoveCheck(bool map[GAME_SIZE_Y][GAME_SIZE_X], TetrisBlock* checkBlock, int destX, int destY);
	bool MoveLineCheck(bool map[GAME_SIZE_Y][GAME_SIZE_X], int line, int destY);
	bool RotateCheck(bool map[GAME_SIZE_Y][GAME_SIZE_X], TetrisBlock* checkBlock);
	bool CheckLine(bool map[GAME_SIZE_Y][GAME_SIZE_X], int line);
	bool CheckEmpty(bool map[GAME_SIZE_Y][GAME_SIZE_X], int line);

	void SaveLine(bool map[GAME_SIZE_Y][GAME_SIZE_X], TetrisBlock* checkBlock);
	void MoveLine(bool map[GAME_SIZE_Y][GAME_SIZE_X], int line);
	void DeleteLine(bool map[GAME_SIZE_Y][GAME_SIZE_X], int line);
	void DownMove(bool map[GAME_SIZE_Y][GAME_SIZE_X], TetrisBlock* checkBlock);

	void CleanUp(bool map[GAME_SIZE_Y][GAME_SIZE_X]);

	TetrisGame(TetrisContent* content) {
		
		playBlock = nullptr;
		nextBlock = nullptr;

		this->content = content; 
	};

};

