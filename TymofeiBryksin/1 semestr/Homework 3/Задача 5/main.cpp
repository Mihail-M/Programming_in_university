#include <iostream>
#include "CycleList.h""

using namespace std;
using namespace Lists;

ListElement *kill(List *list, ListElement *soldier, int m)
{
    for (int i = 0; i < m-1; ++i) 
    {
        soldier = soldier->next;
    }
    
    deleteElement(list, soldier);
    return soldier;
}

int main()
{
    List *list = create();
    int n, m;
    cout <<" Task about Josephus \nInput n and m: ";
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
        add(list, getElement(list->size-1, list), i);

    initCycle(list);

    ListElement *q = getElement(list->size - 1, list);

    q = getElement(list->size - 1, list);

    while (list->size > 1)
        q = kill(list, q, m);



    cout <<"Answer is: ";

    printList(list);
    deleteList(list);
    
    return 0;

}

