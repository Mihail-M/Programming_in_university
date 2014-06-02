#include "acicliclist.h"
#include <iostream>
AciclicList::AciclicList(): List()
{
    head = new ListElement;
    last = new ListElement;
    head->prev = last->next = nullptr;
    head->next = last;
    last->prev = head;
}

AciclicList::~AciclicList()
{
    clear();
}



void AciclicList::pushBack(valueType x)
{

    ListElement *newElement = new ListElement;
    newElement->key = x;
    newElement->next = last;
    newElement->prev = last->prev;
    newElement->prev->next = newElement;
    last->prev = newElement;

    countOfElements++;
}

void AciclicList::pushFront(valueType x)
{
    ListElement *newElem = new ListElement;
    newElem->key = x;
    newElem->prev = head;
    newElem->next = head->next;
    newElem->next->prev = newElem;
    head->next = newElem;

    countOfElements++;
}


void AciclicList::popFront()
{
    if(!isEmpty()) {
        ListElement *elem = head;
        head = head->next;
        head->prev = nullptr;
        delete elem;
        countOfElements--;

    }
}

void AciclicList::popBack()
{

    if(!isEmpty()) {
        ListElement *elem = last;
        last = last->prev;
        last->next = nullptr;
        delete elem;
        countOfElements--;
    }
}



List::iterator AciclicList::insert(List::iterator position, const int &x)
{
    ListElement *newElem = new ListElement;
    newElem->key = x;
    newElem->prev = position.operator ->();
    newElem->next = position->next;
    newElem->prev->next = newElem;
    newElem->next->prev = newElem;

    countOfElements++;
    return iterator(newElem);
}

List::iterator AciclicList::erase(List::iterator position)
{
    ListElement * elem = position.operator ->();
    elem->next->prev = elem->prev;
    elem->prev->next = elem->next;
    position = iterator(elem);
    ++position;
    countOfElements--;
    delete elem;
    return position;

}


