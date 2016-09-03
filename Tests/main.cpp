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

TEST_CASE( "Testing LinkedList::at", "[linkedlist]" ) {
    ads::LinkedList list;
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
        REQUIRE( list.at(9) == nullptr );
    }
}
