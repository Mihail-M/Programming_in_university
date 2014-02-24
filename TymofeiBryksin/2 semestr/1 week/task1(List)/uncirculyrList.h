#pragma once
#include "circulyrList.h"

typedef double valueType;

class uncirculyrList : public circulyrList
{
public:
    uncirculyrList();

    void push_back(valueType x);// добавляет к концу списка
    void push_front(valueType x);//добавляет в начало списка
    void pop_front();//удаляет первый элемент в списке
    void pop_back();//удаляет последний элемент в списке
    void erase(int pos);// удаляет 'один элемент с номером pos

};
