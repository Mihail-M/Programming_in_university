#include "myset.h"

#include <iostream>
using namespace std;
int main()
{
    MySet<int> set;
    set.add(1);
    set.add(2);
    MySet<int> set2;
    set2.add(2);
    set2.add(3);
    cout << MySet<int>::intersection(set1,set2)->exist(2);

    H.add(2);
    H.add(3);
    H.remove(3);
    H.remove(3);
    H.remove(2);
    cout << H.size();
    H.add(2);
    cout << H.size();
}
