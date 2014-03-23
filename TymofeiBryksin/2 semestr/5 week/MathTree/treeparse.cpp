#include "treeparse.h"

bool TreeParse::isSign(char c)
{
    return (c == '*' || c == '+' || c == '-' || c =='/');
}


TreeParse::~TreeParse()
{
    clear();
}

void TreeParse::parse(std::istream &read)
{
    parse(read,root);
}

double TreeParse::calculate()
{
    return root->calculate();
}

void TreeParse::parse(std::istream &read, TreeNode *&node)
{
    char c;
    read >> c;
    while ((c == '(' || c == ')') && c != '\z')
        read >> c;

    if (isSign(c)) {
        node = new SignNode(c);
        parse(read, node->left);
        parse(read, node->right);
    }
    else
    {
        node = new NumberNode(c);
    }
}


void TreeParse::print()
{
    root->print();
}

void TreeParse::printNormal()
{
    root->printNormal();
}

void TreeParse::clear()
{
    deleteTreeParse(root);
}

void TreeParse::deleteTreeParse(TreeNode *node)
{
    if (node != nullptr) {
        deleteTreeParse(node->left);
        deleteTreeParse(node->right);
        delete node;
    }
}
