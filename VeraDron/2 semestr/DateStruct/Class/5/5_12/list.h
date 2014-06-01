#pragma once
typedef int valueType;
///
/// \brief The List class
///
class List
{

public:
    class iterator;
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
    iterator begin();
    iterator end();

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

class List::iterator
{
    friend class List;
public:
    iterator() : element(0)
    {
    }
    iterator( ListElement * _element ) : element(_element)
    {
    }

    bool operator==(const iterator &it) const;
    bool operator!=(const iterator &it) const;
    iterator operator++();
    iterator operator--();
    int & operator*() const;
    ListElement * operator->() const;
private:
    ListElement *element;
};


