#include "TetrisTitle.h"
#include "../../../CSGPFrameWork.h"

void TetrisTitle::OnInit()
{
}

void TetrisTitle::OnRender()
{
	int xpos = 5;
	SCREEN->OnDrawText(xpos, 3, "¡á¡á¡á¡á¡á  ¡á¡á¡á¡á¡á  ¡á¡á¡á¡á¡á  ¡á¡á¡á¡á¡á  ¡á¡á¡á¡á¡á  ¡á¡á¡á¡á¡á");
	SCREEN->OnDrawText(xpos, 4, "    ¡á      ¡á              ¡á      ¡á      ¡á      ¡á      ¡á        ");
	SCREEN->OnDrawText(xpos, 5, "    ¡á      ¡á¡á¡á¡á¡á      ¡á      ¡á¡á¡á¡á        ¡á      ¡á¡á¡á¡á¡á");
	SCREEN->OnDrawText(xpos, 6, "    ¡á      ¡á              ¡á      ¡á      ¡á      ¡á              ¡á");
	SCREEN->OnDrawText(xpos, 7, "    ¡á      ¡á¡á¡á¡á¡á      ¡á      ¡á      ¡á  ¡á¡á¡á¡á¡á  ¡á¡á¡á¡á¡á");

	SCREEN->OnDrawText(36, 17, "GAME START");
	SCREEN->OnDrawText(36, 19, "GAME EXIT");
	
	switch (gameState)
	{
	case _ETETRIS_STATE::START:
		SCREEN->OnDrawText(32, 17, "¡ß");
		SCREEN->OnDrawText(48, 17, "¡ß");
		break;
	case _ETETRIS_STATE::END:
		SCREEN->OnDrawText(32, 19, "¡ß");
		SCREEN->OnDrawText(48, 19, "¡ß");
		break;
	default:
		break;
	}
}

void TetrisTitle::OnUpdate()
{
	if (INPUT->KeyDown(VK_DOWN))
	{
		gameState = (_ETETRIS_STATE)((int)gameState + 1);

		if (gameState > _ETETRIS_STATE::END)
		{
			gameState = _ETETRIS_STATE::START;
		}
	}
	if (INPUT->KeyDown(VK_UP))
	{
		gameState = (_ETETRIS_STATE)((int)gameState - 1);

		if (gameState < (_ETETRIS_STATE)0)
		{
			gameState = _ETETRIS_STATE::END;
		}
	}

	if (INPUT->KeyDown(VK_RETURN))
	{
		if (gameState == _ETETRIS_STATE::START)
		{
			content->ChangeScene("GAME");
		}

		if (gameState == _ETETRIS_STATE::END)
		{
			CONTENTS->ChangeContent("MAIN");
		}
	}
}

void TetrisTitle::OnRelease()
{
}
