#pragma once
#include "stack.h"

typedef double valueType;

class StackArr : public Stack
{

public:
     StackArr();
     void push(valueType x);

     valueType pop();
     void clear();
     valueType top();

private:
    valueType a[100000];

};

