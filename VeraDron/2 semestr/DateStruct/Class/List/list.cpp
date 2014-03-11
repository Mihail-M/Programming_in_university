#include "list.h"
#include <iostream>

List::List(): head(nullptr), last(nullptr), countOfElements(0)
{
   // head = nullptr, last = nullptr, countOfElements = 0;
}

List::~List()
{

}

int &List::back()
{
    return last->key;
}

int &List::front()
{
    return head->key;
}

void List::clear()
{
    while(countOfElements != 0) {
        popBack();
    }

}

bool List::isEmpty()
{
    return (countOfElements == 0);
}

void List::show()
{
    ListElement *t = head;

    for(int i = 0; i < countOfElements; i++,t = t->next)
    {

        std::cout << t->key << " ";
    }

    std::cout << std::endl;
}

int List::size() const
{
    return countOfElements;

}

List::ListElement *List::getNListElem(int pos)
{
    ListElement *temp = head;
    for(int i = 0; i < pos  && i < countOfElements - 1; i++)
    {
        temp = temp->next;
    }

    return temp;
}

