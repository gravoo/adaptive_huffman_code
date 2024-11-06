#include <iostream>
#include <string>
#include <exception>
#include "include/Tree.h"
#include "include/Transmiter.h"
#include "argh.h"

int main(int argc, char **argv)
{
    auto cmdl = argh::parser({"-e ,-d"});
    cmdl.parse(argc, argv);
    
    if (cmdl["-h"] || cmdl["--help"] || (!cmdl({"e"}) && !cmdl({"d"}))) {
        std::cout << "Usage:\n";
        std::cout << "-e=<encoded file to be decoded> \n";
        std::cout << "-d=<decoded file to be encoded> \n";
        return 0;
    }
    if(cmdl({"e"}))
    {
        std::cout << "Encoding file" << cmdl({"e"}).str() <<" \n";
        int nodeCount=256-1;
        int e=7,r=0;
        Tree encodeTree{nodeCount};
        Transmiter encoder{nodeCount,e,r,encodeTree};
        encoder.encode(cmdl({"e"}).str());

    }
    else if(cmdl({"d"}))
    {
        std::cout << "Decoding file" << cmdl({"d"}).str() <<" \n";
        int nodeCount=256-1;
        int e=7,r=0;

        Tree decodeTree{nodeCount};
        Transmiter decoder{nodeCount,e,r,decodeTree};  
        decoder.decode(cmdl({"d"}).str()); 
    }

    return 0;
}
