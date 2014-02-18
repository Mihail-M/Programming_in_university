#include "stack.h"
#include <stackelement.h>

StackElement *last;
Stack::Stack()
{
    size = 0;
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


