#ifndef TREE_H
#define TREE_H
#include "Node.h"
#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <iterator>
class Tree
{
    public:
        Tree();
        virtual ~Tree();
        Tree(int number)
        {
            root=new Node{number};
            NYT=root;
            current=nullptr;
            maxNode=nullptr;
            pathFinder="";
            nytPath="";
        };

        bool isNYT(Node *node);
        bool isExternalNode(Node *node);
        bool updateTree(char mark);

        Node* getRoot();
        Node* getLeft(Node *);
        Node* getRight(Node *);
        std::string getNytPath();
        std::string getPath();

    protected:
    private:
        void addNode(char mark);
        void addNode(char mark,Node *nyt);
        bool findMark(char mark, Node *tmpRoot);
        void printTO();
        void switchNodes(Node *,Node *);
        void inorder(Node *root);
        void maxNodeInBlock(Node * tmoRoot,int weight,int number);
        void swapNodes(Node *current,Node *maxNode);
        bool findPath(Node *,std::string,std::string ,std::string);
        void findPath(Node*);
        void releseTree(Node *root);
        std::string findMe(char mark);
        std::string findNyt();
        std::string nytPath;
        std::string pathFinder;
        Node *root;
        Node *NYT;
        Node *current;
        Node *maxNode;
        Node *addNode(char mark,Node *tmp,Node *nyt);
        Node* findMaxInBlock(Node *,Node *,int);
        Node* findNode();
};

#endif // TREE_H
