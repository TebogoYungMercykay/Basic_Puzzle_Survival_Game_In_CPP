#include "Map.h"
using namespace std;

Map::Map(int w, int h)
{
    Map::width = w;
    Map::height = h;
    Map::rows = new ObjectList*[Map::height];
    Map::columns = new ObjectList*[Map::width];
    for (int i = 0; i < Map::height; i++)
    {
        Map::rows[i] = new ObjectList(false);
    }
    for (int i = 0; i < Map::width; i++)
    {
        Map::columns[i] = new ObjectList(true);
    }
}

void Map::add(Object* obj)
{
    if(obj != NULL)
    {
        if (obj->getCoord(false) >= 0 && obj->getCoord(true) >= 0 && obj->getCoord(true) < Map::height && obj->getCoord(false) < Map::width)
        {
            Map::rows[obj->getCoord(true)]->add(obj);
            Map::columns[obj->getCoord(false)]->add(obj);
        }
    }  
}

std::string Map::print()
{
    string p = "";
    for (int i = 0; i < Map::height; i++)
    {
        p += Map::rows[i]->print() + "\n";
    }
    return p;
}

Map::~Map()
{
    for (int i = 0; i < Map::height; i++)
    {
        Object *temp = Map::rows[i]->getHead();
        while (temp != NULL)
        {
            Object *temp2 = temp->getNext(false);
            delete temp;
            temp = temp2;
        }
        Map::rows[i] = NULL;
    }
    Map::rows = NULL;
}