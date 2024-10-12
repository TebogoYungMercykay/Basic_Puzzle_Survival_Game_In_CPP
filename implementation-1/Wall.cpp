#include "Wall.h"

using namespace std;

Wall::Wall(int x, int y) : Object(x, y)
{
    solid = true;
    icon = '#';
}

void Wall::updateLight(char direction, int intensity)
{
    lit = true;
}