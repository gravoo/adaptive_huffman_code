#ifndef TREE_H
#define TREE_H
#include "Node.h"
#include <iostream>
#include <string>
class Tree
{
    public:
        Tree() = default;
        ~Tree();
        Tree(int number);
        Tree(const Tree&);
        bool isNYT(Node *node);
        bool isExternalNode(Node *node);
        bool updateTree(char mark);

        Node* getRoot();
        Node* getLeft(Node *);
        Node* getRight(Node *);
        std::string getNytPath();
        std::string getPathToLastAddedMark();
        Node *findChar(char);
        std::string buildPath(char mark);
    private:
        void addNode(char mark,Node *);
        void switchNodes(Node *,Node *);
        void maxNodeInBlock(Node * tmoRoot,int weight,int number);
        void swapNodes(Node *,Node *);
        void releseTree(Node *&ptr);
        void copyAndAllocateNewNodes(Node *ptr, Node *current);
        void balanceTree(Node *ptr, Node *root);
        void buildPath(Node *ptr,char mark, std::string, std::string&);
        Node *findChar(Node *, char);
        std::string buildNytPath();
        void buildPath(Node *ptr, Node *target, std::string path, std::string &resoult);
        std::string buildPathToNode(Node *target);
        std::string nytPath;
        std::string pathToLastAddedMark;
        Node *root{nullptr};
        Node *NYT{nullptr};
        Node *maxNode{nullptr};
};

#endif // TREE_H
