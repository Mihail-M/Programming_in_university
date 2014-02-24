#include "stack.h"

stack::stack()
{
    size = 0;
    last = nullptr;
}

stack::~stack()
{
    clear();
}
void stack::clear()
{
    while(size != 0)
        pop();
}

bool stack::isEmpty()
{
    return (size == 0);
}

void stack::push(valueType x)
{
    StackElement *newElem = new StackElement();

    newElem->key = x;
    newElem->prev = last;
    last = newElem;
    size++;
}

valueType stack::pop()
{
    if (isEmpty())
        return -1;
    valueType key = last->key;
    StackElement *temp = last;
    last = temp->prev;
    delete temp;
    size--;
    return key;
}

valueType stack::top()
{
    if(!isEmpty())
        return last->key;
    return -1;
}

int stack::Size()
{
    return size;
}


