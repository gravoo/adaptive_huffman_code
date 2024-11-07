#include "Tree.h"

Tree::Tree()
{}
Tree::~Tree()
{
   //releseTree(root);
}
void Tree::releseTree(Node *root)
{
    if(root)
    {
        releseTree(root->left);
            delete root->left;
        releseTree(root->right);
            delete root->right;
    }
}
void Tree::addNode(char mark,Node *nyt)
{
	nyt->left=new Node{nyt->getNumber()-2,nyt};
	nyt->right=new Node{mark,1,nyt->getNumber()-1,nyt};
	nyt->incWeight();
	NYT=nyt->left;
}
void Tree :: maxNodeInBlock(Node * tmoRoot,int weight,int number)
{
	if(tmoRoot)
	{
		if(tmoRoot->getWeight()==weight&&tmoRoot->getNumber()>number)
		{
			maxNode=tmoRoot;
			number=tmoRoot->getNumber();
		}
		maxNodeInBlock(tmoRoot->left,weight,number);
		maxNodeInBlock(tmoRoot->right,weight,number);

	}
}
void Tree::swapNodes(Node *current,Node *maxNode)
{
    if(current->parent!=maxNode&&maxNode!=nullptr)
		{
			switchNodes(current,maxNode);
		}
}
bool Tree :: updateTree(char mark)
{
    bool flag;


	findMe(mark);
	if(current)
	{

		maxNodeInBlock(root,current->getWeight(),current->getNumber());
        swapNodes(current,maxNode);
        current->incWeight();
        flag=false;

	}
	else
	{
        findNyt();
		addNode(mark,NYT);
		current=NYT->parent;
		flag=true;
	}
    while(current!=root)
    {
        current=current->parent;
        maxNode=current;
        maxNodeInBlock(root,current->getWeight(),current->getNumber());
        swapNodes(current,maxNode);
        maxNode->incWeight();
    }
    //inorder(root);
	//std::cout<<std::endl;
	current=nullptr;
	maxNode=nullptr;
	return flag;

}
Node* Tree::getRoot()
{
    return root;
}
void Tree :: switchNodes(Node *lowerNode,Node *higherNode)
{
	if(lowerNode==higherNode)
		return ;

    lowerNode->nodeSwaper(lowerNode,higherNode);

}
bool Tree ::findMark(char mark,Node *tmpRoot)
{
	if(tmpRoot){
		if(tmpRoot->getMark()==mark)
        {
            current=tmpRoot;
            return true;
        }

		if(findMark(mark,tmpRoot->left))
            return true;
		if(findMark(mark,tmpRoot->right))
            return true;
	}

	return false;
}
std::string Tree::findMe(char mark)
{
    pathFinder="";
    findPath(root,std::string(1,mark),"","");
    return pathFinder;
}
std::string Tree::findNyt()
{
    nytPath="";
    findPath(NYT);
    std::reverse(std::begin(nytPath),std::end(nytPath));
    return nytPath;
}
bool Tree::findPath(Node *root,std::string mark,std::string path,std::string side)
{
    if(root)
    {
        path+=side;
        if(!mark.compare(std::string(1,root->getMark())))
        {
            pathFinder=path;
            current=root;
            return true;
        }
        if(findPath(root->left,mark,path,"0"))
            return true;

        if(findPath(root->right,mark,path,"1"))
            return true;

    }
    if(path.size())
        path.resize(path.size()-1);
    return false;
}
void Tree::findPath(Node *nyt)
{
    if(nyt->parent)
    {
        if(nyt->parent->left==nyt)
        {
            nytPath+="0";

        }
        else
            nytPath+="1";

        findPath(nyt->parent);
    }
}
void Tree::inorder(Node *root)
{
    if(root)
    {
        std::cout<<root->getMark()<<" "<<root->getWeight();
        std::cout<<"(";
        inorder(root->left);
        std::cout<<")";
        std::cout<<"(";
        inorder(root->right);
        std::cout<<")";
    }
}
std::string Tree::getPath()
{
    return this->pathFinder;
}
bool Tree::isExternalNode(Node *node)
{
    if(!(node->left||node->right))
        return true;
    return false;
}
bool Tree::isNYT(Node *node)
{
    if(node==NYT)
        return true;
    return false;
}
Node *Tree::getLeft(Node *node)
{
    return node->left;
}
Node *Tree::getRight(Node *node)
{
    return node->right;
}
std::string  Tree:: getNytPath()
{
    return this->nytPath;
}
