#include "ColliderManager.h"

bool ColliderManager::MapCheck(int x, int y)
{
    if (x < 0 || y < 0 || x > width || y > height)
        return false;
    else
        return true;
}

bool ColliderManager::MapCheckSpecial(int x, int y)
{
    if (x < 0 || y < 0 || x > width / 2 || y > height)
        return false;
    else
        return true;
}

bool ColliderManager::LimitMove(int x, int y, int size_x, int size_y, int limit_x, int limit_y)
{
    if (x + size_x> limit_x || x < 0 || y + size_y > limit_y || y < 0)
        return false;

    return true;
}

bool ColliderManager::LimitArray4X4(int x, int y, bool checkBlock[4][4])
{

    return true;
}
