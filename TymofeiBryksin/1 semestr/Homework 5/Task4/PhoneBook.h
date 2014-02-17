#include <string>
#include <fstream>
#include <iostream>
#pragma once

namespace PhoneBooks
{
    struct PhoneBookElement
    {
        char *name;
        char *number;
        PhoneBookElement* next;
    };

    struct PhoneBook
    {
        PhoneBookElement* head;
        int size;
    };

    PhoneBook* create();
    PhoneBookElement* getElement(int pos, PhoneBook *book);
    void add(PhoneBook* book, PhoneBookElement* prev, char *number, char *name);
    void deleteElement(PhoneBook *list, PhoneBookElement *prev);
    void deletePhoneBook(PhoneBook *book);
    void printBook(PhoneBook *book, std::ostream& of);

    void sortAdd(PhoneBook *book, char name[100], char *number);
    PhoneBookElement* findByName(PhoneBook *book, char *name);
    PhoneBookElement* findByNumber(PhoneBook *book, char *number);



}
