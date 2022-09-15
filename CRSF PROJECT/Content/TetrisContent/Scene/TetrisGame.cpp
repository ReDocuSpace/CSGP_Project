#include "TetrisGame.h"
#include "../../../CSGPFrameWork.h"

#include "TetrisInfo.h"

void TetrisGame::OnInit()
{
	playBlock = new TetrisBlock();
	playBlock->OnInit(TetrisInfo::block[3]);
	
	aliveBlock = new TetrisBlock();
	nextBlock = new TetrisBlock();
	nextBlock->OnInit(TetrisInfo::block[rand() % BLOCK_COUNT]);

	// 1P
	for (int i = 0;i < GAME_SIZE_Y;i++)
	{
		gameMap[i][0] = true;
		gameMap[i][GAME_SIZE_X - 1] = true;

		gameMap2P[i][0] = true;
		gameMap2P[i][GAME_SIZE_X - 1] = true;
	}

	for (int i = 0;i < GAME_SIZE_X;i++)
	{
		gameMap[GAME_SIZE_Y - 1][i] = true;
		gameMap2P[GAME_SIZE_Y - 1][i] = true;
	}

	score = 0;
	score_point = 100;

}

void TetrisGame::OnRender()
{
	// 1P POS
	int xpos1P = 2;
	int ypos1P = 1;

	for (int i = 0;i < GAME_SIZE_X;i++)
	{
		for (int j = 0;j < GAME_SIZE_Y;j++)
		{
			if(i == 0 || i == GAME_SIZE_X - 1 || j == GAME_SIZE_Y - 1)
				SCREEN->OnDrawTextColor(xpos1P + i * 2, ypos1P + j, "бс",SKYBLUE);
			else if (!gameMap[j][i])
			{
			}
			//	SCREEN->OnDrawTextColor(xpos1P + i * 2, ypos1P + j, "бр",YELLOW);
			else
				SCREEN->OnDrawTextColor(xpos1P + i * 2, ypos1P + j, "бс",YELLOW);
			
		}
	}
	
	playBlock->Draw(xpos1P, ypos1P);

	nextBlock->Draw(18, 2);
	nextBlock->Draw(34, 2);

	SCREEN->OnDrawSetColor(WHITE);

	SCREEN->OnDrawText(28, 10, "<SCORE>");
	SCREEN->OnDrawText(30, 11, to_string(score).c_str());


	int xpos2P = 54;
	int ypos2P = 1;

	for (int i = 0; i < GAME_SIZE_X; i++)
	{
		for (int j = 0; j < GAME_SIZE_Y; j++)
		{
			if (i == 0 || i == GAME_SIZE_X - 1 || j == GAME_SIZE_Y - 1)
				SCREEN->OnDrawTextColor(xpos2P + i * 2, ypos2P + j, "бс", SKYBLUE);
			else if (!gameMap2P[j][i])
			{
			}
			//	SCREEN->OnDrawTextColor(xpos2P + i * 2, ypos2P + j, "бр",YELLOW);
			else
				SCREEN->OnDrawTextColor(xpos2P + i * 2, ypos2P + j, "бс", YELLOW);

		}
	}


	//SCREEN->OnDrawText(60, 5, to_string(playBlock->GetXpos()).c_str());
	//SCREEN->OnDrawText(60, 6, to_string(playBlock->GetYpos()).c_str());
	//SCREEN->OnDrawText(60, 7, to_string(checkLine).c_str());


}

void TetrisGame::OnUpdate()
{
	if (TIMER->TickWaitTimer(0.1f))
	{
		if (MoveCheck(gameMap,playBlock, 0, 1))
			playBlock->BlockMove(false, true);
		else
		{
			SaveLine(gameMap,playBlock);
			CleanUp(gameMap);
		}
	}

	if (INPUT->KeyDown(VK_UP))
	{
		if(MoveCheck(gameMap,playBlock, 0, -1))
			playBlock->BlockMove(false, true, -1);
	}
	if (INPUT->KeyDown(VK_DOWN))
	{
		if (MoveCheck(gameMap,playBlock, 0, 1))
			playBlock->BlockMove(false, true);
		else
			SaveLine(gameMap,playBlock);
	}
	if (INPUT->KeyDown(VK_LEFT))
	{
		if (MoveCheck(gameMap, playBlock, -1, 0))
			playBlock->BlockMove(true, false, -1);
	}
	if (INPUT->KeyDown(VK_RIGHT))
	{
		if (MoveCheck(gameMap,playBlock, 1, 0))
			playBlock->BlockMove(true, false);
	}
	if (INPUT->KeyDown('L'))
	{
		if(RotateCheck(gameMap,playBlock))
			playBlock->BlockRotation();
	}
	if (INPUT->KeyDown('K'))
	{
		DownMove(gameMap,playBlock);

		SaveLine(gameMap,playBlock);
		CleanUp(gameMap);
	}
	if (INPUT->KeyDown('M'))
	{
		nextBlock->OnChange(TetrisInfo::block[rand() % BLOCK_COUNT]);
		//playBlock->OnReset();
		//playBlock->OnChange(TetrisInfo::block[rand()%BLOCK_COUNT]);
	}



}

