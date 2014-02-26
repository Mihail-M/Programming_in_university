#pragma once
typedef double valueType;

class List
{

public:
    List();
    ~List();

    virtual void pushBack(valueType x) = 0;// добавляет к концу списка
    virtual void pushFront(valueType x) = 0;//добавляет в начало списка
    virtual void popFront() = 0;//удаляет первый элемент в списке
    virtual void popBack() = 0;//удаляет последний элемент в списке

    virtual void erase(int pos) = 0;// удаляет элемент c номером pos

    void clear();
    bool isEmpty();
    void show();

    int size() const;

protected:

    struct ListElement {
        valueType key;
        ListElement *next;
        ListElement *prev;
    };

    ListElement *head;
    ListElement *last;
    int countOfElements;

    ListElement *getNListElem(int pos); // возвращает pos-й элемент списка
};

