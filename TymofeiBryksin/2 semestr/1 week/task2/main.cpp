#include <iostream>
#include <stack.h>

using namespace std;

int main()
{
    Stack *a = new Stack();
    a->push(2);
    a->push(3);
    a->push(2);
    a->push(2);
    a->push(2);
    cout << a->top();


    cout << a->Size();
    return 0;
}

