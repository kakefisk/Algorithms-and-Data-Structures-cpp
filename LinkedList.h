#ifndef LINKEDLIST_H
#define LINKEDLIST_H

namespace ads
{
    //!  A test class.
    /*!
      A more elaborate class description.
    */
    class Node
    {
    public:
        Node(int value);
        void setValue(int value);
        //! Gets the value held by the node.
        /*!
          \return the value of the node.
        */
        int getValue();
        void setNext();
        void setPrev();
        void getNext();
        void getPrev();

    private:
        int value;
        Node* prev;
        Node* next;
    };

    //!  A test class 2.
    /*!
      A more elaborate class description.
    */

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
