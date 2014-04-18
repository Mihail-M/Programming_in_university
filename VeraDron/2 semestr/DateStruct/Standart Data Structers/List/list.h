#pragma once
typedef int valueType;
///
/// \brief The List class
///
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
    /// вставляет элемент после pos
    virtual void add(int pos, int x) = 0;

    ///возвращает ссылку на значение последнего элемента
    valueType &back();
    ///возвращает ссылку на значение первого элемента
    valueType &front();
    ///очищает список
    void clear();
    ///если список пуст возращает true
    bool isEmpty();
    ///выводит список на экран
    void show();
    ///возращает размер списка
    int size() const;

protected:
    ///вспомогательная структура( элемент списка)
    struct ListElement {
        valueType key;
        ListElement *next;
        ListElement *prev;
    };

    ListElement *head;
    ListElement *last;
    int countOfElements;
    /// возвращает pos-й элемент списка

    ListElement *getNListElem(int pos);
 private:
    List(List &a);
    List &operator = (List const &b);
};

