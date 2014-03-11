#pragma once
#include "list.h"

typedef int valueType;

class AciclicList : public List
{
public:
    AciclicList();
    ~AciclicList();

    void pushBack(valueType x);
    void pushFront(valueType x);
    void popFront();
    void popBack();
    void reverse();
    void erase(int pos);
    void add(int pos, int x);

private:
    void pushInit(ListElement *newElem); //вставляет в пустой список первый элемент
};
