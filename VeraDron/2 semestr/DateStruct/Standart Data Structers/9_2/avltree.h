#pragma once
#include "tree.h"

class AVLTree : public Tree
{
public:
    AVLTree();
    ~AVLTree();
    void insert(int x);
    void remove(Node *x);


 private:
    void clear();
    void deleteTree(Node *temp);


    Node *balance(Node *p);
    int balance_factor(const Node *p);
    Node *rotate_right(Node *p);
    Node *rotate_left(Node *q);

    Node *insert(Node *p, int x);
    Node *remove1(Node *p, int x);
    Node* removemin(Node* p);

    AVLTree(const AVLTree &);
    AVLTree &operator = (const AVLTree &);


};

