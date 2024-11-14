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

        void incWeight();
        Node *getParent();
        
        Node *left{nullptr};
        Node *right{nullptr};
        Node *parent{nullptr};

    private:
        int weight{0};
        int number{0};
        char mark{0};
};

#endif // NODE_H
