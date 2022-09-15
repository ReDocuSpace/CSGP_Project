#include "SnakeTitle.h"
#include "../../../CSGPFrameWork.h"

void SnakeTitle::OnInit()
{
}

void SnakeTitle::OnRender()
{

	SCREEN->OnDrawText(11,3,"бсбсбсбсбс  бс      бс      бс      бс      бс  бсбсбсбсбс");
	SCREEN->OnDrawText(11,4,"бс          бсбс    бс    бс  бс    бс    бс    бс        ");
	SCREEN->OnDrawText(11,5,"бс          бсбс    бс  бс      бс  бс  бс      бс        ");
	SCREEN->OnDrawText(11,6,"бсбсбсбсбс  бс  бс  бс  бсбсбсбсбс  бсбс        бсбсбсбсбс");
	SCREEN->OnDrawText(11,7,"        бс  бс    бсбс  бс      бс  бс  бс      бс        ");
	SCREEN->OnDrawText(11,8,"        бс  бс    бсбс  бс      бс  бс    бс    бс        ");
	SCREEN->OnDrawText(11,9,"бсбсбсбсбс  бс      бс  бс      бс  бс      бс  бсбсбсбсбс");

	SCREEN->OnDrawText(36, 17, "GAME START");
	//SCREEN->OnDrawText(36, 17, "UPDATE...");
	SCREEN->OnDrawText(36, 19, "GAME EXIT");


	// ╝▒┼├

	switch (gameState)
	{
	case _ESNAKE_STATE::START:
		SCREEN->OnDrawText(32, 17, "б▀");
		SCREEN->OnDrawText(48, 17, "б▀");
		break;
	//case _ESNAKE_STATE::MULTI:
	//	SCREEN->OnDrawText(32, 17, "б▀");
	//	SCREEN->OnDrawText(48, 17, "б▀");
	//	break;
	case _ESNAKE_STATE::END:
		SCREEN->OnDrawText(32, 19, "б▀");
		SCREEN->OnDrawText(48, 19, "б▀");
		break;
	default:
		break;
	}


}

void SnakeTitle::OnUpdate()
{
	if (INPUT->KeyDown(VK_DOWN))
	{
		gameState = (_ESNAKE_STATE)((int)gameState + 1);

		if (gameState > _ESNAKE_STATE::END)
		{
			gameState = _ESNAKE_STATE::START;
		}
	}
	if (INPUT->KeyDown(VK_UP))
	{
		gameState = (_ESNAKE_STATE)((int)gameState - 1);

		if (gameState < (_ESNAKE_STATE)0)
		{
			gameState = _ESNAKE_STATE::END;
		}
	}

	if (INPUT->KeyDown(VK_RETURN))
	{
		if (gameState == _ESNAKE_STATE::START)
		{
			content->ChangeScene("STAGE");
			//SCENE->ChangeScene("SNAKE");
		}

		if (gameState == _ESNAKE_STATE::END)
		{
			CONTENTS->ChangeContent("MAIN");
		}
	}

}

void SnakeTitle::OnRelease()
{
}
