#pragma once

class ColliderLib
{
private:
	// �ػ� �־��ּ���
	const int width = 80;
	const int height = 50;

public:
	// English
	bool MapCheck(int x, int y);
	// Special Character 
	bool MapCheckSpecial(int x, int y);
};

