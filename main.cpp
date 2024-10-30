#include <iostream>
#include <string>
#include <exception>
#include "include/Tree.h"
#include "include/Transmiter.h"

int main(int argc, char **argv)
{

    if(argc <= 2)
    {
        std::cout<<"no enough args passed\n";
    }
    else
    {
        int nodeCount=256-1;
        int e=7,r=0;

        Tree encodeTree{nodeCount};
        Transmiter encoder{nodeCount,e,r,encodeTree};

        Tree decodeTree{nodeCount};
        Transmiter decoder{nodeCount,e,r,decodeTree};
        try
        {
            switch((char)*argv[1])
            {
                case 'e':
                    encoder.encode(argv[2]);
                    break;
                case 'd':
                    decoder.decode(argv[2]);
                    break;
                default:
                    std::cout<<"code or decode?\n";
                    break;
            }
        }
        catch(std::exception& e)
        {
            std::cout << "No path specified " << e.what() << std::endl;
        }
    }



    return 0;
}
