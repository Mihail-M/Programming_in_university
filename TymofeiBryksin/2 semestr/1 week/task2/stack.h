#pragma once

class Stack
{

public:
    typedef double valueType;

    Stack();

    bool isEmpty();

    void push(valueType x);
    void pop();

    valueType top();
    int Size();

private:
    int size;
};

