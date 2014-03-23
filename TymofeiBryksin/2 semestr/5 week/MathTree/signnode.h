#pragma once
#include "treenode.h"

class SignNode: public TreeNode
{
public:
    SignNode(char val);
    double calculate();
    void print();
    void printNormal();

};