void TetrisGame::OnRelease()
{
}

bool TetrisGame::RotateCheck(bool map[GAME_SIZE_Y][GAME_SIZE_X], TetrisBlock* checkBlock)
{
	bool tempBlock[4][4];

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			tempBlock[i][j] = checkBlock->block[j][4 - i - 1];
		}
	}
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			//if (checkBlock->GetYpos() < 0
			//	|| checkBlock->GetXpos() < 0
			//	|| checkBlock->GetYpos() + i > GAME_SIZE_Y - 1
			//	|| checkBlock->GetXpos() + j > GAME_SIZE_X - 1)
			//	continue;

			if (tempBlock[i][j] && map[checkBlock->GetYpos() + i][checkBlock->GetXpos() + j])
			{
				if (checkBlock->GetXpos() <= 0)
					checkBlock->BlockMove(true, 0,1);
				
				if (checkBlock->GetXpos() + 4 >= GAME_SIZE_X)
					checkBlock->BlockMove(true, 0, -1);
				
				if (RotateCheck(map,checkBlock))
					checkBlock->BlockRotation();

				return false;
			}
		}
	}
	return true;
}
bool TetrisGame::MoveLineCheck(bool map[GAME_SIZE_Y][GAME_SIZE_X], int line, int destY)
{
	for (int j = 1; j < GAME_SIZE_X - 1; j++)
	{
		if (map[line + destY][j] == true)
			return false;
	}

	return true;
}
bool TetrisGame::MoveCheck(bool map[GAME_SIZE_Y][GAME_SIZE_X], TetrisBlock* checkBlock, int destX, int destY)
{
	for (int i = 0;i < 4;i++)
	{
		for (int j = 0;j < 4;j++)
		{
			if (checkBlock->GetYpos() < 0 
				|| checkBlock->GetXpos() < 0 
				|| checkBlock->GetYpos() + i + destY > GAME_SIZE_Y - 1 
				|| checkBlock->GetXpos() + j + destX > GAME_SIZE_X - 1)
				continue;

			if (checkBlock->block[i][j] && map[checkBlock->GetYpos() + i + destY][checkBlock->GetXpos() + j + destX])
				return false;
		}
	}
	return true;
}
bool TetrisGame::CheckLine(bool map[GAME_SIZE_Y][GAME_SIZE_X], int line)
{
	for (int i = 1; i < GAME_SIZE_X - 1; i++)
	{
		if (!map[line][i])
			return false;
	}
	return true;
}
bool TetrisGame::CheckEmpty(bool map[GAME_SIZE_Y][GAME_SIZE_X], int line)
{
	for (int i = 1; i < GAME_SIZE_X - 1; i++)
	{
		if (map[line][i])
			return false;
	}
	return true;
}
void TetrisGame::SaveLine(bool map[GAME_SIZE_Y][GAME_SIZE_X], TetrisBlock* checkBlock)
{
	for (int i = 0;i < 4;i++)
	{
		for (int j = 0;j < 4;j++)
		{
			if(checkBlock->block[i][j])
				map[checkBlock->GetYpos() + i][checkBlock->GetXpos() + j] = checkBlock->block[i][j];
		}
	}

	playBlock->OnReset();

	for (int i = 0;i < 16;i++)
	{
		playBlock->block[i/4][i%4] = nextBlock->block[i / 4][i % 4];
	}
	nextBlock->OnChange(TetrisInfo::block[rand() % BLOCK_COUNT]);
}
void TetrisGame::DownMove(bool map[GAME_SIZE_Y][GAME_SIZE_X], TetrisBlock* checkBlock)
{
	if (MoveCheck(map,checkBlock, 0, 1))
	{
		checkBlock->BlockMove(false, true);
		DownMove(map,checkBlock);
	}
}
void TetrisGame::CleanUp(bool map[GAME_SIZE_Y][GAME_SIZE_X])
{
	int deleteCount = 0;
	for (int i = GAME_SIZE_Y - 2; i > 1; i--)
	{
		if (CheckLine(map,i))
		{
			DeleteLine(map,i);
			deleteCount++;
		}
	}

	while (deleteCount--)
	{
		for (int i = GAME_SIZE_Y - 2; i > 1; i--)
		{
			if (!CheckLine(map,i) && CheckEmpty(map,i))
				MoveLine(map,i);
		}
	}
	
	
}

void TetrisGame::MoveLine(bool map[GAME_SIZE_Y][GAME_SIZE_X], int line)
{
	for (int i = 1; i < GAME_SIZE_X - 1; i++)
	{
		map[line][i] = map[line - 1][i];
		map[line - 1][i] = false;
	}
}

void TetrisGame::DeleteLine(bool map[GAME_SIZE_Y][GAME_SIZE_X], int line)
{
	for (int i = 1; i < GAME_SIZE_X - 1; i++)
	{
		map[line][i] = false;
	}

	score += score_point;
}
