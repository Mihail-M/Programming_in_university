#include "list.h"
#include <iostream>

List::List(): head(nullptr), last(nullptr), countOfElements(0)
{
}

List::~List()
{

}

bool List::find(valueType x)
{
    if (isEmpty()) return 0;
    ListElement *current = head;
    for (int i = 0; i < countOfElements; i++, current = current->next)
        if (current->key == x)
            return 1;
    return 0;

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
    while (countOfElements != 0) {
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

int List::getIndListElemWithKey(valueType x)
{
    int pos = -1;
    ListElement *current = head;
    for (int i = 0; i < countOfElements; i++, current = current->next) {
        if (current->key == x) {
            pos = i;
            return pos;
        }
    }
    return pos;
}

