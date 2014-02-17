#pragma once

class ListElement
{
public:
    ListElement();
    ~ListElement();
    int getKey() const;
    void setKey(int value);

    ListElement *getNext() const;
    void setNext(ListElement *value);

    ListElement *getPrev() const;
    void setPrev(ListElement *value);

private:
    int key;
    ListElement *next;
    ListElement *prev;

 };

