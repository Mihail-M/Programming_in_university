#pragma once
#include "listelement.h"
class List
{

public:

    List();
    ~List();
    void push_front(valueType x);//добавляет в начало списка
    void pop_front();//удаляет первый элемент в списке
    void insert(ListElement *pos, valueType x);//вставляет элемент x после pos
    void insert(ListElement *pos, int n, valueType x);//вставляет n элементов x после pos
    void erase(ListElement *pos);// удаляет один элемент после pos
    ListElement *find(valueType x); // найти по значению(если элемент не найден, возвращается nullptr)
    ListElement *getNListElem(int n); // вернуть n-й элемент(если n > size, возвращается last)
    void show();

    ListElement *Head() const;

protected:
    bool isEmpty();
    void push_back(valueType x);// добавляет к концу списка
    ListElement *Last() const;
    void pop_back();//удаляет последний элемент в списке
    int getSize();
    int size;
    ListElement *last;

private:
    ListElement *head;
};
