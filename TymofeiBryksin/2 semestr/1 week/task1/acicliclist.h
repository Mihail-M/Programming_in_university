#pragma once
#include "list.h"

typedef double valueType;

class AciclicList : public List
{
public:
    AciclicList();
    ~AciclicList();

    void pushBack(valueType x);// добавляет к концу списка
    void pushFront(valueType x);//добавляет в начало списка
    void popFront();//удаляет первый элемент в списке
    void popBack();//удаляет последний элемент в списке

    void erase(int pos);// удаляет элемент c номером pos

private:
    void pushInit(ListElement *newElem); //вставляет в пустой список первый элемент
};
