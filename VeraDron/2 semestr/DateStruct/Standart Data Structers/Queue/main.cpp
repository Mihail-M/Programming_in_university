#include <iostream>
#include "queue.h"
using namespace std;

int main()
{
    Queue a;
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        a.push(i);
    while(a.size() > 1) {

        for(int i = 0; i < m-1; i++)
            a.push(a.pop());
        cout << a.front() << " ";
        a.pop();
    }
    cout << a.front();
    a.clear();

    return 0;
}

