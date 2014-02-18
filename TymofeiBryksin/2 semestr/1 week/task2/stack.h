#pragma once
#include "stackelement.h"

class Stack
{

public:
    Stack();

    bool isEmpty();

    void push(valueType x);
    void pop();

    valueType top();
    int Size();

private:
    StackElement *last;
    int size;
};

