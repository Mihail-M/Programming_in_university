#include "numbernode.h"
#include <iostream>



NumberNode::NumberNode(char val)
{
    right = nullptr;
    left = nullptr;
    value = val;
}

double NumberNode::calculate()
{
    return value - '0';
}

void NumberNode::print()
{
    std::cout << value;
}

void NumberNode::printNormal()
{
    print();
}
