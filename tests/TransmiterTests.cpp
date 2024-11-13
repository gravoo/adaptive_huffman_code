#include <catch2/catch_test_macros.hpp>
#include "Transmiter.h"
#include <filesystem>
#include <fstream>
#include <iostream>

TEST_CASE( "Encode a string" ) {

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
TEST_CASE( "Encode aa string" ) {

    std::string file{"input"};
    std::ofstream outFile(file);
    outFile << "aa";
    outFile.close();
    auto rootId{256};
    int e=7,r=0;
    Tree tree(rootId);
    Transmiter encoder{rootId,e,r,tree};
    auto result = encoder.encode(file);
    REQUIRE( result == "011000011" );
}
TEST_CASE( "Encode aaa string" ) {

    std::string file{"input"};
    std::ofstream outFile(file);
    outFile << "aaa";
    outFile.close();
    auto rootId{256};
    int e=7,r=0;
    Tree tree(rootId);
    Transmiter encoder{rootId,e,r,tree};
    auto result = encoder.encode(file);
    REQUIRE( result == "0110000111" );
}

TEST_CASE( "Encode aaab string" ) {

    std::string file{"input"};
    std::ofstream outFile(file);
    outFile << "aaab";
    outFile.close();
    auto rootId{256};
    int e=7,r=0;
    Tree tree(rootId);
    Transmiter encoder{rootId,e,r,tree};
    auto result = encoder.encode(file);
    REQUIRE( result == "0110000111001100010" );
}

TEST_CASE( "Encode aaabb string" ) {

    std::string file{"input"};
    std::ofstream outFile(file);
    outFile << "aaabb";
    outFile.close();
    auto rootId{256};
    int e=7,r=0;
    Tree tree(rootId);
    Transmiter encoder{rootId,e,r,tree};
    auto result = encoder.encode(file);
    REQUIRE( result == "011000011100110001001" );
}

TEST_CASE( "Encode aaabbaa string" ) {

    std::string file{"input"};
    std::ofstream outFile(file);
    outFile << "aaabbaa";
    outFile.close();
    auto rootId{256};
    int e=7,r=0;
    Tree tree(rootId);
    Transmiter encoder{rootId,e,r,tree};
    auto result = encoder.encode(file);
    REQUIRE( result == "01100001110011000100111" );
}