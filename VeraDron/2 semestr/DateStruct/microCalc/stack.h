#pragma once
#include "stackelement.h"

class Stack
{

public:

    Stack();
    ~Stack();

    bool isEmpty();

    void push(valueType x);
    int pop();
    void clear();
    valueType top();
    int Size();

private:
    int size;
    StackElement *last;

};
