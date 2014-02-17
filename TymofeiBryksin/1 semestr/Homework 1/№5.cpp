#include <cstdio>
#include <cstring>
#include <iostream>
const int n = 10000;

struct stack
{
    char a[n];
    int sz = 0;

    void push(int n)
    {
        a[sz++] = n;
    }

    char back()
    {
        return a[sz - 1];
    }

    char pop()
    {
        return a[--sz];
    }

    int size()
    {
        return sz;
    }

    void clear()
    {
        sz = 0;
    }

    bool empty()
    {
        return !sz;
    }
};

bool isOpen(char c)
{
    return c=='(';
}

int main()
{
    char c;
    int lim = 0;
    stack st;

    printf("Enter N:");
    scanf("%i", &lim);
    printf("Enter the sequence consisting of ( and ) the length of N:");
    scanf("%c", &c);
    for(int i = 0; i < lim; i++)
    {
        scanf("%c", &c);

        if (isOpen(c))
            st.push(c);
        else
        {
            if(!st.empty())
                st.pop();
            else
            {
                printf("NO1");
                return 0;
            }
        }
    }

    if (st.size() == 0)
        printf("YES");
    else
        printf("NO");

    return 0;
}
