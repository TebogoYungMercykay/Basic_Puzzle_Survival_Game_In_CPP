#include "MessageQueue.h"

using namespace std;

// A constructor that takes in the message timeout. Also initialises links appropriately, and set
// current to timeout, to be decremented each time print is called.
MessageQueue::MessageQueue(int timeout)
{
    this->timeout = timeout;
    current = timeout;
    head = NULL;
    tail = NULL;
}

// Deletes any remaining messages in the queue
MessageQueue::~MessageQueue()
{
    if(head != NULL)
    {
        Message* temp = head;
        while (temp != NULL)
        {
            head = head->next;
            delete temp;
            temp = head;
        }
    }
}

// Adds a message to the back of the queue
void MessageQueue::addMessage(Message* m)
{
    if(m != NULL)
    {
        if (head == NULL)
        {
            head = m;
            tail = m;
        }
        else
        {
            tail->next = m;
            tail = m;
        }
    }
}

// Returns the current messages in the queue. Each message terminated by a newline (\n). It
// then updates the current timer. When the timer runs out, the message at the head of the
// queue needs to be removed and deleted, and the timer reset.
std::string MessageQueue::print()
{
    string result = "";
    if(head != NULL)
    {
        if (current == 0)
        {
            Message* temp = head;
            head = head->next;
            delete temp;
            temp = NULL;
            current = timeout;
        }
        Message* temp = head;
        while (temp != NULL)
        {
            result += temp->getText() + "\n";
            temp = temp->next;
        }
        current--;
    }
    return result;
}