#include "ColliderLib.h"

bool ColliderLib::MapCheck(int x, int y)
{
    if (x < 0 || y < 0 || x > width || y > height)
        return false;
    else
        return true;
}

bool ColliderLib::MapCheckSpecial(int x, int y)
{
    if (x < 0 || y < 0 || x > width / 2 || y > height)
        return false;
    else
        return true;
}
