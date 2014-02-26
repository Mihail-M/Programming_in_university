#include <iostream>
#include "circulyrlist.h"
#include "acicliclist.h"

using namespace std;

int main()
{
    cout << "Present: \n";
    CirculyrList *l = new CirculyrList();
    AciclicList *l1 = new AciclicList();

    for(int i = 0 ;i < 10;i++){
        l->pushBack(i);
    }
    for(int i = 0 ;i < 10;i++)
        l->pushFront(i);

    l->popBack();
    l->popFront();
    l->show();

    l->erase(15);
    l->show();
    l->show();

    for(int i = 0 ;i < 10;i++)
        l1->pushBack(i);

    for(int i = 0 ;i < 10;i++)
        l1->pushFront(i);

    l1->show();

    cout << "\nSize of aciclic list:\n";

    cout << l1->size() << endl;


    l1->show();

    delete l;
    delete l1;
    return 0;
}

