#include <iostream>
#include <string>
#include <exception>
#include "include/Tree.h"
#include "include/Transmiter.h"

int main(int argc, char **argv)
{

    int nodeCount=256-1;
    int e=7,r=0;

    Tree encodeTree{nodeCount};
    Transmiter encoder{nodeCount,e,r,encodeTree};

    Tree decodeTree{nodeCount};
    Transmiter decoder{nodeCount,e,r,decodeTree};

    try{

        switch((char)*argv[1])
        {
            case 'e':
                encoder.encode(argv[2]);
                break;
            case 'd':
                decoder.decode(argv[2]);
                break;
            default:
                std::cout<<"nie sprecyzowano czy kodowac czy dekodowac";
                break;
        }
    }
    catch(std::exception& e)
    {
        std::cout << "No path specified " << e.what() << std::endl;
    }



    return 0;
}
