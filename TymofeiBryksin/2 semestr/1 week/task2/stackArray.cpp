#include "stack.h"

char a[100000];

Stack::Stack()
{
    size = 0;

}



void Stack::push(valueType x)
{
    a[size++] = x;
}

valueType Stack::top()
{
    return a[size - 1];
}

void Stack::pop()
{
    --size;
}

int Stack::Size()
{
    return size;
}

bool Stack::isEmpty()
{
    return !size;
}

