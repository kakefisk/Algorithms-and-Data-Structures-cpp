#include "Algorithm.h"
#include "LinkedList.h"

#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"

TEST_CASE( "Testing ads::add", "[add]" ) {
    REQUIRE( ads::add(2, 2) == 4 );
    REQUIRE( ads::add(1, 0) == 1 );
}

TEST_CASE( "Testing whether ads::swap swaps values", "[swap]" ) {
    int a = 5;
    int b = 10;

    SECTION( "By reference" ) {
        ads::swap(a, b);
        REQUIRE( a == 10 );
        REQUIRE( b == 5 );
    }

    SECTION( "By pointer to value" ) {
        ads::swap(&a, &b);
        REQUIRE( a == 10 );
        REQUIRE( b == 5 );
    }
}

TEST_CASE( "Testing bubblesort", "[bubblesort]" ) {
    int list[] = {5, 2, 7, 1, 8, 9, 3, 6, 4};
    int sorted[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    const int size = sizeof(list)/sizeof(list[0]);
    ads::bubblesort(list, size);
    for (int i = 0; i < size; i++) {
        REQUIRE( list[i] == sorted[i] );
    }
}

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
        REQUIRE( list.insert(list.getSize() + 1, 1) == nullptr );
    }

    SECTION( "Inserts at head" ) {
        list.insert(0, 1);
        REQUIRE( list.front()->getValue() == 1 );
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
        list.insert(list.getSize(), 10);
        REQUIRE( list.back()->getValue() == 10 );
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
}
