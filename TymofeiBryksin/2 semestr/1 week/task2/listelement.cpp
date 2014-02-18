#include "listelement.h"

ListElement::ListElement()
{
}

ListElement::~ListElement()
{
}
int ListElement::getKey() const
{
    return key;
}

void ListElement::setKey(valueType value)
{
    key = value;
}
ListElement *ListElement::getNext() const
{
    return next;
}

void ListElement::setNext(ListElement *value)
{
    next = value;
}
ListElement *ListElement::getPrev() const
{
    return prev;
}

void ListElement::setPrev(ListElement *value)
{
    prev = value;
}
