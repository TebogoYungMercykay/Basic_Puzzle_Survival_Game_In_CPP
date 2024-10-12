#include "Door.h"

using namespace std;

Door::Door(int x, int y, bool open) : Object(x, y)
{
    this->open = open;
    int k = 1;
    if(open == true)
    {
        k = 2;
    }
    switch(k)
    {
        case 1:
            solid = true;
            icon = '+';
            break;

        case 2:
            solid = false;
            icon = '=';
            break;
        default:
            break;
    }
}

void Door::interact()
{
    string s = "You closed a door";
    int k = 1;
    if(open == true)
    {
        k = 2;
    }
    switch(k)
    {
        case 1:
            s = "You opened a door";
            icon = '=';
            open = true;
            solid = false;
            break;

        case 2:
            icon = '+';
            open = false;
            solid = true;
            break;
        default:
            break;
    }
    throw s;
}

void Door::updateLight(char direction, int intensity)
{
    Object::updateLight(direction, intensity);
}