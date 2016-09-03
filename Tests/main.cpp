#include "Algorithm.h"

#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"

TEST_CASE( "Testing ads::add", "[add]" ) {
    REQUIRE( ads::add(2, 2) == 4 );
    REQUIRE( ads::add(1, 0) == 1 );
}

TEST_CASE( "Testing whether ads::swap swaps values", "[swap]" ) {
    int a = 5;
    int b = 10;
    ads::swap(a, b);
    REQUIRE( a == 10 );
    REQUIRE( b == 5 );
}
