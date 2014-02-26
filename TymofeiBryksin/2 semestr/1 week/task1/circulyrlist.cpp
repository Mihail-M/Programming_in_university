#include "circulyrlist.h"
#include <iostream>



CirculyrList::CirculyrList(): List()
{
}

CirculyrList::~CirculyrList()
{
    clear();
}


void CirculyrList::pushBack(valueType x)
{
    ListElement *newElem = new ListElement;
    newElem->key = x;
    if (isEmpty()) {
        pushInit(newElem);
    }
    else {
        newElem->prev = last;
        last->next = newElem;
        last = newElem;
        last->next = head;
        head->prev = last;
    }

    countOfElements++;
}

void CirculyrList::pushFront(valueType x)
{
    ListElement *newElem = new ListElement;
    newElem->key = x;

    if (isEmpty()) {
        pushInit(newElem);
    }
    else {
        newElem->next = head;
        head->prev = newElem;
        head = newElem;
        head->prev = last;
        last->next = head;
    }

    countOfElements++;
}

void CirculyrList::popFront()
{
    if(!isEmpty()) {
        ListElement *temp = head;
        head = head->next;
        head->prev = last;
        last->next = head;

        delete temp;
        countOfElements--;
    }
}

void CirculyrList::popBack()
{
    if(!isEmpty()) {
        ListElement *temp = last;
        last = last->prev;
        last->next = head;
        head->prev = last;
        delete temp;
        countOfElements--;
    }
}

void CirculyrList::erase(int pos)
{

    if(!isEmpty()) {
        ListElement *temp = getNListElem(pos);

        if(temp == last) popBack();
        else
            if(temp == head) popFront();
            else{
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
                countOfElements--;
                delete temp;
            }

    }
}

void CirculyrList::pushInit(List::ListElement *newElem)
{
    newElem->next = newElem;
    newElem->prev = newElem;

    head = newElem;
    last = newElem;
}
