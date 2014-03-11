#pragma once
typedef int valueType;

class List
{

public:
    List();
    virtual ~List();
    /// добавляет к концу списка
    virtual void pushBack(valueType x) = 0;
    ///добавляет в начало списка
    virtual void pushFront(valueType x) = 0;
    ///удаляет первый элемент в списке
    virtual void popFront() = 0;
    ///удаляет последний элемент в списке
    virtual void popBack() = 0;
    ///разворачивает список
    virtual void reverse() = 0;
    /// удаляет элемент c номером pos, либо последний
    virtual void erase(int pos) = 0;
    /// вставляет элемент в произвольную позицию
    virtual void add(int pos, int x) = 0;

    int &back();
    int &front();
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

