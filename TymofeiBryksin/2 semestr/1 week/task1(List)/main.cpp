#include <iostream>
#include <list.h>

using namespace std;

int main()
{

    List *l = new List();
    for(int i = 0 ;i < 10;i++)
        l->push_back(i);

   for(int i = 0 ;i < 10;i++)
        l->push_front(i);

    l->show();
    return 0;
}

