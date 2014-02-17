#pragma once
namespace Lists
{
struct ListElement
{

    int value;
    ListElement *next;
};

struct List
{
    ListElement *next;
};

List create()
{
    List *a = new List;
    a->next = NULL;
    return *a;
}
void add(List *a, int values)
{   std::cout<<123;
    while (a->next != NULL)
    {

        if (a->next->value < values)
        {

            ListElement *temp = new ListElement;
            temp->value = values;
            temp->next = a->next;
            a->next = temp;
        }
        a->next = a->next->next;
    }
    std::cout<<"OK";
}
int top(ListElement *a)
{
    return a->value;
}



}



