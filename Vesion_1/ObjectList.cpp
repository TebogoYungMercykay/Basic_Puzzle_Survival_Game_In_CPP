#include "ObjectList.h"

using namespace std;

// Constructor which initialises everything as it should be (to an empty list), and sets the list
// dimension.
ObjectList::ObjectList(bool dim)
{
    dimension = dim;
    head = NULL;
    current = NULL;
}

// Add an object to the list. Remember that these lists are used to store objects along a dimension.
// They also need to be inserted in the correct spot along that dimension, that is to say in ascending
// order to fit with the 2D map you will be creating.
// If an object is added with the same dimension value as an existing object, it is added in front of that object
// (i.e. the new object is the head of the list).
void ObjectList::add(Object *obj)
{
    if(obj != NULL)
    {
        if (head == NULL)
        {
            head = obj;
            current = obj;
        }
        else
        {
            Object* nodePtr = NULL;
            Object* prevPtr = NULL;
            for(nodePtr = head; nodePtr != NULL && nodePtr->getCoord(dimension) < obj->getCoord(dimension); nodePtr = nodePtr->getNext(dimension))
            {
                prevPtr = nodePtr;
            }
            if (nodePtr == NULL)
            {
                prevPtr->setNext(obj, dimension);
                obj->setPrev(prevPtr, dimension);
            }
            else if (prevPtr == NULL)
            {
                obj->setNext(head, dimension);
                head->setPrev(obj, dimension);
                head = obj;
                current = head;
            }
            else
            {
                prevPtr->setNext(obj, dimension);
                obj->setPrev(prevPtr, dimension);
                obj->setNext(nodePtr, dimension);
                nodePtr->setPrev(obj, dimension);
            }
        }
    }
}

// A getter for the head member
Object* ObjectList::getHead()
{
    return head;
}

// Return a string concatenating the icons of every item (no newline at the end). Essentially
// this will be used later to print out e.g a row; iterate from start to finish, and return a string
// containing all the icons in order.
string ObjectList::print()
{
    string output = "";
    current = head;
    while (current != NULL)
    {
        output += current->getIcon();
        current = current->getNext(dimension);
    }
    return output;
}

// This is make iterating over all the items more convenient for anything using the list. Instead
// of them needing to keep track of which dimension the list uses, they simply call iterate and the
// next object along the correct dimension is returned. Should iteration be over (end of the list),
// then null is returned. Keep track of where iteration is by using the current member variable.
Object* ObjectList::iterate()
{
    if (current == NULL)
    {
        return NULL;
    }
    else
    {
        Object *temp = current;
        current = current->getNext(dimension);
        return temp;
    }
}

// This resets iteration, so that the current member points at the head of the list.
void ObjectList::reset()
{
    current = head;
}

// This is used to make sure your links are all correct. 
// The start of the string is the text “Forward:\n". 
// For each item in the list, add the following followed by a newline (for each object):
// "<icon>at (xPos,yPos) Top:Y or N ". Top is true (Y) if an object does not have anything
// above it (if above is null). After the entire list is iterated through, the text “Back:\n" is
// added, and the entire process is repeated with the list going in reverse, thereby testing the
// double-linked list.
string ObjectList::debug()
{
    string output = "Forward:\n";
    Object *temp = head;
    while (temp != NULL)
    {
        output += "<";
        output += temp->getIcon();
        output += ">";
        output += " at (";
        output += temp->getCoord(false);
        output += ",";
        output += temp->getCoord(true);
        output += ") Top:";
        if (temp->above == NULL)
        {
            output += "Y";
        }
        else
        {
            output += "N";
        }
        output += "\n";
        temp = temp->getNext(dimension);
    }
    output += "Back:\n";
    temp = head;
    while (temp->getNext(dimension) != NULL)
    {
        temp = temp->getNext(dimension);
    }
    while (temp != NULL)
    {
        output += "<";
        output += temp->getIcon();
        output += ">";
        output += " at (";
        output += temp->getCoord(false);
        output += ",";
        output += temp->getCoord(true);
        output += ") Top:";
        if (temp->above == NULL)
        {
            output += "Y";
        }
        else
        {
            output += "N";
        }
        output += "\n";
        temp = temp->getPrev(dimension);
    }
    return output;
}

