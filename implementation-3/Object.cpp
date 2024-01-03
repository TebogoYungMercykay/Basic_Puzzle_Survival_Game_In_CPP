#include "Object.h"
using namespace std;

Object::Object(int x, int y){
    this->xPos = x;
    this->yPos = y;
    this->icon = '?';
    this->nextHoriz = NULL;
    this->nextVert = NULL;
    this->prevVert = NULL;
    this->prevHoriz = NULL;
    this->above = NULL;
    this->below = NULL;
    // Part 2
    this->lit = true;
    this->solid = false;
}
char Object::getIcon(){
    if(this != NULL){
        if(this->lit == false){
            return ' ';
        }
        Object* temp = this->above;
        if(temp == NULL){
            return this->icon;
        }
        return temp->getIcon();
    }
    return ' ';
}
int Object::getCoord(bool dimension){
    if(this != NULL){
        if(dimension == false){
            return this->xPos;
        }
        return this->yPos;
    }
    return -1;
}
Object* Object::getNext(bool dimension){
    if(this != NULL){
        if(dimension == false){
            return this->nextHoriz;
        }
        return this->nextVert;
    }
    return NULL;
}
Object* Object::getPrev(bool dimension){
    if(this != NULL){
        if(dimension == false){
            return this->prevHoriz;
        }
        return this->prevVert;
    }
    return NULL;
}
void Object::setNext(Object* obj, bool dimension){
    if(this != NULL){
        if(dimension == false){
            this->nextHoriz = obj;
        }
        else{
            this->nextVert = obj;
        }
    }
}
void Object::setPrev(Object* obj, bool dimension){
    if(this != NULL){
        if(dimension == false){
            this->prevHoriz = obj;
        }
        else{
            this->prevVert = obj;
        }
    }
}
// Part 2
void Object::update(){
    if(this != NULL){
        this->lit = false;
        // this->lit = true;
    }
}
bool Object::isSolid(){
    if(this != NULL && ((this->solid == true) || (this->above != NULL && this->above->isSolid() == true))){
        return true;
    }
    return false;
}
void Object::interact(){
    // By default, this does nothing, and a child class overrides this method.
}
// Virtual (not pure virtual) method
void Object::updateLight(char direction, int intensity){
    if(intensity == 1 || this->solid == true){
        this->lit = true;
    }
    else{
        this->lit = true;
        if(direction == 'u' && this != NULL){
            if(this->prevVert != NULL){
                this->prevVert->updateLight(direction, intensity - 1);
            }
            if(this->prevHoriz != NULL){
                this->prevHoriz->updateLight('l', 1);
            }
            if(this->nextHoriz != NULL){
                this->nextHoriz->updateLight('r', 1);
            }
        }
        else if(direction == 'd' && this != NULL){
            if(this->nextVert != NULL){
                this->nextVert->updateLight(direction, intensity - 1);
            }
            if(this->prevHoriz != NULL){
                this->prevHoriz->updateLight('l', 1);
            }
            if(this->nextHoriz != NULL){
                this->nextHoriz->updateLight('r', 1);
            }
        }
        else if(direction == 'l' && this != NULL){
            if(this->prevHoriz != NULL){
                this->prevHoriz->updateLight(direction, intensity - 1);
            }
            if(this->prevVert != NULL){
                this->prevVert->updateLight('u', 1);
            }
            if(this->nextVert != NULL){
                this->nextVert->updateLight('d', 1);
            }
        }
        else if(direction == 'r' && this != NULL){
            if(this->nextHoriz != NULL){
                this->nextHoriz->updateLight(direction, intensity - 1);
            }
            if(this->prevVert != NULL){
                this->prevVert->updateLight('u', 1);
            }
            if(this->nextVert != NULL){
                this->nextVert->updateLight('d', 1);
            }
        }
    }
}