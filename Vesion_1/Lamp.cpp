#include "Lamp.h"

using namespace std;


Lamp::Lamp(int x, int y) : Object(x, y) 
{
    this->solid = true;
    icon = '^';
}
    
void Lamp::update()
{   
    if(this != NULL)
    {
        below->updateLight('u', 21);
        below->updateLight('d', 21);
        below->updateLight('l', 21);
        below->updateLight('r', 21);
    } 
}