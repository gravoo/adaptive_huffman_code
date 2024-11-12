#ifndef NODE_H
#define NODE_H

class Node
{
    public:
        Node() = delete;
        ~Node() = default;
        Node(char mark,int weight,int number,Node *parent);
        Node(int number);
        Node(int number,Node *parent);

        char getMark();
        int getWeight();
        int getNumber();

        void setMark(char);
        void setNumber(int);
        void nodeSwaper(Node *,Node *);
        void incWeight();
        Node *getParent();
        
        Node *left;
        Node *right;
        Node *parent;

    private:
        int weight;
        int number;
        char mark;
};

#endif // NODE_H
