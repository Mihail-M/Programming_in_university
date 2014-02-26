#include "acicliclist.h"

AciclicList::AciclicList(): List()
{
}

AciclicList::~AciclicList()
{
    clear();
}



void AciclicList::pushBack(valueType x)
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
    }
    countOfElements++;
}

void AciclicList::pushFront(valueType x)
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
    }
    countOfElements++;
}


void AciclicList::popFront()
{
    if(!isEmpty()) {
        ListElement *temp = head;
        head = head->next;

        delete temp;
        countOfElements--;
    }
}

void AciclicList::popBack()
{
    if(!isEmpty()) {
        ListElement *temp = last;
        last = last->prev;
        delete temp;
        countOfElements--;
    }
}

void AciclicList::erase(int pos)
{
    if(!isEmpty()) {
        ListElement *temp = getNListElem(pos);
        temp = temp->next;
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        delete temp;
        countOfElements--;
    }
}


void AciclicList::pushInit(List::ListElement *newElem)
{
    head = newElem;
    last = newElem;
    head->next = nullptr;
    last->prev = nullptr;
}
