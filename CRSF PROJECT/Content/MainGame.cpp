#include "MainGame.h"
#include "../CSGPFrameWork.h"

#include "MainContent/MainContent.h"

#include "SnakeContent/SnakeContent.h"
#include "RoadContent/RunnerContent.h"
#include "TetrisContent/TetrisContent.h"

void MainGame::OnInit()
{
	//srand(time(NULL));

	//mainContent = new MainContent();
	//mainContent->OnInit();
	//snakeContent = new SnakeContent();
	//snakeContent->OnInit();

	CONTENTS->AddContent("MAIN", new MainContent());
	CONTENTS->AddContent("SNAKE", new SnakeContent());
	CONTENTS->AddContent("ROAD", new RunnerContent());
	CONTENTS->AddContent("TETRIS", new TetrisContent());

	CONTENTS->ChangeContent("TETRIS");

}

void MainGame::OnRelease()
{

	//mainContent->OnRelease();
	//SAFE_DELETE(mainContent);

	//snakeContent->OnRelease();
	//SAFE_DELETE(snakeContent);
}

void MainGame::OnUpdate()
{
	CONTENTS->OnUpdate();

	//if (INPUT->KeyDown(VK_F5))
	//{
	//	CONTENTS->ChangeContent("MAIN");
	//}

	if (INPUT->KeyDown('P'))
	{
		CONTENTS->ChangeContent("MAIN");
	}

	if (INPUT->KeyDown('O'))
	{
		CONTENTS->ChangeContent("SNAKE");
	}
	//mainContent->OnUpdate();
	//snakeContent->OnUpdate();
}

void MainGame::OnRender()
{

	for (int y = 0; y < SCREEN_HEIGHT; y++)
	{
		for (int x = 0; x < SCREEN_WIDTH / 2; x++)
		{
			if (x == 0 || x == SCREEN_WIDTH / 2 - 1 || y == 0 || y == SCREEN_HEIGHT - 1)
			{
				SCREEN->OnDrawTextColor((x) * 2, y, "бс", BLUE);
				//SCREEN->OnDrawText((x) * 2, y, "бс");
			}
		}
	}

	SCREEN->OnDrawSetColor(WHITE);
	CONTENTS->OnRender();

}
