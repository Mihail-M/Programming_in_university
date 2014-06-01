#include "list.h"
#include <iostream>

List::List(): head(nullptr), last(nullptr), countOfElements(0)
{
   // head = nullptr, last = nullptr, countOfElements = 0;
}

List::~List()
{

}

valueType &List::back()
{
    return last->key;
}

valueType &List::front()
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
    ListElement *t = head->next;

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

List::iterator List::begin()
{
     return iterator(head->next);
}

List::iterator List::end()
{
     return iterator(last);
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



bool List::iterator::operator==(const List::iterator &it) const
{
    if (element == it.element)
        return true;
    return false;
}

bool List::iterator::operator!=(const List::iterator &it) const
{
    if (element != it.element)
        return true;
    return false;
}

List::iterator List::iterator::operator++()
{
    if (element->next != nullptr)
        element = element->next;
    iterator copy(element);
    return copy;

}

List::iterator List::iterator::operator--()
{
    if (element->prev != nullptr)
        element = element->prev;
    iterator copy(element);
    return copy;

}

int &List::iterator::operator*() const
{
    return element->key;
}

List::ListElement *List::iterator::operator->() const
{
    return element;
}
