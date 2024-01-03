#include "Object.h"

using namespace std;

// A constructor which takes in the x and y positions of the object. The constructor should also
// set the icon to ’?’. The reason is that icon is a protected member, so it an be accessed by child
// classes who will set their own icons. If an object is instantiated as-is (not a derived object), a
// question mark is displayed. Remember to initialise links to null
Object::Object(int x, int y)
{
    xPos = x;
    yPos = y;
    icon = '?';
    nextHoriz = NULL;
    nextVert = NULL;
    prevHoriz = NULL;
    prevVert = NULL;
    above = NULL;
    below = NULL;
    
    lit = true;
    solid = false;
}

// A getter for the icon. If there is an object above the current object, logically it would be
// obscured. In that case, the icon displayed should be the icon of the above object. 
// This continues, until the very top object is displayed, so that visually (from top down) only the
// object at the top of the above chain is visible.
char Object::getIcon()
{
    if (lit == false)
    {
        return ' ';
    }
    else if (above == NULL)
    {
        return icon;
    }
    else
    {
        return above->getIcon();
    }
}

// Instead of having separate getters and setters for each individual position and link, there is a
// single function per set of links, with a bool value passed in. False indicates a horizontal request
// (in this case, x) and True indicates a vertical request (in this case, y).
int Object::getCoord(bool dimension)
{
    if (dimension == false)
    {
        return this->xPos;
    }
    else
    {
        return this->yPos;
    }
}

// A getter for the next links. Again, False indicates horizontal (in this case, nextHoriz) and True
// indicates vertical (in this case, nextVert).
Object *Object::getNext(bool dimension)
{
    if (dimension == false)
    {
        return this->nextHoriz;
    }
    else
    {
        return this->nextVert;
    }
}

// The same as above, except for the previous links
Object *Object::getPrev(bool dimension)
{
    if (dimension == false)
    {
        return this->prevHoriz;
    }
    else
    {
        return this->prevVert;
    }
}

// setNext and setPrev follow the same convension, except that they set links.
void Object::setNext(Object *obj, bool dim)
{
    if(obj != NULL)
    {
        if (dim == false)
        {
            this->nextHoriz = obj;
        }
        else
        {
            this->nextVert = obj;
        }
    }
}

void Object::setPrev(Object *obj, bool dim)
{
    if(obj != NULL)
    {
        if (dim == false)
        {
            this->prevHoriz = obj;
        }
        else
        {
            this->prevVert = obj;
        }
    }
}

void Object::update()
{
    lit = false;
}

bool Object::isSolid()
{
    if (solid == true || (above != NULL && above->isSolid()))
    {
        return true;
    }
    return false;
}

void Object::interact()
{

}

void Object::updateLight(char direction, int intensity)
{    
    if (intensity == 1 || solid == true)
    {
        lit = true;
        return;
    }
    else
    {
        lit = true;
        switch(direction)
        {
            case 'l':
                if (prevVert != NULL)
                {
                    prevVert->updateLight(direction, 1);
                }
                if (nextVert != NULL)
                {
                    nextVert->updateLight(direction, 1);
                }
                if (prevHoriz != NULL)
                {
                    prevHoriz->updateLight(direction, intensity-1);
                }
                break;
            case 'r':
                if (prevVert != NULL)
                {
                    prevVert->updateLight(direction, 1);
                }
                if (nextVert != NULL)
                {
                    nextVert->updateLight(direction, 1);
                }
                if (nextHoriz != NULL)
                {
                    nextHoriz->updateLight(direction, intensity-1);
                }
                break;
            case 'u':
                if (prevHoriz != NULL)
                {
                    prevHoriz->updateLight(direction, 1);
                }
                if (nextHoriz != NULL)
                {
                    nextHoriz->updateLight(direction, 1);
                }
                if (prevVert != NULL)
                {
                    prevVert->updateLight(direction, intensity-1);
                }
                break;
            case 'd':
                if (prevHoriz != NULL)
                {
                    prevHoriz->updateLight(direction, 1);
                }
                if (nextHoriz != NULL)
                {
                    nextHoriz->updateLight(direction, 1);
                }
                if (nextVert != NULL)
                {
                    nextVert->updateLight(direction, intensity-1);
                }
                break;
        }
    }
}