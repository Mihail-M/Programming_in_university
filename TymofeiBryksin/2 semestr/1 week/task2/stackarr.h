#pragma once
#include "stack.h"

typedef double valueType;

class stackArr : public stack
{

public:
     stackArr();
     void push(valueType x);
     valueType pop();
     void clear();
     valueType top();

private:
    valueType a[100000];

};

