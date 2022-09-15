#pragma once
#include "singleton.h"

#include <utility>
using namespace std;

class ColliderManager : public singleton<ColliderManager>
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

	bool LimitMove(int x, int y, int size_x, int size_y, int limit_x, int limit_y);
	bool LimitArray4X4(int x, int y, bool checkBlock[4][4]);

	
};