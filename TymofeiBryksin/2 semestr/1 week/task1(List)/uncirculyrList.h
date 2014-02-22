#pragma once
#include "circulyrList.h"

class uncyrcularList : public circulyrList
{
public:
    uncyrcularList();

    void push_back(valueType x);// добавляет к концу списка
    void push_front(valueType x);//добавляет в начало списка
    void pop_front();//удаляет первый элемент в списке
    void pop_back();//удаляет последний элемент в списке
    void insert(ListElement *pos, valueType x);//вставляет элемент x после pos
    void insert(ListElement *pos, int n, valueType x);//вставляет n элементов x после pos
    void erase(ListElement *pos);// удаляет один элемент после pos

};
