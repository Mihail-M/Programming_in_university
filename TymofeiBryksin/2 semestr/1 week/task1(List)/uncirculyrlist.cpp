#include "uncirculyrlist.h"

uncirculyrList::uncirculyrList()
{
}

void uncirculyrList::push_back(valueType x)
{
    ListElement *newElem = new ListElement;
    newElem->key = x;
    if (isEmpty()) {

        head = newElem;
        head->next = nullptr;
        last = newElem;
        last->prev = nullptr;

    }
    else {
        newElem->prev = last;
        last->next = newElem;
        last = newElem;
    }
    size++;
}

void uncirculyrList::push_front(valueType x)
{
    ListElement *newElem = new ListElement;
    newElem->key = x;

    if (isEmpty()) {
        head = newElem;
        last = newElem;
    }
    else {
        newElem->next = head;
        head->prev = newElem;
        head = newElem;
    }
    size++;
}


void uncirculyrList::pop_front()
{
    if(!isEmpty()) {
        ListElement *temp = head;
        head = head->next;

        delete temp;
        size--;
    }
}

void uncirculyrList::pop_back()
{
    if(!isEmpty()) {
        ListElement *temp = last;
        last = last->prev;
        delete temp;
        size--;
    }
}

void uncirculyrList::erase(int pos)
{
    if(!isEmpty()) {
        ListElement *temp = getNListElem(pos);
        temp = temp->next;
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        delete temp;
        size--;
    }

}
