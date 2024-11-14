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
    REQUIRE(sut.getPathToLastAddedMark() == std::string(""));

    REQUIRE(sut.updateTree('a') == true);
    REQUIRE(sut.getNytPath() == std::string(""));
    REQUIRE(sut.getPathToLastAddedMark() == std::string(""));
    
    REQUIRE(sut.updateTree('a') == false);
    REQUIRE(sut.getNytPath() == std::string(""));
    REQUIRE(sut.getPathToLastAddedMark() == std::string("1"));

    REQUIRE(sut.updateTree('r') == true);
    REQUIRE(sut.getNytPath() == std::string("0"));
    REQUIRE(sut.getPathToLastAddedMark() == std::string(""));

    REQUIRE(sut.updateTree('d') == true);
    REQUIRE(sut.getNytPath() == std::string("00"));
    REQUIRE(sut.getPathToLastAddedMark() == std::string(""));

    REQUIRE(sut.updateTree('v') == true);
    REQUIRE(sut.getNytPath() == std::string("000"));
    REQUIRE(sut.getPathToLastAddedMark() == std::string(""));
}
TEST_CASE("Delete Tree") {
    auto rootId{12345};
    Tree sut{rootId};
    sut.updateTree('v');
    sut.updateTree('a');
}
TEST_CASE("Tree Test Char Path") {
    auto rootId{12345};
    Tree sut{rootId};

    REQUIRE(sut.updateTree('a') == true);
    REQUIRE(sut.getPathToLastAddedMark() == "");
    auto resoult = sut.buildPath('a');
    REQUIRE(resoult == "1");
    REQUIRE(sut.updateTree('a') == false);
    REQUIRE(sut.getPathToLastAddedMark() == "1");
    resoult = sut.buildPath('a');
    REQUIRE(resoult == "1");
    REQUIRE(sut.updateTree('b') == true);
    resoult = sut.buildPath('a');
    REQUIRE(resoult == "1");
    resoult = sut.buildPath('b');
    REQUIRE(resoult == "01");
    REQUIRE(sut.updateTree('b') == false);
    REQUIRE(sut.getPathToLastAddedMark() == "01");
    REQUIRE(sut.updateTree('c') == true);
    REQUIRE(sut.updateTree('d') == true);
    REQUIRE(sut.updateTree('d') == false);
    REQUIRE(sut.updateTree('d') == false);
    REQUIRE(sut.updateTree('d') == false);
    REQUIRE(sut.getPathToLastAddedMark() == "0001");
    REQUIRE(sut.buildPath('b') == "01");
    REQUIRE(sut.buildPath('a') == "1");
    REQUIRE(sut.buildPath('c') == "001");
    REQUIRE(sut.buildPath('d') == "0001");
}
TEST_CASE("Tree Test Find Node") {
    auto rootId{12345};
    Tree sut{rootId};

    REQUIRE(sut.findChar('a') == nullptr);

    REQUIRE(sut.updateTree('a') == true);
    REQUIRE(sut.findChar('a')->getMark() == 'a');
    REQUIRE(sut.updateTree('b') == true);
    auto found = sut.findChar('b');
    REQUIRE(found->getMark() == 'b');
    
}