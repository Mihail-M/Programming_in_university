#pragma once

namespace Lists
{
    struct ListElement
    {
        int value;
        ListElement* next;
    };

    struct List
    {
        ListElement* head;
        int size;
    };

    List* create();
    ListElement* getElement(int pos, List *list);
    void add(List* list, ListElement* prev, int value);
    void deleteElement(List *list, ListElement *prev);
    void deleteList(List *list);
    void printList(List *list);
    void sortAdd(List *list, int value);
    void deleteKey(List *list, int key);
}
