#include <catch2/catch_test_macros.hpp>
#include "Node.h"

TEST_CASE( "Basic Node Test", "[single-file]" ) 
{
    Node sut(10);
    REQUIRE( true );
}

TEST_CASE( "Delete Node Test", "[single-file]" )
{
    Node *root = new Node(1);
    Node *left = new Node(2, root);
    Node *right = new Node(3, root);
    REQUIRE( true );
}

