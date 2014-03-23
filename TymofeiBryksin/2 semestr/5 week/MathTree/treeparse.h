#pragma once
#include <iostream>
#include "numbernode.h"
#include "signnode.h"
#include "treenode.h"

class TreeParse
{
public:
    ~TreeParse();
    ///parse expression
    void parse(std::istream &read);
    ///calculate expression
    double calculate();
    /// print expression
    void print();
    /// print expression in normal form
    void printNormal();
    /// clear expression tree
    void clear();

private:
    void deleteTreeParse(TreeNode *node);
    void parse(std::istream &read, TreeNode *&a);
    TreeNode* root;
    ///is sign?
    bool isSign(char c);
};
