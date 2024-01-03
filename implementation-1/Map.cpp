#include "Map.h"


using namespace std;

// A constructor which takes in width and height, and creates the required rows and columns,
// filled with empty lists using the correct dimension.
Map::Map(int w, int h)
{
    width = w;
    height = h;
    rows = new ObjectList*[height];
    columns = new ObjectList*[width];
    for (int i = 0; i < height; i++)
    {
        rows[i] = new ObjectList(false);
    }
    for (int i = 0; i < width; i++)
    {
        columns[i] = new ObjectList(true);
    }

    this->lights = new ObjectList(false);
}

// Destructor, deletes all objects on the map. You can use a list’s getHead to get the start of
// each e.g row, then delete every row. Remember to then not delete the columns as well.
Map::~Map()
{
    for (int i = 0; i < height; i++)
    {
        Object *temp = rows[i]->getHead();
        while (temp != NULL)
        {
            Object *temp2 = temp->getNext(false);
            delete temp;
            temp = temp2;
        }
        rows[i] = NULL;
    }
    // delete[] rows;
    rows = NULL;
}

// Add an object to the map. In order to have all the links set up correctly, you have objectlists
// for both the rows and columns. 
// So, when an item is added, you need to add it into both the correct row, and the correct column. That way all the links are updated correctly by the lists,
// and you end up with each object in two lists making up a map. 
// From there, an object can directly reference the objects around it.
void Map::add(Object* obj)
{
    if(obj != NULL && obj->getCoord(true) < height && obj->getCoord(false) < width && obj->getCoord(false) >= 0 && obj->getCoord(true) >= 0)
    {
        int x = obj->getCoord(false);
        int y = obj->getCoord(true);
        rows[y]->add(obj);
        columns[x]->add(obj);
    }  
}

// This prints the map, row by row, and adds a newline after each row. It starts from the top
// row, working its way down. This method is used to actually print the map when running the
// game.
std::string Map::print()
{
    string map = "";
    for (int i = 0; i < height; i++)
    {
        if (rows[i] != NULL)
        {
            map += rows[i]->print();
        }
        map += '\n';
    }
    return map;
}

Object* Map::getAt(int x, int y)
{
    if (x >= 0 && x < width && y >= 0 && y < height)
    {
        Object* temp = rows[y]->getHead();
        for (int i = 0; i < x; i++)
        {
            if (temp != NULL)
            {
                temp = temp->getNext(false);
            }
            else
            {
                continue;
            }
        }
        if(x != 0 && temp == rows[y]->getHead())
        {
            return NULL;
        }
        else
        {
            return temp;
        }
    }
    return NULL;
}

void Map::addLight(Object* light)
{
    if (light != NULL && light->getCoord(true) < height && light->getCoord(false) < width && light->getCoord(false) >= 0 && light->getCoord(true) >= 0)
    {
        lights->add(light);
    }
}

void Map::resetEnvironment()
{
    for (int i = 0; i < height; i++)
    {
        Object* temp = rows[i]->getHead();
        while (temp != NULL)
        {
            temp->update();
            temp = temp->nextHoriz;
        }
    }
}

void Map::updateEnvironment()
{
    Object* temp = lights->getHead();
    while (temp != NULL)
    {
        temp->update();
        temp = temp->nextHoriz;
    }
}