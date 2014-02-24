#include "stackarr.h"

stackArr::stackArr()
{
}

void stackArr::push(valueType x){

    a[size++] = x;

}

valueType stackArr::pop() {

    return a[--size];

}
void stackArr::clear(){

    size = 0;

}

valueType stackArr::top(){

    return a[size - 1];
}
