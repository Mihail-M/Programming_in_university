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
    iterator insert(iterator position, const int &x);
    iterator erase(iterator position);


private:
    AciclicList(AciclicList &a);
    AciclicList &operator = (AciclicList const &b);
};
