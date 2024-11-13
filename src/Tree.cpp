#include "Tree.h"
#include <algorithm>

Tree::Tree(int number)
{
    root=new Node{number};
    root->left = nullptr;
    root->right = nullptr;
    NYT=root;
    current=nullptr;
    maxNode=nullptr;
    pathFinder="";
    nytPath="";
};
Tree::Tree(const Tree& tree)
{
    root = new Node{tree.root->getMark(), tree.root->getWeight(), tree.root->getNumber(), nullptr};
    root->left = nullptr;
    root->right = nullptr;
    current = nullptr;
    maxNode = nullptr;
    NYT = root;
    pathFinder = tree.pathFinder;
    nytPath = tree.nytPath;
    traverseTree(tree.root, root);
}
void Tree::traverseTree(Node *ptr, Node *current)
{
    if(ptr)
    {
        if(ptr->left)
        {
            current->left = new Node{ptr->left->getMark(), ptr->left->getWeight(), ptr->left->getNumber(), current};
            current->left->left = nullptr;
            current->left->right = nullptr;
            NYT=current;
            traverseTree(ptr->left, current->left);
        }
        if(ptr->right)
        {
            current->right = new Node{ptr->right->getMark(), ptr->right->getWeight(), ptr->right->getNumber(), current};
            current->right->left = nullptr;
            current->right->right = nullptr;
            traverseTree(ptr->right, current->right);
        }
    }
}
Tree::~Tree()
{
    auto ptr = getRoot();
    releseTree(ptr);
}
void Tree::releseTree(Node *&ptr)
{
    if (ptr == nullptr) {
        return;
    }
    if(ptr->left == nullptr and ptr->right == nullptr)
    {
       delete ptr;
       ptr = nullptr;
    }
    else
    {
        releseTree(ptr->left);
        releseTree(ptr->right);
        delete ptr;
        ptr = nullptr;
    }
}
void Tree::addNode(char mark,Node *nyt)
{
    nyt->left=new Node{nyt->getNumber()-2,nyt};
    nyt->right=new Node{mark,1,nyt->getNumber()-1,nyt};
    nyt->left->left = nullptr;
    nyt->left->right = nullptr;
    nyt->right->left = nullptr;
    nyt->right->right = nullptr;
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
bool Tree::updateTree(char mark)
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
    {
        return ;
    }
    lowerNode->nodeSwaper(lowerNode,higherNode);
}
bool Tree ::findMark(char mark,Node *tmpRoot)
{
    if(tmpRoot)
    {
        if(tmpRoot->getMark()==mark)
        {
            current=tmpRoot;
            return true;
        }

        if(findMark(mark,tmpRoot->left))
        {
            return true;
        }
        if(findMark(mark,tmpRoot->right))
        {
            return true;
        }
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
        {
            return true;
        }

        if(findPath(root->right,mark,path,"1"))
        {
            return true;
        }

    }
    if(path.size())
    {
        path.resize(path.size()-1);
    }
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
        {
            nytPath+="1";
        }

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
    {
        return true;
    }
    return false;
}
bool Tree::isNYT(Node *node)
{
    if(node==NYT)
    {
        return true;
    }
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
std::string Tree::getNytPath()
{
    return this->nytPath;
}
