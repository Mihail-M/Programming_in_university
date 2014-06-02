#include <iostream>
#include <acicliclist.h>

using namespace std;

int main()
{

    AciclicList list;
    for (int i = 0; i < 6; i++)
    {
        list.pushFront(rand() % 42);
        list.pushBack(rand() % 42);
    }

    for (List::iterator it = list.begin(); it != list.end(); ++it)
        cout << *it << " ";
    cout << endl;
    list.show();

    for (int i = 0; i < 3; i++)
    {
        list.popBack();
        list.popFront();
    }

    cout << list.size() << endl;
    List::iterator it;
    for (it = --(list.end()); it != list.begin()->prev; --it)
        cout << *it << " ";
    cout << endl;
    int max = *(list.begin());
    for (List::iterator it = list.begin(); it != list.end(); ++it)
            max = std::max(*it, max);

    cout << max << endl;

    list.show();
    cout << endl;

    for (List::iterator it = list.begin(); it != list.end(); ++it)
        if (*it % 2 == 0)
            list.insert(it, *it - 1);

    list.show();
    cout << endl;

    for (List::iterator it = list.begin(); it != list.end(); ++it)
        if (*it % 3 == 0)
        {
            it = list.erase(it);
            --it;
        }

    list.show();


    return 0;
}

