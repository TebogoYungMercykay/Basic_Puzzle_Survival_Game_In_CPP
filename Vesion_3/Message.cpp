#include "Message.h"
using namespace std;

Message::Message(std::string t){
    this->text = t;
    this->next = NULL;
}
std::string Message::getText(){
    return this->text;
}