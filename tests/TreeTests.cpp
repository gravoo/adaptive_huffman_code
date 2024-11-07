#include "Tree.h"
#include <catch2/catch_test_macros.hpp>
#include <bitset>

TEST_CASE( "Tree Basic Test", "[single-file]" ) {
    auto numberOfNodes{1};
    Tree sut(numberOfNodes);
}

TEST_CASE( "Tree Test Copy Constructor") {
    auto numberOfNodes{1};
    Tree orig(numberOfNodes);
    {
        Tree sut(orig);
    }
    REQUIRE( true );
}

TEST_CASE("Tree Test Updating") {
    auto numberOfNodes{1};
    Tree sut{numberOfNodes};

    REQUIRE(sut.getNytPath() == std::string(""));
    REQUIRE(sut.getPath() == std::string(""));

    REQUIRE(sut.updateTree('a') == true);
    REQUIRE(sut.getNytPath() == std::string(""));
    REQUIRE(sut.getPath() == std::string(""));
    
    REQUIRE(sut.updateTree('a') == false);
    REQUIRE(sut.getNytPath() == std::string(""));
    REQUIRE(sut.getPath() == std::string("1"));

    REQUIRE(sut.updateTree('r') == true);
    REQUIRE(sut.getNytPath() == std::string("0"));
    REQUIRE(sut.getPath() == std::string(""));

    REQUIRE(sut.updateTree('d') == true);
    REQUIRE(sut.getNytPath() == std::string("00"));
    REQUIRE(sut.getPath() == std::string(""));

    REQUIRE(sut.updateTree('v') == true);
    REQUIRE(sut.getNytPath() == std::string("000"));
    REQUIRE(sut.getPath() == std::string(""));
}