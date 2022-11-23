#include "Player.h"

using namespace std;

// Each object simply takes in the position it should be placed as input parameter to its constructor,
// and also sets its icon.
// Player uses the icon ’&’
Player::Player(int x, int y) : Object(x, y)
{
    icon = '&';
}


// First find the object that the player is moving to based on the x and y values.
// Use if statements for each case and in those if statements you must find the object it is going to be at, using prevHoriz/prevVert and nextHoriz/nextVert pointers.
// After those if statements you have found the object and now you must change the above and below pointers of the this object which is the player.
// You must find the object it is currently on by looping till it is at the bottom and setting its above to NULL.
// And then set the players below to the object it is moving to, and set the new object's above to the player.
void Player::move(int x, int y)
{
    if((x == 0 && y == 0) || this == NULL)
    {
        return;
    }
    if(y != -1 && y != 1 && y != 0)
    {
        return;
    }
    if(x != -1 && x != 1 && x != 0)
    {
        return;
    }
    else
    {
        Object* current = this->below;
        current->above = NULL;
        if (x == 1)
        {
            if(y == -1)
            {
                if(current->nextHoriz->prevVert != NULL && current->nextHoriz->prevVert->isSolid() == false)
                {
                    current = current->nextHoriz->prevVert;
                    current->above = this;
                    this->below = current;
                    this->xPos = current->getCoord(false);
                    this->yPos = current->getCoord(true);
                }
            }
            else if(y == 1)
            {
                if(current->nextHoriz->nextVert != NULL && current->nextHoriz->nextVert->isSolid() == false)
                {
                    current = current->nextHoriz->nextVert;
                    current->above = this;
                    this->below = current;
                    this->xPos = current->getCoord(false);
                    this->yPos = current->getCoord(true);
                }
            }
            else
            {
                if(current->nextHoriz != NULL && current->nextHoriz->isSolid() == false)
                {
                    current = current->nextHoriz;
                    current->above = this;
                    this->below = current;
                    this->xPos = current->getCoord(false);
                    this->yPos = current->getCoord(true);
                }
            }
        }
        else if (x == -1)
        {
            if(y == -1)
            {
                if(current->prevHoriz->prevVert != NULL && current->prevHoriz->prevVert->isSolid() == false)
                {
                    current = current->prevHoriz->prevVert;
                    current->above = this;
                    this->below = current;
                    this->xPos = current->getCoord(false);
                    this->yPos = current->getCoord(true);
                }
            }
            else if(y == 1)
            {
                if(current->prevHoriz->nextVert != NULL && current->prevHoriz->nextVert->isSolid() == false)
                {
                    current = current->prevHoriz->nextVert;
                    current->above = this;
                    this->below = current;
                    this->xPos = current->getCoord(false);
                    this->yPos = current->getCoord(true);
                }
            }
            else
            {
                if(current->prevHoriz != NULL && current->prevHoriz->isSolid() == false)
                {
                    current = current->prevHoriz;
                    current->above = this;
                    this->below = current;
                    this->xPos = current->getCoord(false);
                    this->yPos = current->getCoord(true);
                }
            }
        }
        else
        {
            if(y == -1)
            {
                if(current->prevVert != NULL && current->prevVert->isSolid() == false)
                {
                    current = current->prevVert;
                    current->above = this;
                    this->below = current;
                    this->xPos = current->getCoord(false);
                    this->yPos = current->getCoord(true);
                }
            }
            else
            {
                if(current->nextVert != NULL && current->nextVert->isSolid() == false)
                {
                    current = current->nextVert;
                    current->above = this;
                    this->below = current;
                    this->xPos = current->getCoord(false);
                    this->yPos = current->getCoord(true);
                }
            }
        }
    }
}








