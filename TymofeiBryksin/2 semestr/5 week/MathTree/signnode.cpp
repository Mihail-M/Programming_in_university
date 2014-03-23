#include "signnode.h"
#include <iostream>

SignNode::SignNode(char val)
{
    right = nullptr;
    left = nullptr;
    value = val;
}

double SignNode::calculate()
{
    if (value == '+')
        return left->calculate() + right->calculate();
    if (value == '-')
        return left->calculate() - right->calculate();
    if (value == '*')
        return left->calculate() * right->calculate();
    if (value == '/')
        return left->calculate() / right->calculate();
}

void SignNode::print()
{
    std::cout << "( " << value << " ";
    left->print();
    std::cout << " ";
    right->print();
    std::cout << " )";
}

void SignNode::printNormal()
{
    std::cout << "( ";
    left->printNormal();
    std::cout << " " << value << " ";
    right->printNormal();
    std::cout << " )";
}
