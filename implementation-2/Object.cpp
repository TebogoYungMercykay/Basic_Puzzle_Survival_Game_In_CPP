#include "Object.h"

using namespace std;

Object::Object(int x, int y)
{
    Object::icon = '?';
    Object::xPos = x;
    Object::yPos = y;

    Object::above = NULL;
    Object::below = NULL;

    Object::Object::nextHoriz = NULL;
    Object::Object::nextVert = NULL;
    Object::Object::prevHoriz = NULL;
    Object::Object::prevVert = NULL;
}

char Object::getIcon()
{
    char i;
    if (above == NULL)
    {
        i = Object::icon;
    }
    else
    {
        i = Object::above->getIcon();
    }
    return i;
}

int Object::getCoord(bool dimension)
{
    int i = 0;
    if (dimension == false)
    {
        i = Object::xPos;
    }
    else
    {
        i = Object::yPos;
    }
    return i;
}

Object* Object::getNext(bool dimension)
{
    Object* i = NULL;
    if (dimension == false)
    {
        i = Object::Object::nextHoriz;
    }
    else
    {
        i = Object::Object::nextVert;
    }
    return i;
}

Object* Object::getPrev(bool dimension)
{
    Object* i = NULL;
    if (dimension == false)
    {
        i = Object::Object::prevHoriz;
    }
    else
    {
        i = Object::Object::prevVert;
    }
    return i;
}

void Object::setNext(Object *obj, bool dim)
{
    if(obj != NULL)
    {
        if (dim == false)
        {
            Object::Object::nextHoriz = obj;
        }
        else
        {
            Object::Object::nextVert = obj;
        }
    }
}

void Object::setPrev(Object *obj, bool dim)
{
    if(obj != NULL)
    {
        if (dim == false)
        {
            Object::Object::prevHoriz = obj;
        }
        else
        {
            Object::Object::prevVert = obj;
        }
    }
}