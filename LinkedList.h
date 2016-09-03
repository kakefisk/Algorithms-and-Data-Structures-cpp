#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <cstddef>

namespace ads
{
    //!  A LinkedList Node object.
    /*!
      A more elaborate class description.
    */

    class Node
    {
    public:
        //! Constructs the node with a value.
        /*!
        \param value The value.
        */
        explicit Node(int value);

        //! Sets the node value.
        /*!
        \param value The new value.
        */
        void setValue(int value);

        //! Gets a reference to the value held by the node.
        /*!
          \return The reference to the node value.
        */
        int& getValue();

        //! Sets the pointer to the next node.
        /*!
        \param node A pointer to the next node.
        */
        void setNext(Node* node);

        //! Gets a pointer to the next node.
        /*!
          \return The pointer to the next node.
        */
        Node* getNext() const;

        const std::nullptr_t sentinel = nullptr;

    private:
        int value;
        Node* next;
    };

    //!  A linear list of nodes, each pointing to the next node.
    /*!
      A more elaborate class description.
    */

    class LinkedList
    {
    public:
        //! Constructs the LinkedList.
        LinkedList();

        //! Pushes a new Node to the back of the list with the specified value.
        /*!
        \param value The value of the new node.
        */
        void push_back(int value);

        //! Inserts a new Node at the specified position with the specified value.
        /*!
        \param pos The position to insert the new Node.
        \param value The value of the new node.
        */
        void insert(size_t pos, int value);

        //! Gets the first node in the list
        /*!
        \return A pointer to the first node in the list.
        */
        Node* front() const;

        //! Gets the last node in the list
        /*!
        \return A pointer to the last node in the list.
        */
        Node* back() const;

        //! Gets the node at the specified position.
        /*!
        \param pos The position of the node.
        \return A pointer to the node at at the specified position.
        */
        Node* at(size_t pos) const;

        //! Clears the list
        void clear();

        //! Removes the node at the specified position.
        /*!
        \param pos The position of the node that is going to be deleted.
        */
        void remove(size_t pos);

        //! Checks whether the list is empty or not.
        /*!
        \return True if the list is empty and false otherwise.
        */
        bool empty() const;

        private:
        Node* head;
        size_t size;
    };
}

#endif // LINKEDLIST_H
