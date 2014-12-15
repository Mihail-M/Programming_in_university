/*xy?z*(h|g)*/
#include <iostream>

using namespace std;

const int successState = 4;
int main()
{
    char c;

    int currentState = 0;
    while (cin >> c)
    {
        if (currentState == 0)
        {
            if (c == 'x')
                currentState = 1;
            continue;

        }
        else if (currentState == 1)
        {
            if (c == 'y')
                currentState = 2;
            else if (c == 'z')
                currentState = 3;
            else if (c == 'h' || c == 'g')
                currentState = 4;
            continue;
        }
        else if (currentState == 2)
        {
            if (c == 'z')
                currentState = 3;
            else if (c == 'h' || c == 'g')
                currentState = 4;
            else currentState = 0;
            continue;

        }
        else if (currentState == 3)
        {
            if (c == 'z')
                currentState = 3;
            else if (c == 'h' || c == 'g')
                currentState = 4;
            else currentState = 0;
            continue;

        }
        else if (currentState == 4)
        {
            continue;
        }
    }

    if (currentState == successState)
        cout << "Yes";
    else
        cout << "No";
    return 0;
}
