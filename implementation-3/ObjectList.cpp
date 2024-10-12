#include "ObjectList.h"
using namespace std;

ObjectList::ObjectList(bool dimension){
    this->dimension = dimension;
    this->head = NULL;
    this->current = NULL;
}
void ObjectList::reset(){
    this->current = head;
}
Object* ObjectList::iterate(){
    Object* tempIterate = this->current;
    if(tempIterate != NULL){
        this->current = this->current->getNext(this->dimension);
        return tempIterate;
    }
    return NULL;
}
Object* ObjectList::getHead(){
    return this->head;
}
std::string ObjectList::print(){
    Object* print_Doubly_Ptr = this->head;
    if(print_Doubly_Ptr != NULL){
        std::string temp = "";
        while(print_Doubly_Ptr != NULL){
            temp += print_Doubly_Ptr->getIcon();
            print_Doubly_Ptr = print_Doubly_Ptr->getNext(this->dimension);
        }
        return temp;
    }
    return "";
}
std::string ObjectList::debug(){
    ObjectList* debug_ObjectList_Ptr = this;
    Object* print_Doubly_Ptr;
    const int sizeS = debug_ObjectList_Ptr->print().length();
    std::string* stringArray = new std::string[sizeS];
    std::string temp = "";
    int index = 0;
    debug_ObjectList_Ptr->reset();
    if(debug_ObjectList_Ptr != NULL){
        while(print_Doubly_Ptr = debug_ObjectList_Ptr->iterate()){
            std::string tempstring = "";
            std::string tempstring1 = "";
            std::string tempstring2 = "";
            std::string tempstring3 = "Y\n";
            if(print_Doubly_Ptr->above != NULL){
                tempstring3 = "N\n";
            }
            std::stringstream tempStreamn;
            tempStreamn << print_Doubly_Ptr->getCoord(false);
            tempStreamn >> tempstring;
            tempStreamn.clear();
            tempStreamn << print_Doubly_Ptr->getCoord(true);
            tempStreamn >> tempstring1;
            tempStreamn.clear();
            tempStreamn << print_Doubly_Ptr->getIcon();
            tempStreamn >> tempstring2;
            stringArray[index++] = "<" + tempstring2 + "> at (" + tempstring + "," + tempstring1 + ") Top:" + tempstring3;
        }
    }
    if(sizeS > 0){
        temp = "Forward:\n";
        for(index = 0; index < sizeS; index++){
            temp += stringArray[index];
        }
        temp += "Back:\n";
        for(index = index - 1; index >= 0; index--){
            temp += stringArray[index];
        }
    }
    else{
        temp = "Forward:\n";
        temp += "Back:\n";
    }
    delete [] stringArray;
    stringArray = NULL;
    return temp;
}
void ObjectList::add(Object* obj){
    if(obj != NULL){
        if(this->head == NULL){
            this->head = obj;
            this->current = this->head;
        }
        else{
            Object* insert_Doubly_Ptr = this->head;
            Object* prev_insert_Doubly_Ptr = NULL;
            while(insert_Doubly_Ptr && insert_Doubly_Ptr->getCoord(this->dimension) < obj->getCoord(this->dimension)){
                prev_insert_Doubly_Ptr = insert_Doubly_Ptr;
                insert_Doubly_Ptr = insert_Doubly_Ptr->getNext(this->dimension);
            }
            if(insert_Doubly_Ptr == NULL){
                prev_insert_Doubly_Ptr->setNext(obj, this->dimension);
                obj->setPrev(prev_insert_Doubly_Ptr, this->dimension);
            }
            else if(prev_insert_Doubly_Ptr == NULL){
                obj->setNext(head, dimension);
                this->head->setPrev(obj, this->dimension);
                this->head = obj;
                this->current = this->head;
            }
            else{
                prev_insert_Doubly_Ptr->setNext(obj, this->dimension);
                obj->setPrev(prev_insert_Doubly_Ptr, this->dimension);
                obj->setNext(insert_Doubly_Ptr, this->dimension);
                insert_Doubly_Ptr->setPrev(obj, this->dimension);
            }
        }
    }
}