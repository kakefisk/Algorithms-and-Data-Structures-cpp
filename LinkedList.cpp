#include "LinkedList.h"

Node::Node(int value)
{
    this->value = value;
}

LinkedList::LinkedList() {}

void LinkedList::push_back(int value)
{
    Node* node = new Node(value);
    if (empty())
    {
        head = node;
    }
    else
    {

    }
}

bool LinkedList::empty()
{
    return (head == null);
}
