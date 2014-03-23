#pragma once
#include <iostream>
///TreeNode
class TreeNode
{
public:
    ///calculate  yourself
    virtual double calculate() = 0;
    ///print yourself
    virtual void print() = 0;
    /// print yourself in normal form
    virtual void printNormal() = 0;

    TreeNode *right;
    TreeNode *left;
    char value;
};


