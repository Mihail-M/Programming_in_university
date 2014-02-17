#include "List.h"
#include <iostream>

using namespace Lists;

List* Lists::create()
{
    ListElement *newElem = new ListElement;
    newElem->next = nullptr;
    return new List {newElem, 0};

}

ListElement* Lists::getElement(int pos, List* list)
{
    if(pos > list->size) {
        std::cout << "WRONG WRONG WRONG!!!!!!! EXTERMINATED";// здесь будет обработка ошибок.. когда-нибудь
        return nullptr;
    }

    int i = 0;
    ListElement* temp = list->head;
    while (i < pos)
    {
        temp = temp->next;
        i++;
    }
    return temp;
}

void Lists::add(List *list, ListElement* prev, int value)
{
    ListElement* newElem = new ListElement {value, prev->next};
    prev->next = newElem;
    list->size += 1;
}

void Lists::printList(List *list){
    ListElement *t = getElement(1, list);
    if (list->size == 0)
        std::cout <<"List is empty\n";

    for(int i = 1; i <= list->size; i++, t = t->next){
        std::cout << t->value << " ";
    }

    std::cout << std::endl;

}

void Lists::deleteElement(List *list, ListElement *prev)
    {
        ListElement* newElem = prev->next;
        prev->next = newElem->next;
        delete newElem;
        list->size--;
    }
void Lists::deleteList(List* list)
{
       while (list->size != 0)
           deleteElement(list, getElement(0, list));
       delete list->head;
        delete list;
}

void Lists::sortAdd(List *list, int value) {

    if (getElement(0, list) == nullptr) {
        printf("Error'n!");
        return;
    }
    ListElement *tempElement = getElement(0, list);//temp

    if(list->size == 0) {
        add(list, tempElement, value);
        return;
    }

    if (value < tempElement->next->value ) //добавляем самый маленький
        add(list, tempElement, value);


    else {

        for (int i = 0; i < list->size; i++)
        {
            if ((tempElement->value <= value) && (tempElement->next->value > value))
                break;
            tempElement = tempElement->next;
        }

        add(list, tempElement, value);

    }
}

void Lists::deleteKey(List *list, int key) {
    
    if (getElement(0, list) == nullptr) {
        printf("Error'n!");
        return;
    }
    
    ListElement *tempElement = getElement(0, list);//temp

    for(int i = 0; i < list->size; i++)
    {
        if (tempElement->next->value == key){
            deleteElement(list, tempElement);
            break;
        }
        else
        {
            tempElement = tempElement->next;
        }
    }
   
}
