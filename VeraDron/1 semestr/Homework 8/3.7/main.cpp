#include <iostream>
#include <cmath>
using namespace std;

typedef double (*Function)(double);

double tg(double x)
{
    return(sin(x)/cos(x));
}

Function chooseF(char c)
{
    switch(c){
            case 's': return sin; break;
    case 'c': return cos; break;
    case 'e': return exp; break;
    case 't': return tan; break;
    case 'l': return log; break;
    }
}

int main()
{
    int n;
    char s;
    double x = 0, z = 0;
    int i = 0;
    cin >> s;
    while ((s >= '0') && (s <= '9'))
    {
        x *= 10;
        x += s - '0';
        cin >> s;
    }
    if (s == '.')
    {
        cin >> s;
        i++;
        while ((s >= '0') && (s <= '9'))
        {
            z += (s - '0') / pow(10, i);
            i++;
            cin >> s;
        }
    }
    x += z;
    while (s!='#')
    {
        x = chooseF(s)(x);
        cin >> s;
    }
    cout << x;
    return 0;
}
