#include <iostream>
#include "circulyrList.h"
#include "uncirculyrList.h"

using namespace std;

int main()
{
    cout << "Present: \n";
    circulyrList *l = new circulyrList();
    uncirculyrList *l1 = new uncirculyrList();

    for(int i = 0 ;i < 10;i++){
        l->push_back(i);
    }

    for(int i = 0 ;i < 10;i++)
        l->push_front(i);

    l->pop_back();
    l->pop_front();
    l->show();

    l->erase(15);
    l->show();

    for(int i = 0 ;i < 10;i++)
        l1->push_back(i);

    for(int i = 0 ;i < 10;i++)
        l1->push_front(i);
    l1->show();

    cout << "\nSize of uncirculyr list:\n";

    cout << l1->Size() << endl;


    l1->show();

    delete l;
    delete l1;
    return 0;
}

