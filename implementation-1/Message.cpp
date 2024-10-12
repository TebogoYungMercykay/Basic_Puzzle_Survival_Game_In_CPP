#include "Message.h"

using namespace std;

// A constructor that takes in the message to store. Also sets next link to null
Message::Message(string t)
{
    text = t;
    next = NULL;
}

// Returns the message text
string Message::getText()
{
    return text;
}


