#pragma once

typedef double valueType;

class Stack
{

public:

    Stack();
    ~Stack();

    bool isEmpty();

    virtual void push(valueType x) = 0;
    virtual valueType pop() = 0;
    virtual void clear() = 0;
    virtual valueType top() = 0;

    int size();


protected:
    int countOfElement;

    struct StackElement
    {
        StackElement* prev;
        double key;
    };

    StackElement *last;
};
