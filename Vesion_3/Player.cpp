#include "Player.h"
using namespace std;

Player::Player(int x, int y): Object(x, y){
    this->icon = '&';
}
void Player::move(int x, int y){
    // Must be implemented after the Map Class
    if((x == 0 && y == 0) || this == NULL){
        return;
    }
    if(x != -1 && x != 1 && x != 0){
        return;
    }
    if(y != -1 && y != 1 && y != 0){
        return;
    }
    else{
        // First Past: Searching for bottom (below)
        Object* temp = this;
        bool movePlayer = false;
        if(temp != NULL){
            if(temp->below != NULL){
                temp->below->above = NULL;
            }
            while(temp != NULL && temp->below != NULL){
                temp = temp->below;
            }
            // Move Player
            // Col 1
            if(x == -1 && y == -1){
                if(temp->getPrev(false) != NULL && temp->getPrev(false)->getPrev(true) != NULL && temp->getPrev(false)->getPrev(true)->isSolid() != true){
                    temp = temp->getPrev(false);
                    if(temp != NULL){
                        temp = temp->getPrev(true);
                        movePlayer = true;
                    }
                }
                else{
                    while(temp != NULL && temp->above != NULL){
                        temp = temp->above;
                    }
                    temp->above = this;
                    this->below = temp;
                    this->above = NULL;
                    return;
                }
            }
            else if(x == -1 && y == 0){
                if(temp->getPrev(false) != NULL && temp->getPrev(false)->isSolid() != true){
                    temp = temp->getPrev(false);
                    movePlayer = true;
                }
                else{
                    while(temp != NULL && temp->above != NULL){
                        temp = temp->above;
                    }
                    temp->above = this;
                    this->below = temp;
                    this->above = NULL;
                    return;
                }
            }
            else if(x == -1 && y == 1){
                if(temp->getPrev(false) != NULL && temp->getPrev(false)->getNext(true) != NULL && temp->getPrev(false)->getNext(true)->isSolid() != true){
                    temp = temp->getPrev(false);
                    if(temp != NULL){
                        temp = temp->getNext(true);
                        movePlayer = true;
                    }
                }
                else{
                    while(temp != NULL && temp->above != NULL){
                        temp = temp->above;
                    }
                    temp->above = this;
                    this->below = temp;
                    this->above = NULL;
                    return;
                }
            }
            // Col 2
            else if(x == 0 && y == -1){
                if(temp->getPrev(true) != NULL && temp->getPrev(true)->isSolid() != true){
                    temp = temp->getPrev(true);
                    movePlayer = true;
                }
                else{
                    while(temp != NULL && temp->above != NULL){
                        temp = temp->above;
                    }
                    temp->above = this;
                    this->below = temp;
                    this->above = NULL;
                    return;
                }
            }
            else if(x == 0 && y == 1){
                if(temp->getNext(true) != NULL && temp->getNext(true)->isSolid() != true){
                    temp = temp->getNext(true);
                    movePlayer = true;
                }
                else{
                    while(temp != NULL && temp->above != NULL){
                        temp = temp->above;
                    }
                    temp->above = this;
                    this->below = temp;
                    this->above = NULL;
                    return;
                }
            }
            // Col 3
            else if(x == 1 && y == -1){
                if(temp->getNext(false) != NULL && temp->getNext(false)->getPrev(true) != NULL && temp->getNext(false)->getPrev(true)->isSolid() != true){
                    temp = temp->getNext(false);
                    if(temp != NULL){
                        temp = temp->getPrev(true);
                        movePlayer = true;
                    }
                }
                else{
                    while(temp != NULL && temp->above != NULL){
                        temp = temp->above;
                    }
                    temp->above = this;
                    this->below = temp;
                    this->above = NULL;
                    return;
                }
            }
            else if(x == 1 && y == 0){
                if(temp->getNext(false) != NULL && temp->getNext(false)->isSolid() != true){
                    temp = temp->getNext(false);
                    movePlayer = true;
                }
                else{
                    while(temp != NULL && temp->above != NULL){
                        temp = temp->above;
                    }
                    temp->above = this;
                    this->below = temp;
                    this->above = NULL;
                    return;
                }
            }
            else{
                if(temp->getNext(false) != NULL && temp->getNext(false)->getNext(true) != NULL && temp->getNext(false)->getNext(true)->isSolid() != true){
                    temp = temp->getNext(false);
                    if(temp != NULL){
                        temp = temp->getNext(true);
                        movePlayer = true;
                    }
                }
                else{
                    while(temp != NULL && temp->above != NULL){
                        temp = temp->above;
                    }
                    temp->above = this;
                    this->below = temp;
                    this->above = NULL;
                    return;
                }
            }
            // Second Part: Searching for Top (Above)
            if(temp != NULL && movePlayer == true){
                while(temp != NULL && temp->above != NULL){
                    temp = temp->above;
                }
                // Inserting the object at the right Position
                // this->xPos = this->getCoord(false) + x;
                // this->yPos = this->getCoord(true) + y;
                temp->above = this;
                this->xPos = temp->getCoord(false);
                this->yPos = temp->getCoord(true);
                this->below = temp;
                this->above = NULL;
            }
        }
    }
}