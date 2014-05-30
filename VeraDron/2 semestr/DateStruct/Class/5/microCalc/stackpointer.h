#pragma once
#include "stack.h"

class StackPointer : public Stack
{
public:
    StackPointer();
    ~StackPointer();
    void push(valueType x);
    valueType pop();
    void clear();
    valueType top();
protected:

    struct StackElement
    {
        StackElement* prev;
        double key;
    };

    StackElement *last;

};

