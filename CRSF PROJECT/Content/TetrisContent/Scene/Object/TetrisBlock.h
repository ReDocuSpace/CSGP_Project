#pragma once
class TetrisBlock
{
private:
	int xpos;
	int ypos;
	
public:
	bool block[4][4];

	void OnInit(bool block[4][4]);
	void OnChange(bool block[4][4]);
	void OnReset();

	void BlockMove(bool xpos, bool ypos, int speed = 1);
	void BlockRotation();
	
	void Draw(int x, int y);

	int GetXpos() { return xpos; }
	int GetYpos() { return ypos; }

	TetrisBlock(bool block[4][4]);
	TetrisBlock() {};
	~TetrisBlock();

};

