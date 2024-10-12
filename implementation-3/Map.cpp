#include "Map.h"

Map::Map(int w, int h){
    this->width = w;
    this->height = h;
    this->rows = new ObjectList*[this->height];
    for(int k_iterator = 0; k_iterator< this->height; k_iterator++){
        this->rows[k_iterator] = new ObjectList(false);
    }
    this->columns = new ObjectList*[this->width];
    for(int k_iterator = 0; k_iterator< this->width; k_iterator++){
        this->columns[k_iterator] = new ObjectList(true);
    }
    // Part 2
    this->lights = new ObjectList(false);
}
void Map::add(Object* obj){
    if(obj != NULL && (this->rows != NULL && this->columns != NULL)){
        if(obj->getCoord(false) >= 0 && obj->getCoord(true) >= 0 && obj->getCoord(true) < this->height && obj->getCoord(false) < this->width){
            if(this->rows[obj->getCoord(true)] != NULL){
                this->rows[obj->getCoord(true)]->add(obj);
            }
            if(this->columns[obj->getCoord(false)] != NULL){
                this->columns[obj->getCoord(false)]->add(obj);
            }
        }
    }
}
std::string Map::print(){
    std::string tempRows = "";
    if(this->rows != NULL){
        for(int k_iterator = 0; k_iterator< this->height; k_iterator++){
            if(this->rows[k_iterator] != NULL){
                tempRows += this->rows[k_iterator]->print() + "\n";
            }
        }
    }
    return tempRows;
}
Object* Map::getAt(int x, int y){
    if(this != NULL && (this->rows != NULL && this->columns != NULL)){
        if((y >= this->height || x >= this->width) || (x < 0 || y < 0)){
            return NULL;
        }
        Object* get_Doubly_Ptr = this->rows[y]->getHead();
        if(get_Doubly_Ptr != NULL){
            int count = 0;
            while(get_Doubly_Ptr != NULL && count < x){
                get_Doubly_Ptr = get_Doubly_Ptr->getNext(false);
                count++;
            }
        }
        if(get_Doubly_Ptr == NULL || (get_Doubly_Ptr == this->rows[y]->getHead() && x != 0)){
            return NULL;
        }
        return get_Doubly_Ptr;
    }
    return NULL;
}
void Map::addLight(Object* light){
    if(light != NULL && (light->getCoord(false) >= 0 && light->getCoord(true) >= 0 && light->getCoord(true) < this->height && light->getCoord(false) < this->width)){
        this->lights->add(light);
    }
}
void Map::resetEnvironment(){
    for(int k_iterator = 0; k_iterator < this->height; k_iterator++){
        Object* myTempObj = rows[k_iterator]->getHead();
        while(myTempObj != NULL){
            myTempObj->update();
            myTempObj = myTempObj->getNext(false);
        }
    }
}
void Map::updateEnvironment(){
    Object* myTempObj = this->lights->getHead();
    while(myTempObj != NULL){
        myTempObj->update();
        myTempObj = myTempObj->getNext(false);
    }
}
// Must revisit this destructor
Map::~Map(){
    if(this != NULL){
        if(this->rows != NULL){
            for(int k_iterator = 0; k_iterator< this->height; k_iterator++){
                Object* headPtr = rows[k_iterator]->getHead();
                Object* myTempObj = NULL;
                while(headPtr != NULL){
                    myTempObj = headPtr->getNext(false);
                    delete headPtr;
                    headPtr = myTempObj;
                }
                this->rows[k_iterator] = NULL;
            }
            this->rows = NULL;
        }
    }
}