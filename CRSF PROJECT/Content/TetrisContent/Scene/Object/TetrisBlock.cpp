#include "TetrisBlock.h"
#include "../../../../CSGPFrameWork.h"

void TetrisBlock::OnInit(bool block[4][4])
{
	ypos = 0;
	xpos = 5;

	for (int y = 0; y < 4; y++)
	{
		for (int x = 0; x < 4; x++)
		{
			this->block[y][x] = block[y][x];
		}
	}

}

void TetrisBlock::OnChange(bool block[4][4])
{
	for (int y = 0; y < 4; y++)
	{
		for (int x = 0; x < 4; x++)
		{
			this->block[y][x] = block[y][x];
		}
	}
}

void TetrisBlock::OnReset()
{
	xpos = 5;
	ypos = 0;
}

void TetrisBlock::BlockMove(bool xpos, bool ypos, int speed)
{
	this->xpos += (xpos * speed);
	this->ypos += (ypos * speed);
}

void TetrisBlock::BlockRotation()
{
	bool tempBlock[4][4];

	for (int i = 0;i < 4;i++)
	{
		for (int j = 0;j < 4;j++)
		{
			tempBlock[i][j] = block[j][4 - i - 1];
		}
	}



	bool check = true;
	for (int i = 0;i < 4;i++)
	{
		if (tempBlock[i][0])
			check = false;

		if (tempBlock[i][1])
			check = false;
	}
	
	if (check)
	{
		for (int i = 0; i < 4; i++)
		{
			tempBlock[i][0] = tempBlock[i][1];
			tempBlock[i][1] = tempBlock[i][2];
			tempBlock[i][2] = tempBlock[i][3];
			tempBlock[i][3] = false;
		}
	}

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			block[i][j] = tempBlock[i][j];
		}
	}
}

void TetrisBlock::Draw(int xpos, int ypos)
{
	for (int y = 0;y < 4;y++)
	{
		for (int x = 0;x < 4;x++)
		{
			if (block[y][x])
				SCREEN->OnDrawTextColor(((x + this->xpos) * 2) + xpos, y + ypos + this->ypos, "бс",YELLOW);
		}
	}
}

TetrisBlock::TetrisBlock(bool block[4][4])
{
	xpos = 0;
	ypos = 0;

	for (int y = 0;y < 4;y++)
	{
		for (int x = 0;x < 4;x++)
		{
			this->block[y][x] = block[y][x];
		}
	}
}

TetrisBlock::~TetrisBlock()
{
}
