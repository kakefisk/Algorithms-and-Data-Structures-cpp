#include "LinkedList.h"

ads::Node::Node(int value)
{
    this->value = value;
}

ads::LinkedList::LinkedList() {}

void ads::LinkedList::push_back(int value)
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

bool ads::LinkedList::empty()
{
    return (head == null);
}
