#pragma once
#include "treenode.h"

class NumberNode: public TreeNode
{
public:
    NumberNode(char val);
    double calculate();
    void print();
    void printNormal();
};

