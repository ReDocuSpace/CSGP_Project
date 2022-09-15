#include "RunnerContent.h"
#include "../../CSGPFrameWork.h"

void RunnerContent::OnInit()
{
	TIMER->AddPlayTimer(0, 0.5f);
	TIMER->AddPlayTimer(1, 0.5f);
	player.x = 3;
	player.y = 15;

	mapHeight = MAP_SIZE_Y + 1;
	speed = 0;
	
	for (int y = 0;y < MAP_SIZE_Y;y++)
	{
		for (int x= 0;x < MAP_SIZE_X;x++)
		{
			mapDesignUp[y][x] = rand() % 5;
			mapDesignDown[y][x] = rand() % 5;
		}
	}
}

void RunnerContent::OnRelease()
{
	TIMER->ClearPlayTimer();
}

void RunnerContent::OnRender()
{
	for (int i = 1;i < SCREEN_WIDTH/2 - 1;i++)
	{
		SCREEN->OnDrawText(i * 2, mapHeight, "¦¡");
		SCREEN->OnDrawText(i * 2, SCREEN_HEIGHT - 1- mapHeight, "¦¡");
	}

	for (int y = 0;y < player.height;y++)
	{
		for (int x = 0;x < player.width;x++)
		{
			if (player.shape[y][x])
			{
				SCREEN->OnDrawText((player.x + x) * 2, player.y + y, "¡á");
			}
			else
			{
				SCREEN->OnDrawText((player.x + x) * 2, player.y + y, "  ");
			}
		}
	}


	for (int y = 0; y < MAP_SIZE_Y; y++)
	{
		for (int x = 0; x < MAP_SIZE_X; x++)
		{
			switch (mapDesignUp[y][x])
			{
			case 0:
				SCREEN->OnDrawText((x + 1) * 2, y + 1, "¢»");
				break;
			case 1:
				SCREEN->OnDrawText((x + 1) * 2, y + 1, "¢¼");
				break;
			case 2:
				SCREEN->OnDrawText((x + 1) * 2, y + 1, "¢¿");
				break;
			case 3:
				SCREEN->OnDrawText((x + 1) * 2, y + 1, "¢À");
				break;
			case 4:
				SCREEN->OnDrawText((x + 1) * 2, y + 1, "  ");
				break;
			default:
				break;
			}

			switch (mapDesignUp[y][x])
			{
			case 0:
				SCREEN->OnDrawText((x + 1) * 2, SCREEN_HEIGHT - (y + 1) - 1, "¢»");
				break;
			case 1:
				SCREEN->OnDrawText((x + 1) * 2, SCREEN_HEIGHT - (y + 1) - 1, "¢¼");
				break;
			case 2:
				SCREEN->OnDrawText((x + 1) * 2, SCREEN_HEIGHT - (y + 1) - 1, "¢¿");
				break;
			case 3:
				SCREEN->OnDrawText((x + 1) * 2, SCREEN_HEIGHT - (y + 1) - 1, "¢À");
				break;
			case 4:
				SCREEN->OnDrawText((x + 1) * 2, SCREEN_HEIGHT - (y + 1) - 1, "  ");
				break;
			default:
				break;
			}
		}
	}


	SCREEN->OnDrawText(65, mapHeight + 1, "speed : ");
	SCREEN->OnDrawText(75, mapHeight + 1, to_string(speed).c_str());
}

void RunnerContent::OnUpdate()
{
	KeyCode();
	MoveRunner();
	MoveMapping();
}

void RunnerContent::KeyCode()
{
	if (INPUT->StayKeyDown(VK_UP) || INPUT->StayKeyDown('W'))
	{
		direct = E_DIRECT::UP;
	}
	if (INPUT->StayKeyDown(VK_DOWN) || INPUT->StayKeyDown('S'))
	{
		direct = E_DIRECT::DOWN;
	}
	if (INPUT->StayKeyDown(VK_LEFT) || INPUT->StayKeyDown('A'))
	{
		direct = E_DIRECT::LEFT;
	}
	if (INPUT->StayKeyDown(VK_RIGHT) || INPUT->StayKeyDown('D'))
	{
		direct = E_DIRECT::RIGHT;
	}
}

void RunnerContent::MoveRunner()
{
	switch (direct)
	{
	case RunnerContent::E_DIRECT::NONE:
		break;
	case RunnerContent::E_DIRECT::RIGHT:
		speed++;
		break;
	case RunnerContent::E_DIRECT::LEFT:
		speed--;
		break;
	case RunnerContent::E_DIRECT::UP:
		player.y--;
		break;
	case RunnerContent::E_DIRECT::DOWN:
		player.y++;
		break;
	default:
		break;
	}

	if (speed < 0) speed = 0;
	if (speed > limitSpeed) speed = limitSpeed;

	if (player.y < mapHeight + 1)
	{
		player.y = mapHeight + 1;
	}

	if (player.y + player.height > SCREEN_HEIGHT - 1 - mapHeight)
	{
		player.y = SCREEN_HEIGHT - 1 - mapHeight - player.height;
	}


	direct = E_DIRECT::NONE;

}

void RunnerContent::MoveMapping()
{
	if (TIMER->TickPlayTimer(0, (1.0f - (double)speed/10.0f)))
	{
		if (speed == 0) return;

		for (int x = 0;x < MAP_SIZE_X - 1;x++)
		{
			for (int y = 0;y < MAP_SIZE_Y;y++)
			{
				mapDesignUp[y][x] = mapDesignUp[y][x + 1];
				mapDesignDown[y][x] = mapDesignDown[y][x + 1];
			}
		}

		for (int i = 0;i < MAP_SIZE_Y;i++)
		{
			mapDesignUp[i][MAP_SIZE_X - 1] = rand() % 5;
			mapDesignDown[i][MAP_SIZE_X - 1] = rand() % 5;
		}

	}


}
