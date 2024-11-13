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
        std::string getPath();

    private:
        void addNode(char mark,Node *nyt);
        bool findMark(char mark, Node *tmpRoot);
        void switchNodes(Node *,Node *);
        void inorder(Node *root);
        void maxNodeInBlock(Node * tmoRoot,int weight,int number);
        void swapNodes(Node *current,Node *maxNode);
        bool findPath(Node *,std::string,std::string ,std::string);
        void findPath(Node*);
        void releseTree(Node *&ptr);
        void traverseTree(Node *ptr, Node *current);
        std::string findMe(char mark);
        std::string findNyt();

        std::string nytPath;
        std::string pathFinder;
        Node *root;
        Node *NYT;
        Node *current;
        Node *maxNode;
};

#endif // TREE_H
