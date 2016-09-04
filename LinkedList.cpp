#include "LinkedList.h"

ads::Node::Node(int value) : value(value), next(nullptr) {}

void ads::Node::setValue(int value)
{
    this->value = value;
}

int& ads::Node::getValue()
{
    return value;
}

void ads::Node::setNext(Node* node)
{
    this->next = node;
}

ads::Node* ads::Node::getNext() const
{
    return next;
}

ads::LinkedList::LinkedList() : head(nullptr), size(0) {}

ads::Node* ads::LinkedList::push_back(int value)
{
    Node* node = new Node(value);
    if (empty())
    {
        head = node;
    }
    else
    {
        back()->setNext(node);
    }
    size++;
    return node;
}

ads::Node* ads::LinkedList::insert(size_t pos, int value)
{
    if (pos > size) return nullptr;
    Node* node = new Node(value);
    if (pos == 0)
    {
        Node* next = at(pos);
        head = node;
        node->setNext(next);
    }
    else if (pos == size)
    {
        Node* prev = at(pos - 1);
        prev->setNext(node);
    }
    else
    {
        Node* prev = at(pos - 1);
        Node* next = prev->getNext();
        prev->setNext(node);
        node->setNext(next);
    }
    size++;
    return node;
}

ads::Node* ads::LinkedList::at(size_t pos) const
{
    if (pos >= size) return nullptr;
    Node* current = head;
    size_t i = 0;
    while (current != nullptr && i < pos)
    {
        i++;
        if (current->getNext() != nullptr)
        {
            current = current->getNext();
        }
    }
    return current;
}

ads::Node* ads::LinkedList::front() const
{
    return head;
}

ads::Node* ads::LinkedList::back() const
{
    if (head == nullptr) return nullptr;
    Node* current = head;
    while (current->getNext() != nullptr) {
        current = current->getNext();
    }
    return current;
}

void ads::LinkedList::clear()
{
    Node* current = head;
    while (current->getNext() != nullptr) {
        Node* prev = current;
        current = current->getNext();
        delete prev;
    }
    delete head;
    head = nullptr;
    size = 0;
}

bool ads::LinkedList::remove(size_t pos)
{
    if (pos >= size) return false;
    if (pos == 0)
    {
        Node* next = head->getNext();
        delete head;
        head = next;
    }
    else if (pos == size - 1)
    {
        Node* prev = at(pos);
        delete prev->getNext();
        prev->setNext(nullptr);
    }
    else
    {
        Node* prev = at(pos - 1);
        Node* next = prev->getNext()->getNext();
        delete prev->getNext();
        prev->setNext(next);
    }
    size--;
    return true;
}

size_t ads::LinkedList::getSize() const
{
    return size;
}

bool ads::LinkedList::empty() const
{
    return (head == nullptr);
}
