#include "uncirculyrlist.h"

uncyrcularList::uncyrcularList()
{
}

void uncyrcularList::push_back(valueType x)
{
    ListElement *newElem = new ListElement;
    newElem->setKey(x);
    if (isEmpty()) {

        head = newElem;
        head->setNext(nullptr);
        last = newElem;
        last->setPrev(nullptr);

    }
    else {
        newElem->setPrev(last);
        last->setNext(newElem);
        last = newElem;
    }
    size++;
}

void uncyrcularList::push_front(valueType x)
{
    ListElement *newElem = new ListElement;
    newElem->setKey(x);

    if (isEmpty()) {
        head = newElem;
        last = newElem;
    }
    else {
        newElem->setNext(head);
        head->setPrev(newElem);
        head = newElem;
    }
    size++;
}


void uncyrcularList::pop_front()
{
    if(!isEmpty()) {
        ListElement *temp = head;
        head = head->getNext();

        delete temp;
        size--;
    }
}

void uncyrcularList::pop_back()
{
    if(!isEmpty()) {
        ListElement *temp = last;
        last = last->getPrev();
        delete temp;
        size--;
    }
}

void uncyrcularList::insert(ListElement *pos, valueType x)
{
    ListElement *newElem = new ListElement;

    newElem->setKey(x);
    newElem->setNext(pos->getNext());
    newElem->setPrev(pos);

    pos->getNext()->setPrev(newElem);
    pos->setNext(newElem);
    size++;
}

void uncyrcularList::insert(ListElement *pos, int n, valueType x)
{
    for(int i = 0; i < n; i++) {

        pos = pos->getNext();
        ListElement *temp = pos;
        pos->getPrev()->setNext(pos->getNext());
        pos->getNext()->setPrev(pos->getPrev());
        delete temp;
        size--;
    }
}

void uncyrcularList::erase(ListElement *pos)
{
    if(!isEmpty()) {
        pos = pos->getNext();
        ListElement *temp = pos;
        pos->getPrev()->setNext(pos->getNext());
        pos->getNext()->setPrev(pos->getPrev());
        delete temp;
        size--;
    }

}
