#include "circulyrList.h"
#include <iostream>

circulyrList::circulyrList()
{
    head = nullptr;
    size = 0;
}

circulyrList::~circulyrList()
{

    for(int i = 0; i < size; i++)
        pop_back();
    delete this;
}

valueType circulyrList::getSize()
{
    return size;
}

void circulyrList::push_back(valueType x)
{
    ListElement *newElem = new ListElement;
    newElem->setKey(x);
    if (isEmpty()) {
        newElem->setNext(newElem);
        newElem->setPrev(newElem);

        head = newElem;
        last = newElem;
    }
    else {
        newElem->setPrev(last);
        last->setNext(newElem);
        last = newElem;
        last->setNext(head);
        head->setPrev(last);
    }

    size++;
}

void circulyrList::push_front(valueType x)
{
    ListElement *newElem = new ListElement;
    newElem->setKey(x);

    if (isEmpty()) {
        newElem->setNext(newElem);
        newElem->setPrev(newElem);
        head = newElem;
        last = newElem;
    }
    else {
        newElem->setNext(head);
        head->setPrev(newElem);
        head = newElem;
        head->setPrev(last);
        last->setNext(head);
    }

    size++;
}

void circulyrList::pop_front()
{
    if(!isEmpty()) {
        ListElement *temp = head;
        head = head->getNext();
        head->setPrev(last);
        last->setNext(head);

        delete temp;
        size--;
    }
}

void circulyrList::pop_back()
{
    if(!isEmpty()) {
        ListElement *temp = last;
        last = last->getPrev();
        last->setNext(head);
        head->setPrev(last);
        delete temp;
        size--;
    }
}

void circulyrList::insert(ListElement *pos, valueType x)
{
    if(pos == last) push_back(x);
    else
        if(pos == head) push_front(x);
        else{
            ListElement *newElem = new ListElement;

            newElem->setKey(x);
            newElem->setNext(pos->getNext());
            newElem->setPrev(pos);

            pos->getNext()->setPrev(newElem);
            pos->setNext(newElem);
            size++;
        }
}

void circulyrList::insert(ListElement *pos, int n, valueType x)
{
    for(int i = 0; i < n; i++) {
        if(pos == last) push_back(x);
        else
            if(pos == head) push_front(x);
            else{
                ListElement *newElem = new ListElement;

                newElem->setKey(x);
                newElem->setNext(pos->getNext());
                newElem->setPrev(pos);

                pos->getNext()->setPrev(newElem);
                pos->setNext(newElem);
                size++;
            }
    }
}

void circulyrList::erase(ListElement *pos)
{
    if(!isEmpty()) {
        if(pos->getNext() == last)pop_back();
        else
            if(pos->getNext() == head)pop_front();
            else{
                pos = pos->getNext();
                ListElement *temp = pos;
                pos->getPrev()->setNext(pos->getNext());
                pos->getNext()->setPrev(pos->getPrev());
                delete temp;
                size--;
            }
    }
}

ListElement *circulyrList::find(valueType x)
{
    ListElement *temp = head;

    for(int i = 0; i < size; i++, temp = temp->getNext())
        if(temp->getKey() == x) {
            return temp;
        }

    delete temp;
    return nullptr;
}

ListElement *circulyrList::getNListElem(int n)
{
    ListElement *temp = head;
    for(int i = 0; i < n; i++, temp = temp->getNext())
    {

    }

    return temp;
}

bool circulyrList::isEmpty()
{
    return (size == 0);
}

void circulyrList::show()
{
    ListElement *t = head;

    for(int i = 0; i < size; i++, t = t->getNext()) {
        std::cout << t->getKey() << " ";
    }
    std::cout << std::endl;

}

ListElement *circulyrList::Head() const
{
    return head;
}

ListElement *circulyrList::Last() const
{
    return last;
}





