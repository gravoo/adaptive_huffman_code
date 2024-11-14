#include "Node.h"
#include <utility>
Node::Node(char mark,int weight,int number,Node *parent):
	mark(mark),weight(weight),number(number),parent(parent){};

Node::Node(int number):
	number(number){};

Node::Node(int number,Node *parent):weight(0),number(number),parent(parent){};

char Node::getMark()
{
	return mark;
}
int Node::getWeight()
{
	return weight;
}
int Node::getNumber()
{
	return number;
}
void Node::incWeight()
{
	weight++;
}
Node *Node::getParent()
{
	return parent;
}