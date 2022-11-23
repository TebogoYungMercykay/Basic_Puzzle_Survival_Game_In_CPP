#include "MessageQueue.h"
using namespace std;

MessageQueue::MessageQueue(int timeOut){
    this->timeout = timeOut;
    this->current = this->timeout;
    this->head = NULL;
    this->tail = NULL;
}
std::string MessageQueue::print(){
    if(this->head != NULL && this->tail != NULL){
        if(this->current == 0){
            Message* messagePtr2 = this->head->next;
            delete this->head;
            this->head = NULL;
            this->head = messagePtr2;
            this->current = this->timeout;
        }
        Message* messagePtr = this->head;
        std::string printStr = "";
        while(messagePtr){
            printStr += messagePtr->getText() + "\n";
            messagePtr = messagePtr->next;
        }
        this->current -= 1;
        return printStr;
    }
    return "";
}
void MessageQueue::addMessage(Message* message){
    if(this->head == NULL){
        this->head = message;
        this->tail = message;
    }
    else{
        this->tail->next = message;
        this->tail = message;
    }
}
MessageQueue::~MessageQueue(){
    if(this->head != NULL){
        Message* messagePtr = this->head;
        while(messagePtr != NULL){
            this->head = this->head->next;
            delete messagePtr;
            messagePtr = this->head;
        }
        this->head = NULL;
        this->tail = NULL;
        this->timeout = 0;
        this->current = 0;
    }
}