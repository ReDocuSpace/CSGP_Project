#include "SnakeStage.h"
#include "../../../CSGPFrameWork.h"

void SnakeStage::OnInit()
{
	score = 0;

	time = 5.25f;
	// 
	SnakeWidth = 50;
	SnakeHeight = 25;

	timeSpeed = 0.1f;
	// 0 Index 俊 1.0 蔼

	// Player 技泼
	player.shape = "♂";
	do
	{
		player.m_x = 1 + (rand() % (SnakeWidth /2 - 2));
		player.m_y = 1 + (rand() % (SnakeHeight - 2));

	} while (ScreenCollider(player.m_x, player.m_y, true));

	
	// Item 技泼
	item.shape = "∴";
	do
	{
		item.m_x = 1 + (rand() % (SnakeWidth / 2 - 2));
		item.m_y = 1 + (rand() % (SnakeHeight - 2));
	
	} while (ScreenCollider(item.m_x, item.m_y, true));


	// 部府 技泼
	tail.m_x = 0;
	tail.m_y = 0;
	tail.shape = "∴";


	direct = E_DIRECT::NONE;
}

void SnakeStage::OnRender()
{
	
	for (int i = 0;i < SnakeHeight;i++)
	{
		SCREEN->OnDrawText(SnakeWidth, i, "♂");
	}

	for (int i = 0; i < tailList.size(); i++)
	{
		SCREEN->OnDrawText(tailList[i].m_x * 2, tailList[i].m_y, tailList[i].shape);
	}

	SCREEN->OnDrawText(item.m_x * 2, item.m_y, item.shape);
	SCREEN->OnDrawText(player.m_x * 2, player.m_y, player.shape);

	SCREEN->OnDrawText(SnakeWidth + 4, 2, "score : ");
	SCREEN->OnDrawText(SnakeWidth + 4 + 9, 2, to_string(score).c_str());
	//SCREEN->OnDrawText(SnakeWidth + 4 + 7, 2, to_string(TIMER->GetStageTimer()).c_str());
}

void SnakeStage::OnUpdate()
{
	if (INPUT->KeyDown('R'))
	{
		TIMER->StartStageTimer(5.0f);
	}

	if (INPUT->KeyDown('E'))
	{
		TIMER->StopStageTimer();
	}

	KeyCode();
	TimeUpdate();
}

void SnakeStage::OnRelease()
{
	GameInit();
}

void SnakeStage::KeyCode()
{

	if (INPUT->KeyDown(VK_UP) || INPUT->KeyDown('W'))
	{
		direct = E_DIRECT::UP;
	}
	if (INPUT->KeyDown(VK_DOWN) || INPUT->KeyDown('S'))
	{
		direct = E_DIRECT::DOWN;
	}
	if (INPUT->KeyDown(VK_LEFT) || INPUT->KeyDown('A'))
	{
		direct = E_DIRECT::LEFT;
	}
	if (INPUT->KeyDown(VK_RIGHT) || INPUT->KeyDown('D'))
	{
		direct = E_DIRECT::RIGHT;
	}
}

void SnakeStage::TimeUpdate()
{
	if (TIMER->TickPlayTimer(0, timeSpeed))
	{

		int m_x = player.m_x;
		int m_y = player.m_y;

		switch (direct)
		{
		case SnakeStage::E_DIRECT::NONE:
			break;
		case SnakeStage::E_DIRECT::LEFT:
			player.m_x--;
			break;
		case SnakeStage::E_DIRECT::RIGHT:
			player.m_x++;
			break;
		case SnakeStage::E_DIRECT::UP:
			player.m_y--;
			break;
		case SnakeStage::E_DIRECT::DOWN:
			player.m_y++;
			break;
		default:
			break;
		}

		if (CheckGameOver())
		{
			content->ChangeScene("TITLE");
		}
		
		if (ScreenCollider(player.m_x, player.m_y, true))
		{
			content->ChangeScene("TITLE");
		}

		if (tailList.size() > 0)
		{
			_SActor head_actor = tailList[0];

			tailList[0].m_x = m_x;
			tailList[0].m_y = m_y;

			for (int i = 1; i < tailList.size(); i++)
			{
				_SActor tail_actor = tailList[i];

				tailList[i] = head_actor;

				head_actor = tail_actor;
			}
		}
	}

	if (player.m_x == item.m_x &&
		player.m_y == item.m_y)
	{

		tail.m_x = player.m_x;
		tail.m_y = player.m_y;

		tailList.push_back(tail);

		score++;
		timeSpeed -= 0.01f;
		
		do
		{
			item.m_x = 1 + (rand() % (SnakeWidth / 2 - 2));
			item.m_y = 1 + (rand() % (SnakeHeight - 2));

		} while (ScreenCollider(item.m_x, item.m_y, true));
	}
}

void SnakeStage::GameInit()
{
	tailList.clear();
}

bool SnakeStage::CheckGameOver()
{
	for (int i = 0; i < tailList.size(); i++)
	{
		if (tailList[i].m_x == player.m_x &&
			tailList[i].m_y == player.m_y)
		{
			return true;
		}
	}


	return false;
}

bool SnakeStage::ScreenCollider(int x, int y, bool sp)
{
	if (x > 0 && y > 0 && x < SnakeWidth / (sp * 2) - 1 && y < SnakeHeight - 1)
	{
		return false;
	}
	return true;
}
