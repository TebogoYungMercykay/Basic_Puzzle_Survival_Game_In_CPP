#include "Door.h"
using namespace std;

Door::Door(int x, int y, bool open): Object(x, y){
    this->open = open;
    if(this->open == true){
        this->icon = '=';
        this->solid = false;
    }
    else{
        this->icon = '+';
        this->solid = true;
    }
}
void Door::interact(){
    if(this->open == true){
        this->open = false;
        this->icon = '+';
        this->solid = true;
        std::string throwMe = "You closed a door";
        throw throwMe;
    }
    else{
        this->open = true;
        this->icon = '=';
        this->solid = false;
        std::string throwMe = "You opened a door";
        throw throwMe;
    }
}
void Door::updateLight(char direction, int intensity){
    Object::updateLight(direction, intensity);
}