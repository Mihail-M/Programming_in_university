#pragma once
typedef double valueType;

class ListElement
{
public:
    ListElement();
    ~ListElement();

    int getKey() const;
    void setKey(valueType value);

    ListElement *getNext() const;
    void setNext(ListElement *value);

    ListElement *getPrev() const;
    void setPrev(ListElement *value);

protected:
    valueType key;
    ListElement *next;
private:
    ListElement *prev;

 };
