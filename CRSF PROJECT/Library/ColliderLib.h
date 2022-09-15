#pragma once

class ColliderLib
{
private:
	// 해상도 넣어주세요
	const int width = 80;
	const int height = 50;

public:
	// English
	bool MapCheck(int x, int y);
	// Special Character 
	bool MapCheckSpecial(int x, int y);
};

