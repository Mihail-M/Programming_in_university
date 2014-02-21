#include <iostream>
#include <list.h>

using namespace std;

int main()
{
    cout << "Present: \n";
    List *l = new List();

    for(int i = 0 ;i < 10;i++)
        l->push_back(i);

   for(int i = 0 ;i < 10;i++)
        l->push_front(i);

    l->pop_back();
    l->pop_front();
    l->insert(l->getNListElem(3), 3, 23);
    l->show();

    return 0;
}

