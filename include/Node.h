#ifndef NODE_H
#define NODE_H
#include<iostream>

class Node
{
    public:
        Node();
        virtual ~Node();
        Node(char mark,int weight,int number,Node *parent):
            mark(mark),weight(weight),number(number),
            left(nullptr),right(nullptr),parent(parent){};

        Node(int number):
            weight(0),number(number),mark(0),left(nullptr),
            right(nullptr),parent(nullptr){};

        Node(int number,Node *parent):weight(0),number(number),
           mark(0),left(nullptr),right(nullptr),parent(parent){};

        char getMark();
        int getWeight();
        int getNumber();

        void setMark(char);
        void setNumber(int);
        void setWeight(int);
        void nodeSwaper(Node *,Node *);
        void incWeight();
        bool isExternal();

        Node *getParent();
        Node *left;
        Node *right;
        Node *parent;

    protected:
    private:
        int weight;
        int number;
        char mark;

};

#endif // NODE_H
