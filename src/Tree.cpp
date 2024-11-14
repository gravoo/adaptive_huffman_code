#include "Tree.h"
#include <algorithm>

Tree::Tree(int number)
{
    root=new Node{number};
    NYT=root;
};
Tree::Tree(const Tree& tree)
{
    root = new Node{tree.root->getMark(), tree.root->getWeight(), tree.root->getNumber(), nullptr};
    NYT = root;
    pathToLastAddedMark = tree.pathToLastAddedMark;
    nytPath = tree.nytPath;
    copyAndAllocateNewNodes(tree.root, root);
}
void Tree::copyAndAllocateNewNodes(Node *ptr, Node *current)
{
    if(ptr)
    {
        if(ptr->left)
        {
            current->left = new Node{ptr->left->getMark(), ptr->left->getWeight(), ptr->left->getNumber(), current};
            NYT=current;
            copyAndAllocateNewNodes(ptr->left, current->left);
        }
        if(ptr->right)
        {
            current->right = new Node{ptr->right->getMark(), ptr->right->getWeight(), ptr->right->getNumber(), current};
            copyAndAllocateNewNodes(ptr->right, current->right);
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
    if (ptr == nullptr) 
    {
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
void Tree::addNode(char mark,Node *ptr)
{
    ptr->left=new Node{ptr->getNumber()-2, ptr};
    ptr->right=new Node{mark,1,ptr->getNumber()-1, ptr};
    ptr->incWeight();
    NYT=ptr->left;
}
void Tree::maxNodeInBlock(Node * ptr,int weight,int number)
{
    if(ptr)
    {
        if((ptr->getWeight()==weight)&&(ptr->getNumber()>number))
        {
            maxNode=ptr;
            number=ptr->getNumber();
        }
        maxNodeInBlock(ptr->left,weight,number);
        maxNodeInBlock(ptr->right,weight,number);
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
    bool charAdded{false};
    pathToLastAddedMark = buildPath(mark);
    auto ptr = findChar(mark);
    if(ptr)
    {
        maxNodeInBlock(root,ptr->getWeight(),ptr->getNumber());
        swapNodes(ptr,maxNode);
        ptr->incWeight();
        charAdded=false;
    }
    else
    {
        findNyt();
        addNode(mark,NYT);
        ptr=NYT->parent;
        charAdded=true;
    }
    balanceTree(ptr, root);
    current=nullptr;
    maxNode=nullptr;
    return charAdded;
}
void Tree::balanceTree(Node *ptr, Node *root)
{
    while(ptr!=root)
    {
        ptr=ptr->parent;
        maxNode=ptr;
        maxNodeInBlock(root,ptr->getWeight(),ptr->getNumber());
        swapNodes(ptr,maxNode);
        maxNode->incWeight();
    } 
}
Node* Tree::getRoot()
{
    return root;
}
void Tree::switchNodes(Node *lowerNode,Node *higherNode)
{
    if(lowerNode==higherNode)
    {
        return ;
    }
    std::swap(lowerNode,higherNode);
}
std::string Tree::findNyt()
{
    nytPath="";
    findPath(NYT);
    std::reverse(std::begin(nytPath),std::end(nytPath));
    return nytPath;
}
std::string Tree::buildPath(char mark)
{
    std::string path, resoult;
    buildPath(getRoot(), mark, path, resoult);
    return resoult;
}
void Tree::buildPath(Node *ptr,char mark, std::string path, std::string &resoult)
{
    if(ptr == nullptr)
    {
        return;
    }
    if(ptr->getMark() == mark)
    {
        resoult = path;
        return;
    }
    buildPath(ptr->left, mark, path + "0", resoult);
    buildPath(ptr->right, mark, path + "1", resoult);
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

std::string Tree::getPathToLastAddedMark()
{
    return pathToLastAddedMark;
}

std::string Tree::getNytPath()
{
    return nytPath;
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
Node *Tree::findChar(char mark)
{
    auto root = getRoot();
    if(root == nullptr)
    {
        return nullptr;
    }
    return findChar(root, mark);
}
Node *Tree::findChar(Node *ptr, char mark)
{
    if(ptr == nullptr)
    {
        return nullptr;
    }
    if(ptr->getMark() == mark)
    {
        return ptr;
    }
    auto leftResoult = findChar(ptr->left, mark);
    if(findChar(ptr->left, mark) != nullptr)
    {
            return leftResoult;
    }
    return findChar(ptr->right, mark);
}