#include <iostream>
#include <fstream>
#include "PhoneBook.h"

using namespace std;
using namespace PhoneBooks;
//ifstream in("PhoneBook.txt");


enum Change{ exitOut, addRecord, findName, findNumber, print, save };

Change intToChange(int one)
{
    return static_cast<Change>(one);
}
void savePhoneBook(PhoneBook *book){
    ofstream of("PhoneBook.txt");
    of << book->size << endl;
    printBook(book, of);
}

PhoneBook* initializer(){
    ifstream in("PhoneBook.txt");
    int count = 0;
    in >> count;
    if (count == 0)
        return create();
    else
    {
        PhoneBook* book = create();

        for (int i = 0; i < count; i++){
            char number[100];
            char name[100];

            in >> number;
            in >> name;

            sortAdd(book , number, name);
        }

        return book;
    }
}

void hello(){
    cout << "\n\nIf you want add record in MY Phone Book input 1:\n";
    cout << "If you want find record by name in MY Phone Book input 2:\n";
    cout << "If you want find record by number in MY Phone Book input 3:\n";
    cout << "If you want see your Phone Book input 4:\n";

    cout << "If you want save your Phone Book input 5:\n";

    cout << "else input 0:\n";
    cout << "YOUR CHANGE IS? input digit: ";

}
int main()
{
    PhoneBook *book = initializer();

    while (true) {
        hello();

        int one = 0;
        cin >> one;

        Change c = intToChange(one);

        if (c == exitOut)
        {
            cout << "BY";
            deletePhoneBook(book);
            return 0;
        }

        if (c == addRecord)
        {
            char *name = new char[100];
            cout << "input name: ";

            cin >> name;

            char *number = new char[100];

            cout << "input number: ";
            cin >> number;

            sortAdd(book , name, number);
           // delete[] name;
            //delete[] number;
        }

        if (c == findName)
        {
            char *name = new char[100];
            cout << "input name: ";
            cin >> name;
            PhoneBookElement *tempElem = findByName(book, name);
            if( tempElem == nullptr)
                cout << "Not Found!";
            else
                cout << tempElem->name << " " << tempElem->number<<endl;
            delete[] name;
        }

        if (c == findNumber)
        {
            char *number = new char[100];
            cout << "input number: ";
            cin >> number;
            PhoneBookElement *tempElem = findByNumber(book, number);
            if( tempElem == nullptr)
                cout << "Not Found!";
            else
                cout << tempElem->name << " " << tempElem->number<<endl;
        }
        if (c == save)
        {
            savePhoneBook(book);
        }
        if (c == print)
        {
            printBook(book, cout);
        }
    }

    return 0;
}

