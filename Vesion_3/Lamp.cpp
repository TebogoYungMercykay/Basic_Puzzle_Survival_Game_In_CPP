#include "Lamp.h"
using namespace std;

Lamp::Lamp(int x, int y): Object(x, y){
    this->icon = '^';
    this->solid = true;
}
// Part 2
void Lamp::update(){
    if(this != NULL){
        Object* floorLevel = this;
        while(floorLevel != NULL && floorLevel->below != NULL){
            floorLevel = floorLevel->below;
        }
        floorLevel->updateLight('u', 21);
        floorLevel->updateLight('d', 21);
        floorLevel->updateLight('l', 21);
        floorLevel->updateLight('r', 21);
    }
}