#include "stackarr.h"

StackArr::StackArr()
{
}

void StackArr::push(valueType x){

    a[countOfElement++] = x;

}

valueType StackArr::pop() {

    return a[--countOfElement];

}

void StackArr::clear(){

    countOfElement = 0;

}

valueType StackArr::top(){

    return a[countOfElement - 1];
}
