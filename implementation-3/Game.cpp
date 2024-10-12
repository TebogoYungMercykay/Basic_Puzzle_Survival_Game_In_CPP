#include "Game.h"

Game::Game(int w, int h, std::string chars){
    int stringIconSelector = 0;
    this->map = NULL;
    this->player = NULL;
    this->exit = NULL;
    this->messages = NULL;
    if(chars.length() == (w * h) && w >= 0 && h >= 0){
        this->map = new Map(w, h);
        for(int k_iterator = 0; k_iterator < h; k_iterator++){
            for(int t_iterator = 0; t_iterator < w; t_iterator++){
                char tempIcon = chars[stringIconSelector];
                if(tempIcon == '&'){
                    Object* floorPtr = new Floor(t_iterator, k_iterator);
                    this->player = new Player(t_iterator, k_iterator);
                    floorPtr->above = this->player;
                    this->player->below = floorPtr;
                    this->map->add(floorPtr);
                }
                else if(tempIcon == '.'){
                    Object* floorPtr = new Floor(t_iterator, k_iterator);
                    this->map->add(floorPtr);
                }
                else if(tempIcon == '#'){
                    Object* wallPtr = new Wall(t_iterator, k_iterator);
                    this->map->add(wallPtr);
                }
                else if(tempIcon == '@'){
                    this->exit = new Exit(t_iterator, k_iterator);
                    Object* wallPtr = this->exit;
                    this->map->add(wallPtr);
                }
                else if(tempIcon == '^'){
                    Object* floorPtr = new Floor(t_iterator, k_iterator);
                    Object* lampPtr = new Lamp(t_iterator, k_iterator);
                    floorPtr->above = lampPtr;
                    lampPtr->below = floorPtr;
                    this->map->add(floorPtr);
                    this->map->addLight(lampPtr);
                }
                else if(tempIcon == '=' || tempIcon == '+'){
                    if(tempIcon == '+'){
                        Object* doorPtr = new Door(t_iterator, k_iterator, false);
                        this->map->add(doorPtr);
                    }
                    else{
                        Object* doorPtr = new Door(t_iterator, k_iterator, true);
                        this->map->add(doorPtr);
                    }
                }
                else{
                    Object* objectPtr = new Object(t_iterator, k_iterator);
                    this->map->add(objectPtr);
                }
                stringIconSelector += 1;
            }
        }
        this->messages = new MessageQueue(4);
        // Must Check
        this->map->resetEnvironment();
        this->map->updateEnvironment();
    }
}
std::string Game::display(){
    std::string tempStr = "";
    tempStr += this->messages->print();
    tempStr += this->map->print();
    return tempStr;
}

void Game::update(char input){
    int xCoord = -2;
    int yCoord = -2;
    if(input == '1'){
        xCoord = -1;
        yCoord = 1;
    }
    else if(input == '2'){
        xCoord = 0;
        yCoord = 1;
    }
    else if(input == '3'){
        xCoord = 1;
        yCoord = 1;
    }
    else if(input == '4'){
        xCoord = -1;
        yCoord = 0;
    }
    else if(input == '5'){
        xCoord = 0;
        yCoord = 0;
    }
    else if(input == '6'){
        xCoord = 1;
        yCoord = 0;
    }
    else if(input == '7'){
        xCoord = -1;
        yCoord = -1;
    }
    else if(input == '8'){
        xCoord = 0;
        yCoord = -1;
    }
    else if(input == '9'){
        xCoord = 1;
        yCoord = -1;
    }
    else if(input == 'e'){
        if(this->player != NULL){
            Object* floorLevel = this->player;
            while(floorLevel != NULL && floorLevel->below != NULL){
                floorLevel = floorLevel->below;
            }
            this->playerInteract(floorLevel->nextVert);
            this->playerInteract(floorLevel->prevVert);
            this->playerInteract(floorLevel->nextHoriz);
            this->playerInteract(floorLevel->prevHoriz);
        }
    }
    if(this->player == NULL){
        Message* tempMessage = new Message("Missing player");
        this->messages->addMessage(tempMessage);
    }
    else{
        if(input != 'e'  && xCoord != -2 && yCoord != -2){
            if( this->map->getAt(this->player->getCoord(false) + xCoord, this->player->getCoord(true) + yCoord) != NULL &&
                this->map->getAt(this->player->getCoord(false) + xCoord, this->player->getCoord(true) + yCoord)->isSolid()){
                Message* tempMessage = new Message("Walked into something");
                this->messages->addMessage(tempMessage);
            }
            else if(this->map->getAt(this->player->getCoord(false) + xCoord, this->player->getCoord(true) + yCoord) == NULL){
                Message* tempMessage = new Message("Out of bounds");
                this->messages->addMessage(tempMessage);
            }
            else{
                this->player->move(xCoord, yCoord);
            }
        }
    }
    // Must Check the functions
    this->map->resetEnvironment();
    this->map->updateEnvironment();
    // Up to here
    if(this->player != NULL && this->exit != NULL){
        if((this->player->getCoord(false) == this->exit->getCoord(false)) && (this->player->getCoord(true) == this->exit->getCoord(true))){
            std::string throwMe = "You reached the exit!";
            throw throwMe;
        }
    }
}
void Game::playerInteract(Object* obj){
    if(obj != NULL){
        Object* topLevel = obj->above;
        while(topLevel != NULL && topLevel->above != NULL){
            topLevel = topLevel->above;
        }
        try{
            if(topLevel == NULL){
                obj->interact();
            }
            else{
                topLevel->interact();
            }
        }
        catch(std::string e){
            Message* tempMessage = new Message(e);
            this->messages->addMessage(tempMessage);
        }
        catch(...){
            return;
        }
    }
}
Game::~Game(){
    delete this->map;
    delete messages;
    delete this->player;
}