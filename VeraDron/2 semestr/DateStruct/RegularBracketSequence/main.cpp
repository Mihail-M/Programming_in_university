#include <iostream>
#include "stack.h"
using namespace std;


int main(){
    char s;
    Stack *st = new Stack();
    while(cin >> s) {

        if(s == '(' || s == '{' || s == '[')
            st->push(s);
        else
        {
            if (st->isEmpty())
            {
                cout << "no";
                return 0;
            }
            else if ((s == ')') && (st->top() == '('))
                st->pop();
            else if ((s == ']') && (st->top() == '['))
                st->pop();
            else if ((s == '}') && (st->top() == '{'))
                st->pop();

            else {
                cout << "no";
                return 0;
            }
        }
    }
    if(st->isEmpty())
        cout << "yes";
    else
        cout << "no";
    delete st;

    return 0;
}

