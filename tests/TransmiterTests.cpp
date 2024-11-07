#include <catch2/catch_test_macros.hpp>
#include "Transmiter.h"

TEST_CASE( "Basic Transmiter Test", "[single-file]" ) {
    auto numberOfNodes{1};
    int e=7,r=0;
    Tree tree(numberOfNodes);
    Transmiter encoder{numberOfNodes,e,r,tree};
    REQUIRE( true );
}