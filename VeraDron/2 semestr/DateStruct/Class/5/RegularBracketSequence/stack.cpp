#include "stack.h"

Stack::Stack()
{
    size = 0;
    last = nullptr;
}

Stack::~Stack()
{
    clear();
}
void Stack::clear()
{
    while(size != 0)
        pop();
}

bool Stack::isEmpty()
{
    return (size == 0);
}

void Stack::push(valueType x)
{
    StackElement *newElem = new StackElement();

    newElem->setKey(x);
    newElem->setPrev(last);
    last = newElem;
    size++;
}

void Stack::pop()
{
    if (isEmpty())
        return;
    StackElement *temp = last;
    last = temp->getPrev();
    delete temp;
    size--;
}

valueType Stack::top()
{
    if(!isEmpty())
        return last->getKey();
    return -1;
}

int Stack::Size()
{
    return size;
}
