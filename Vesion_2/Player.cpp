#include "Player.h"

using namespace std;

Player::Player(int x, int y) : Object(x, y)
{
    Player::icon = '&';
}

void Player::move(int x, int y)
{
    if((x == 0 && y == 0) || this == NULL)
    {
        return;
    }
    else if(y >= -1 && y < 2 && x >= -1 && x < 2 )
    {
        Object* curr = Player::below;
        curr->above = NULL;
        if (x == 0)
        {
            if(y != 0)
            {
                if(y == -1)
                {
                    curr = curr->prevVert;
                    curr->above = this;
                    Player::below = curr;
                    Player::yPos += y;
                    Player::xPos += x;
                }
                else
                {
                    curr = curr->nextVert;
                    curr->above = this;
                    Player::below = curr;
                    Player::yPos += y;
                    Player::xPos += x;
                }

            }
        }
        if (x == 1)
        {
            if(y == 1)
            {
                curr = curr->nextHoriz->nextVert;
                curr->above = this;
                Player::below = curr;
                Player::yPos += y;
                Player::xPos += x;
            }
            else if(y == -1)
            {
                curr = curr->nextHoriz->prevVert;
                curr->above = this;
                Player::below = curr;
                Player::yPos += y;
                Player::xPos += x;
            }
            else
            {
                curr = curr->nextHoriz;
                curr->above = this;
                Player::below = curr;
                Player::yPos += y;
                Player::xPos += x;
            }
        }
        else if (x == -1)
        {
            if(y == 1)
            {
                curr = curr->prevHoriz->nextVert;
                curr->above = this;
                Player::below = curr;
                Player::yPos += y;
                Player::xPos += x;
            }
            else if(y == -1)
            {
                curr = curr->prevHoriz->prevVert;
                curr->above = this;
                Player::below = curr;
                Player::yPos += y;
                Player::xPos += x;
            }
            else
            {
                curr = curr->prevHoriz;
                curr->above = this;
                Player::below = curr;
                Player::yPos += y;
                Player::xPos += x;
            }
        }
    }
    else
    {
        return;
    }
}