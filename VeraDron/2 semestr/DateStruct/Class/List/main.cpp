#include <iostream>
#include "acicliclist.h"

using namespace std;

int main()
{
    List *a = new AciclicList ;
    int t = -1;

    while (t != 0) {
        cin >> t;
        if (t == 0) break;
        a->pushBack(t);
    }

    long long ans = 0;

    while(!a->isEmpty()){
        ans += a->front()*a->back();
        a->popFront();
        a->popBack();
    }

    cout << ans << endl;
    delete a;

}

