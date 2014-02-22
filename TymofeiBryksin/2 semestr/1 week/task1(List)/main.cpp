#include <iostream>
#include <circulyrList.h>
#include <uncirculyrlist.h>

using namespace std;

int main()
{
    cout << "Present: \n";
    circulyrList *l = new circulyrList();
    uncyrcularList *l1 = new uncyrcularList();

    for(int i = 0 ;i < 10;i++){
        l->push_back(i);
    }

    for(int i = 0 ;i < 10;i++)
        l->push_front(i);

    l->pop_back();
    l->pop_front();
    l->insert(l->Last(), 3);
    l->erase(l->Last());

    l->show();

    for(int i = 0 ;i < 10;i++)
        l1->push_back(i);


    for(int i = 0 ;i < 10;i++)
        l1->push_front(i);
    l1->show();

    cout << "\nSize of uncirculyr list:\n";

    cout << l1->getSize() << endl;

    l1->erase(l1->Head());
    l1->show();

    delete l;
    delete l1;
    return 0;
}

