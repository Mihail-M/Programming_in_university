#include "stackpointer.h"

StackPointer::StackPointer():last(nullptr)
{
}

StackPointer::~StackPointer()
{
    clear();
}

void StackPointer::push(valueType x)
{
    StackElement *newElem = new StackElement();

    newElem->key = x;
    newElem->prev = last;
    last = newElem;
    countOfElement++;
}

valueType StackPointer::pop()
{
    if (isEmpty())
        return -1;
    valueType key = last->key;
    StackElement *temp = last;
    last = temp->prev;
    delete temp;
    countOfElement--;
    return key;
}

void StackPointer::clear()
{
    while(countOfElement != 0)
        pop();

}

valueType StackPointer::top()
{
    if(!isEmpty())
        return last->key;

    return -1;
}
