#include "MainContent.h"
#include "../../CSGPFrameWork.h"

void MainContent::OnInit()
{
	pressMessage = true;
	pressTrigger = false;
	pressTimer = 0.5f;

	mainMode = _EMainMode::READY;
	gameList = _EGameList::SNAKE;

	TIMER->AddPlayTimer(0, pressTimer);
}

void MainContent::OnRelease()
{
	TIMER->ClearPlayTimer();
}

void MainContent::OnRender()
{
	LogoRender();

	switch (mainMode)
	{
	case _EMainMode::NONE:
		NoneRender();
		break;
	case _EMainMode::READY:
		ReadyRender();
		break;
	case _EMainMode::SELECT:
		SelectRender();
		break;
	case _EMainMode::CHOICE:
		ChoiceRender();
		break;
	default:
		break;
	}



}

void MainContent::OnUpdate()
{
	switch (mainMode)
	{
	case _EMainMode::NONE:
		NoneUpdate();
		break;
	case _EMainMode::READY:
		ReadyUpdate();
		break;
	case _EMainMode::SELECT:
		SelectUpdate();
		break;
	case _EMainMode::CHOICE:
		ChoiceUpdate();
		break;
	default:
		break;
	}
}

void MainContent::NoneRender()
{
}

void MainContent::ReadyRender()
{
	if (pressMessage)
	{
		SCREEN->OnDrawText(30, 18, "press to Enter Key");
	}
}

void MainContent::SelectRender()
{
	SCREEN->OnDrawText(16, 14, "1. SNAKE");
	SCREEN->OnDrawText(16, 16, "2. ROADRUNNER");
	SCREEN->OnDrawText(16, 18, "3. UPDATE...");
	SCREEN->OnDrawText(16, 20, "4. UPDATE...");
	
	SCREEN->OnDrawText(48, 14, "5. UPDATE...");
	SCREEN->OnDrawText(48, 16, "6. UPDATE...");
	SCREEN->OnDrawText(48, 18, "7. UPDATE...");
	SCREEN->OnDrawText(48, 20, "8. UPDATE...");


	//SCREEN->OnDrawText(19, 24, "CURRENT");
	SCREEN->OnDrawText(36, 22, "EXIT");
	

	switch (gameList)
	{
	case _EGameList::SNAKE:
		SCREEN->OnDrawText(12, 14, "¢º");
		break;
	case _EGameList::ROADRUNNER:
		SCREEN->OnDrawText(12, 16, "¢º");
		break;
	case _EGameList::GAME2:
		SCREEN->OnDrawText(12, 18, "¢º");
		break;
	case _EGameList::GAME3:
		SCREEN->OnDrawText(12, 20, "¢º");
		break;
	case _EGameList::GAME4:
		SCREEN->OnDrawText(44, 14, "¢º");
		break;
	case _EGameList::GAME5:
		SCREEN->OnDrawText(44, 16, "¢º");
		break;
	case _EGameList::GAME6:
		SCREEN->OnDrawText(44, 18, "¢º");
		break;
	case _EGameList::GAME7:
		SCREEN->OnDrawText(44, 20, "¢º");
		break;
	case _EGameList::EXIT:
		SCREEN->OnDrawText(32, 22, "¢º");
		break;
	case _EGameList::NONE:
		//SCREEN->OnDrawText(12, 24, "¢º");
		break;
	default:
		break;
	}

}

void MainContent::ChoiceRender()
{
}



void MainContent::NoneUpdate()
{
}
void MainContent::ReadyUpdate()
{
	if (TIMER->TickPlayTimer(0, pressTimer))
	{
		pressMessage = !pressMessage;
	}

	if (INPUT->KeyDown(VK_RETURN))
	{
		pressTimer = 0.1f;
		pressTrigger = true;
	}

	if (pressTrigger)
	{
		if (TIMER->TickWaitTimer(2.0f))
		{
			pressTrigger = false;
			mainMode = _EMainMode::SELECT;
		}
	}
}

void MainContent::SelectUpdate()
{
	if (INPUT->KeyDown(VK_DOWN))
	{
		gameList = (_EGameList)((int)gameList + 1);

		if (gameList > _EGameList::EXIT)
		{
			gameList = _EGameList::NONE;
		}
	}
	if (INPUT->KeyDown(VK_UP))
	{
		gameList = (_EGameList)((int)gameList - 1);

		if (gameList < (_EGameList)0)
		{
			gameList = _EGameList::EXIT;
		}
	}

	if (INPUT->KeyDown(VK_RETURN))
	{
		if (gameList == _EGameList::SNAKE)
		{
			CONTENTS->ChangeContent("SNAKE");
		}
		else if (gameList == _EGameList::ROADRUNNER)
		{
			CONTENTS->ChangeContent("ROADRUNNER");
		}
		else if (gameList == _EGameList::EXIT)
		{
			CONTENTS->GameExit();
		}
	}
}

void MainContent::ChoiceUpdate()
{
}

void MainContent::LogoRender()
{
	SCREEN->OnDrawText(18, 3, "¡á¡á¡á¡á¡á  ¡á¡á¡á¡á¡á  ¡á¡á¡á¡á¡á  ¡á¡á¡á¡á¡á");
	SCREEN->OnDrawText(18, 4, "¡á          ¡á          ¡á          ¡á      ¡á");
	SCREEN->OnDrawText(18, 5, "¡á          ¡á          ¡á          ¡á      ¡á");
	SCREEN->OnDrawText(18, 6, "¡á          ¡á¡á¡á¡á¡á  ¡á  ¡á¡á¡á  ¡á¡á¡á¡á¡á");
	SCREEN->OnDrawText(18, 7, "¡á                  ¡á  ¡á  ¡á  ¡á  ¡á        ");
	SCREEN->OnDrawText(18, 8, "¡á                  ¡á  ¡á      ¡á  ¡á        ");
	SCREEN->OnDrawText(18, 9, "¡á¡á¡á¡á¡á  ¡á¡á¡á¡á¡á  ¡á¡á¡á¡á¡á  ¡á        ");

	SCREEN->OnDrawText(28, 12, "ConSole GamePack ver 0.1");
}
