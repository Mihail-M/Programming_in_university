#include iostream

using namespace std;
const int successState = 5;
int main()
{
    int n;
    cin  n;
    char c;

    int currentState = 0;
    while (cin  c)
    {
        if (currentState == 0)
        {
            if (c == 'a')
                currentState = 1;
            continue;

        }
        else if (currentState == 1)
        {
            if (c == 'b')
                currentState = 2;
            else if (c == 'a')
                currentState = 1;
            else currentState = 0;
            continue;
        }
        else if (currentState == 2)
        {
            if (c == 'a')
                currentState = 3;
            else currentState = 0;
            continue;

        }
        else if (currentState == 3)
        {
            if (c == 'b')
                currentState = 4;
            else if (c == 'a')
                currentState = 1;
            else currentState = 0;
            continue;

        }
        else if (currentState == 4)
        {
            if (c == 'c')
            {
                currentState = 5;
                break;
            }
            else if (c == 'a')
                currentState = 3;
            else currentState = 0;
            continue;

        }
    }
    if (currentState == successState)
        cout  Yes;
    else
        cout  No;
    return 0;
}
