#include "circulyrList.h"
#include <iostream>


circulyrList::ListElement *circulyrList::getNListElem(int pos)
{
    ListElement *temp = head;
    for(int i = 0; i < pos && i < size-1; i++, temp = temp->next)
    {

    }

    return temp;
}

circulyrList::circulyrList()
{
    head = nullptr;
    last = nullptr;
    size = 0;
}

circulyrList::~circulyrList()
{
    for(int i = 0; i < size; i++)
        pop_back();
}

void circulyrList::push_back(valueType x)
{
    ListElement *newElem = new ListElement;
    newElem->key = x;
    if (isEmpty()) {
        newElem->next = newElem;
        newElem->prev = newElem;

        head = newElem;
        last = newElem;
    }
    else {
        newElem->prev = last;
        last->next = newElem;
        last = newElem;
        last->next = head;
        head->prev = last;
    }

    size++;
}

void circulyrList::push_front(valueType x)
{
    ListElement *newElem = new ListElement;
    newElem->key = x;

    if (isEmpty()) {
        newElem->next = newElem;
        newElem->prev = newElem;
        head = newElem;
        last = newElem;
    }
    else {
        newElem->next = head;
        head->prev = newElem;
        head = newElem;
        head->prev = last;
        last->next = head;
    }

    size++;
}

void circulyrList::pop_front()
{
    if(!isEmpty()) {
        ListElement *temp = head;
        head = head->next;
        head->prev = last;
        last->next = head;

        delete temp;
        size--;
    }
}

void circulyrList::pop_back()
{
    if(!isEmpty()) {
        ListElement *temp = last;
        last = last->prev;
        last->next = head;
        head->prev = last;
        delete temp;
        size--;
    }
}

void circulyrList::erase(int pos)
{
    ListElement *temp = getNListElem(pos);

    if(!isEmpty()) {
        if(temp == last)pop_back();
        else
            if(temp == head)pop_front();
            else{
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
                size--;
            }
    }
    delete temp;
}



bool circulyrList::isEmpty()
{
    return (size == 0);
}

void circulyrList::show()
{
    ListElement *t = head;

    for(int i = 0; i < size; i++, t = t->next) {
        std::cout << t->key << " ";
    }
    std::cout << std::endl;

}

int circulyrList::Size() const
{
    return size;
}

