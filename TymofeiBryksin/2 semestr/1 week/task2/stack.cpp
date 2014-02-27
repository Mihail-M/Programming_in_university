#include "stack.h"

Stack::Stack(): countOfElement(0)
{
}

Stack::~Stack()
{

}

bool Stack::isEmpty()
{
    return (countOfElement == 0);
}

int Stack::size()
{
    return countOfElement;
}


