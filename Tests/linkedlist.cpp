#include "catch.hpp"
#include "LinkedList.h"

TEST_CASE( "Testing LinkedList::push_back", "[linkedlist]" ) {

    ads::LinkedList list;
    ads::Node* node = list.push_back(10);

    SECTION( "Checks if correct value is pushed and can be accessed" ) {
        REQUIRE( node->getValue() == 10 );
    }

    SECTION( "Checks if size of list is incremented" ) {
        size_t size = list.getSize();
        list.push_back(20);
        REQUIRE( list.getSize() == size + 1 );
    }
}

TEST_CASE( "Testing LinkedList::insert", "[linkedlist]" ) {

    ads::LinkedList list;

    SECTION( "Tries to insert at a negative position" ) {
        REQUIRE( list.insert(-1, 1) == nullptr );
    }

    SECTION( "Tries to insert at pos > size" ) {
        REQUIRE( list.insert(list.getSize() + 1, 4) == nullptr );
    }

    SECTION( "Inserts at head" ) {
        list.insert(0, 5);
        REQUIRE( list.front()->getValue() == 5 );
    }

    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.push_back(4);

    SECTION( "Inserts in middle" ) {
        list.insert(2, 10);
        REQUIRE( list.at(2)->getValue() == 10 );
    }

    SECTION( "Inserts at size. Similar to push_back." ) {
        list.insert(list.getSize(), 20);
        REQUIRE( list.back()->getValue() == 20 );
    }

    SECTION( "Checks if size of list is incremented" ) {
        size_t size = list.getSize();
        list.insert(0, 20);
        REQUIRE( list.getSize() == size + 1 );
    }
}

TEST_CASE( "Testing LinkedList::empty", "[linkedlist]" ) {

    ads::LinkedList list;

    SECTION( "Checks for empty list" ) {
        REQUIRE( list.empty() == true );
    }

    list.push_back(1);

    SECTION( "Checks for non-empty list" ) {
        REQUIRE( list.empty() == false );
    }
}

TEST_CASE( "Testing LinkedList::front", "[linkedlist]" ) {

    ads::LinkedList list;

    SECTION( "Checks for empty list" ) {
        REQUIRE( list.front() == nullptr );
    }

    list.push_back(1);
    list.push_back(2);
    list.push_back(3);

    SECTION( "Checks for non-empty list" ) {
        REQUIRE( list.front()->getValue() == 1 );
    }
}

TEST_CASE( "Testing LinkedList::back", "[linkedlist]" ) {

    ads::LinkedList list;

    SECTION( "Checks for empty list" ) {
        REQUIRE( list.back() == nullptr );
    }

    list.push_back(1);
    list.push_back(2);
    list.push_back(3);

    SECTION( "Checks for non-empty list" ) {
        REQUIRE( list.back()->getValue() == 3 );
    }
}

TEST_CASE( "Testing LinkedList::at", "[linkedlist]" ) {

    ads::LinkedList list;

    SECTION( "Tries to access a node in a empty list" ) {
        REQUIRE( list.at(0) == nullptr );
    }

    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.push_back(4);
    list.push_back(5);
    list.push_back(6);
    list.push_back(7);
    list.push_back(8);
    list.push_back(9);

    SECTION( "Tries a negative index" ) {
        REQUIRE( list.at(-1) == nullptr );
    }

    SECTION( "Accesses the head" ) {
        REQUIRE( list.at(0)->getValue() == 1 );
    }

    SECTION( "Accesses a middle node" ) {
        REQUIRE( list.at(5)->getValue() == 6 );
    }

    SECTION( "Accesses the tail" ) {
        REQUIRE( list.at(8)->getValue() == 9 );
    }

    SECTION( "Tries an index >= size" ) {
        REQUIRE( list.at(list.getSize()) == nullptr );
    }
}

TEST_CASE( "Testing LinkedList::remove", "[linkedlist]" ) {

    ads::LinkedList list;

    SECTION( "Tries to remove from an empty list" ) {
        REQUIRE( list.remove(0) == false );
    }

    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.push_back(4);
    list.push_back(5);
    list.push_back(6);
    list.push_back(7);
    list.push_back(8);
    list.push_back(9);

    SECTION( "Tries a negative index" ) {
        REQUIRE( list.remove(-1) == false );
    }

    SECTION( "Remove first node" ) {
        REQUIRE( list.remove(0) == true );
        REQUIRE( list.front()->getValue() == 2 );
    }

    SECTION( "Removes middle node" ) {
        REQUIRE( list.remove(4) == true );
        REQUIRE( list.at(4)->getValue() == 6 );
    }

    SECTION( "Removes the last node" ) {
        REQUIRE( list.remove(list.getSize() - 1) == true );
        REQUIRE( list.back()->getValue() == 8 );
    }

    SECTION( "Tries an index >= size" ) {
        REQUIRE( list.remove(list.getSize()) == false );
    }

    SECTION( "Checks if size of list is decremented" ) {
        size_t size = list.getSize();
        list.remove(0);
        REQUIRE( list.getSize() == size - 1 );
    }
}

TEST_CASE( "Node::getNext, Node::setNext()" , "[linkedlist]" )
{
    ads::Node* node1 = new ads::Node(1);

    SECTION( "Testing if it return nullptr if there is no next node" )
    {
        REQUIRE( node1->getNext() == nullptr );
    }

    SECTION( "Testing if next can be set and is set properly" )
    {
        ads::Node* node2 = new ads::Node(2);
        node1->setNext(node2);
        REQUIRE( node1->getNext() == node2 );
        REQUIRE( node1->getNext()->getValue() == 2 );
        delete node2;
    }
    delete node1;
}

TEST_CASE( "LinkedList::clear" , "[linkedlist]" )
{
    ads::LinkedList list;

    SECTION( "Clearing an empty list" )
    {
        list.clear();
        REQUIRE( list.getSize() == 0 );
        REQUIRE( list.front() == nullptr );
    }

    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.push_back(4);
    list.push_back(5);

    SECTION( "Clearing non-empty list" )
    {
        /*ads::Node* back = list.back();
        ads::Node* node = list.front()->getNext();*/
        list.clear();
        REQUIRE( list.getSize() == 0 );
        REQUIRE( list.front() == nullptr );
        //REQUIRE( back == nullptr );
        //REQUIRE( node == nullptr );
    }
}


