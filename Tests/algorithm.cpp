#include "catch.hpp"
#include "Algorithm.h"

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
