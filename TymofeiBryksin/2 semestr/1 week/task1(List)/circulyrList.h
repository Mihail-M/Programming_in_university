#pragma once
typedef double valueType;
class circulyrList
{

public:

    circulyrList();
    ~circulyrList();

    virtual void push_back(valueType x);// добавляет к концу списка
    virtual void push_front(valueType x);//добавляет в начало списка
    virtual void pop_front();//удаляет первый элемент в списке
    virtual void pop_back();//удаляет последний элемент в списке

    virtual void erase(int pos);// удаляет элемент c номером pos

    bool isEmpty();
    void show();

    int Size() const;

protected:

    struct ListElement {
        valueType key;
        ListElement *next;
        ListElement *prev;
    };


    ListElement *head;
    ListElement *last;
    int size;
    ListElement *getNListElem(int pos); // возвращает pos-й элемент списка

};

