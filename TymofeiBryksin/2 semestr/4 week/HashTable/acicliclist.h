#pragma once
#include "list.h"
#include <string>

typedef std::string valueType;

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
    void erase(valueType x);
    void add(int pos, valueType x);

private:
    void pushInit(ListElement *newElem); //вставляет в пустой список первый элемент
};
