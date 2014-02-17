#include <iostream>
#include "limits.h"
#include "List.h"
#include <string>

using namespace std;
using namespace Lists;

enum Change { exitOut, addElem, deleteElem, print };

Change intToChange(int one)
{
    return static_cast<Change>(one);
}

void hello(){
    cout << "If you want add value in MY list input 1:\n";
    cout << "If you want delete value in MY list input 2:\n";
    cout << "If you want see MY list input 3:\n";
    cout << "else input 0:\n";
    cout << "YOUR CHANGE IS? input digit: ";
}

int main()
{
    List *list = create();

    while (true) {

        hello();
        int changeTemp = 0;
        Change c;
        cin >> changeTemp;
        c = intToChange(changeTemp);

        if (c == exitOut)
        {
            cout << "BY";
            deleteList(list);
            return 0;
        }

        if (c == addElem)
        {
            cout << "Input value: ";
            int value = 0;
            cin >> value;
            sortAdd(list, value);
            cout << endl;
        }

        if (c == deleteElem)
        {
            cout << "Input value: ";
            int key = 0;
            cin >> key;
            deleteKey(list, key);
            cout << endl;
        }

        if (c == print)
        {
            cout << "LIST: ";
            printList(list);
        }
        cout << endl;
    }

    deleteList(list);
    return 0;
}