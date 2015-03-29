#ifndef TRANSMITER_H
#define TRANSMITER_H
#include <fstream>
#include <string>
#include "Node.h"
#include "Tree.h"

class Transmiter
{
    public:
        Transmiter();
        Transmiter(int nodeCount,int e,int r,Tree &huffmanTree);
        virtual ~Transmiter();
        void encode(std::string filePath);
        void decode(std::string filePath);
    protected:
    private:
        void getCharacter();
        void decodeChar(Node *pointer,char c);
        void toBits(char c);
        Node *updateTree(char c);
        Node *getNode(Node *,char);
        Node *upTree(int &,std::string &,char);
        char toChar(std::string bits);

        int nodeCount;
        int e;
        int r;
        Tree huffmanTree;
};

#endif // TRANSMITER_H
