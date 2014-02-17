#include "PhoneBook.h"
#include <iostream>
#include <cstring>
#include <fstream>

using namespace PhoneBooks;
void write(char *value, std::ostream& out)
{
    for (int i = 0; i < strlen(value); i++)
        out << value[i];
    out << " ";
}

PhoneBook* PhoneBooks::create()
{

    PhoneBookElement *newElem = new PhoneBookElement {new char[100], new char[100], nullptr};

    return new PhoneBook{newElem, 0};

}

PhoneBookElement* PhoneBooks::getElement(int pos, PhoneBook* book)
{
    if(pos > book->size) {
        std::cout << "WRONG WRONG WRONG!!!!!!! EXTERMINATED";// здесь будет обработка ошибок.. когда-нибудь
        return nullptr;
    }

    int i = 0;
    PhoneBookElement* temp = book->head;
    while (i < pos)
    {
        temp = temp->next;
        i++;
    }
    return temp;
}
void read(char* arr, char *outArr) {
    for (int i = 0; i < strlen(arr); i++)
        outArr[i] = arr[i];
    outArr[strlen(arr)] = '\0';
}

void PhoneBooks::add(PhoneBook *book, PhoneBookElement* prev, char *name, char *number)
{
    char *a = new char[100];
    char *b = new char[100];

    read(name, a);
    read(number, b);
    PhoneBookElement* newElem = new PhoneBookElement{a, b, prev->next};

    prev->next = newElem;
    book->size += 1;
    //delete[] a;
    //delete[] b;
}

void PhoneBooks::sortAdd(PhoneBook *book, char *name, char *number) {

    PhoneBookElement *tempElement = getElement(0, book);//temp

    if(book->size == 0) {
        add(book, tempElement, name, number);
        return;
    }
    int a = strcmp(tempElement->next->name, name);
    if (strcmp(tempElement->next->name, name) > 0) //добавляем самый маленький
        add(book, tempElement, name, number);


    else {

        for (int i = 0; i < book->size; i++)
        {
            if ((strcmp(name, tempElement->name) >= 0) && (strcmp(name, tempElement->next->name) < 0))
                break;
            tempElement = tempElement->next;
        }

        add(book, tempElement, name, number);

    }
}

void PhoneBooks::printBook(PhoneBook *book, std::ostream& of){

    PhoneBookElement *t = getElement(1, book);
    if (book->size == 0)
        of <<"Book is empty!\n";

    for(int i = 1; i <= book->size; i++, t = t->next, of << std::endl){
        write(t->name, of);
        write(t->number, of);
    }


}

void PhoneBooks::deleteElement(PhoneBook *book, PhoneBookElement *prev)
{
        PhoneBookElement* newElem = prev->next;
        delete[] newElem->name;
        delete[] newElem->number;
        prev->next = newElem->next;
        delete newElem;
        book->size--;
}

void PhoneBooks::deletePhoneBook(PhoneBook* book)
{
       while (book->size != 0)
           deleteElement(book, getElement(0, book));
       delete book->head;
       delete book;
}



PhoneBookElement* PhoneBooks::findByName(PhoneBook *book, char *name){
    PhoneBookElement* tempElem = getElement(0, book);
    for (int i = 0; i <= book->size; i++, tempElem = tempElem->next)
        if(!strcmp(tempElem->name, name))
            return tempElem;

    return nullptr;
}
PhoneBookElement* PhoneBooks::findByNumber(PhoneBook *book, char *number){
    PhoneBookElement* tempElem = getElement(0, book);
    for (int i = 0; i <= book->size; i++, tempElem = tempElem->next )
        if(!strcmp(tempElem->number, number))
            return tempElem;

    return nullptr;
}



