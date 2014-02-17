#include <iostream>

using namespace std;

const int countSymbols = 256;
void read(int length, int (&symbols)[countSymbols])
{
    for (int i = 0; i < length; i++)
    {
        char temp = '0';
        cin >> temp;
        symbols[temp]++;
    }
}
int main()
{

    int length = 0;

    cout << "input length first and second string: \n";
    cin >> length;

    int symbols[countSymbols];
    int symbols2[countSymbols];

    for (int i = 0; i < countSymbols; i++)
        symbols[i] = symbols2[i] = 0;

    cout << "input first string: \n";
    read(length, symbols);

    cout << "input second string: \n";
    read(length, symbols);

    for (int i = 0; i < countSymbols; i++)
        if (symbols[i] != symbols2[i])
        {
            cout << "NO";
            return 0;
        }

    cout << "YES";
    return 0;
}
