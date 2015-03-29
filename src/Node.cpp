#include "../include/Node.h"

Node::Node()
{}
Node::~Node()
{}
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
void  Node :: setWeight(int weight)
{
	this->weight=weight;
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
