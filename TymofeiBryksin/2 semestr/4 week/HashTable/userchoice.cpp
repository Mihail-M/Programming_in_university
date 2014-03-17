#include "userchoice.h"
#include <iostream>

using namespace std;

void UserChoice::choice(HashTable *table)
{
    cout << "You can: " << endl << "0 - exit";
    cout << endl << "1 - add value";
    cout << endl << "2 - remove value";
    cout << endl << "3 - check element exist or not";
    cout << endl << "4 - show HashTable";
    cout << endl << "5 - show statistics";
    cout << endl;
    cout << "You need choose one of two hash finction for use:" << endl;
    cout << "    1: Primitive hash function(s.size()%arraysize)" << endl;
    cout << "    2: Power hash function!" << endl;

    int choiceHashFunc = 2;
    cin >> choiceHashFunc;
    table->setHashFunction(getHashFunction(choiceHashFunc));
    cout << endl;
    int command = -1;
    while(command != 0)
    {
        string str;
        switch(command)
        {
        case 1:
        {
            cout << "Enter string for add: ";
            cin >> str;
            table->add(str);
            break;
        }
        case 2:
        {
            cout << "Enter string for remove: ";
            cin >> str;
            table->erase(str);
            break;
        }
        case 3:
        {
            cout << "Enter string for check: ";
            cin >> str;
            if (table->find(str))
                cout << "Found.";
            else
                cout << "not found.";
            cout << endl;
            break;
        }
        case 4:
        {
            table->show();
            break;
        }
        case 5:
        {
            table->showStatistic();
            break;
        }
        default:
        {
            command = 0;
            break;
        }
        }

        cout << endl << "Enter command: ";
        cin >> command;
    }
}
