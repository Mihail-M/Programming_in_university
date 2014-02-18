#pragma once

typedef int valueType;
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

private:
    valueType key;
    ListElement *next;
    ListElement *prev;

 };

