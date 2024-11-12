#include <catch2/catch_test_macros.hpp>
#include "Transmiter.h"
#include <filesystem>
#include <fstream>
#include <iostream>

TEST_CASE( "Encode simple string" ) {

    std::string file{"input"};
    std::ofstream outFile(file);
    outFile << "a";
    outFile.close();
    auto rootId{256};
    int e=7,r=0;
    Tree tree(rootId);
    Transmiter encoder{rootId,e,r,tree};
    auto result = encoder.encode(file);
    REQUIRE( result == "01100001" );
}
