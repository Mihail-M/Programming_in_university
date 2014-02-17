#pragma once
#include "listelement.h"
class List
{

public:

    List();
    ~List();
    int getSize();
    void push_back(int x);// добавляет к концу списка
    void push_front(int x);//добавляет в начало списка
    void pop_front();//удаляет первый элемент в списке
    void pop_back();//удаляет последний элемент в списке
    void insert(ListElement *pos, int x);//вставляет элемент x после pos
    void insert(ListElement *pos, int n, int x);//вставляет n элементов x после pos
    void erase(ListElement *pos);// удаляет один элемент после pos
    ListElement *find(int x); // найти по значению(если элемент не найден, возвращается nullptr)
    ListElement *getNListElem(int n); // вернуть n-й элемент(если n > size, возвращается last)

    bool isEmpty();
    void show();

    ListElement *Head() const;

    ListElement *Last() const;

private:
    ListElement *head;
    ListElement *last;


    int size;
};

