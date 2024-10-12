#include "ObjectList.h"

using namespace std;

ObjectList::ObjectList(bool dim)
{
    ObjectList::dimension = dim;
    ObjectList::head = NULL;
    ObjectList::current = NULL;
}

void ObjectList::add(Object* obj)
{
    if(obj != NULL)
    {
        if (ObjectList::head == NULL)
        {
            ObjectList::head = obj;
            ObjectList::current = obj;
        }
        else if (ObjectList::dimension == false)
        {
            Object* currentptr;
            Object* previous;
            currentptr = previous = NULL;
            for(currentptr = ObjectList::head; currentptr != NULL && currentptr->getCoord(false) < obj->getCoord(false); currentptr = currentptr->getNext(false))
            {
                previous = currentptr;
            }
            if (currentptr == NULL)
            {
                previous->setNext(obj, false);
                obj->setPrev(previous, false);
            }
            else if (previous == NULL)
            {
                obj->setNext(ObjectList::head, false);
                ObjectList::head->setPrev(obj, false);
                ObjectList::head = obj;
                ObjectList::current = ObjectList::head;
            }
            else
            {
                previous->setNext(obj, false);
                obj->setPrev(previous, false);
                obj->setNext(currentptr, false);
                currentptr->setPrev(obj, false);
            }
        }
        else
        {
            Object* currentptr;
            Object* previous;
            currentptr = previous = NULL;
            for(currentptr = ObjectList::head; currentptr != NULL && currentptr->getCoord(true) < obj->getCoord(true); currentptr = currentptr->getNext(true))
            {
                previous = currentptr;
            }
            if (currentptr == NULL)
            {
                previous->setNext(obj, true);
                obj->setPrev(previous, true);
            }
            else if (previous == NULL)
            {
                obj->setNext(ObjectList::head, true);
                ObjectList::head->setPrev(obj, true);
                ObjectList::head = obj;
                current = ObjectList::head;
            }
            else
            {
                previous->setNext(obj, true);
                obj->setPrev(previous, true);
                obj->setNext(currentptr, true);
                currentptr->setPrev(obj, true);
            }
        }
    }
}

Object* ObjectList::getHead()
{
    return ObjectList::head;
}

string ObjectList::print()
{
    string p = "";
    current = ObjectList::head;
    while (current != NULL)
    {
        p += current->getIcon();
        current = current->getNext(ObjectList::dimension);
    }
    this->reset();
    return p;
}

Object* ObjectList::iterate()
{
    if (ObjectList::current != NULL)
    {
        Object* temp = ObjectList::current;
        ObjectList::current = ObjectList::current->getNext(ObjectList::dimension);
        return temp;
    }
    return NULL;
}

void ObjectList::reset()
{
    ObjectList::current = ObjectList::head;
}

string ObjectList::debug()
{
    string p("");
    if (head != NULL)
    {
        p = "Forward:\n";
        string x, y, i;
        string topLess = "Y";
        Object* currentptr = ObjectList::head;
        stringstream ss;
        while (currentptr != NULL)
        {
            ss << currentptr->getCoord(true);
            ss >> y;
            ss.clear();
            ss << currentptr->getCoord(false);
            ss >> x;
            ss.clear();
            ss << currentptr->getIcon();
            ss >> i;
            ss.clear();
            if (currentptr->above != NULL)
            {
                topLess = 'N';
            }
            string p1 = "<" + i + ">" + " at (" + x + ',' + y + ") Top:" + topLess + '\n';
            p += p1;
            if (!currentptr->getNext(ObjectList::dimension))
            {
                break;
            }
            else
            {
                currentptr = currentptr->getNext(ObjectList::dimension);
            }
        }
        p += "Back:\n";
        while (currentptr != NULL)
        {
            ss << currentptr->getCoord(true);
            ss >> y;
            ss.clear();
            ss << currentptr->getCoord(false);
            ss >> x;
            ss.clear();
            ss << currentptr->getIcon();
            ss >> i;
            ss.clear();
            if (currentptr->above != NULL)
            {
                topLess = 'N';
            }
            string p1 = "<" + i + ">" + " at (" + x + ',' + y + ") Top:" + topLess + '\n';
            p += p1;
            currentptr = currentptr->getPrev(ObjectList::dimension);
        }
    }
    return p;
}