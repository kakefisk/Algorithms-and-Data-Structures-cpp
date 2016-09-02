#ifndef LINKEDLIST_H
#define LINKEDLIST_H

namespace ads
{
    class Node
    {
    public:
        Node(int value);
        void setValue();
        void getValue();
        void setNext();
        void setPrev();
        void getNext();
        void getPrev();

    private:
        int value;
        Node* prev;
        Node* next;
    };

    class LinkedList
    {
    public:
        LinkedList();
        void push_back(int value);
        void insert(size_t index, int value);
        bool empty();

        private:
        Node* head;
        size_t size;
    };
}

#endif // LINKEDLIST_H
