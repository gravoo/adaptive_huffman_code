#include "Tree.h"
#include <catch2/catch_test_macros.hpp>
#include <bitset>

TEST_CASE( "Tree Basic Test", "[single-file]" ) {
    auto rootId{12345};
    Tree sut(rootId);
}

TEST_CASE( "Tree Test Copy Constructor") {
    auto rootId{12345};
    Tree orig(rootId);
    REQUIRE(orig.updateTree('a') == true);
    REQUIRE(orig.updateTree('b') == true);
    REQUIRE(orig.updateTree('b') == false);
    {
        Tree sut(orig);
        REQUIRE(sut.updateTree('b') == false);
    }
    REQUIRE( true );
}

TEST_CASE("Tree Test Updating") {
    auto rootId{12345};
    Tree sut{rootId};

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
TEST_CASE("Delete Tree") {
    auto rootId{12345};
    Tree sut{rootId};
}