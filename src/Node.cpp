#include "Node.h"
#include <utility>
Node::Node(char mark,int weight,int number,Node *parent):
	mark(mark),weight(weight),number(number),
	left(nullptr),right(nullptr),parent(parent){};

Node::Node(int number):
	weight(0),number(number),mark(0),left(nullptr),
	right(nullptr),parent(nullptr){};

Node::Node(int number,Node *parent):weight(0),number(number),
		mark(0),left(nullptr),right(nullptr),parent(parent){};

char Node :: getMark()
{
	return this->mark;
}
int Node :: getWeight()
{
	return this->weight;
}
int Node :: getNumber()
{
	return this->number;
}
void Node :: setMark(char mark)
{
	this->mark=mark;
}
void Node :: setNumber(int number)
{
	this->number=number;
}
void Node :: incWeight()
{
	this->weight=this->weight+1;
}
Node * Node :: getParent()
{
	return this->parent;
}
void Node::nodeSwaper(Node *A,Node *B)
{
    std::swap(A,B);

}
