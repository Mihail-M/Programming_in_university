#include <iostream>

using namespace std;

int main()
{
    int temp = 10;
    int *digit = new int[10];

    for (int i = 0; i < 10 ; i++)
        digit[i] = 0;

    int n = 0;
    cout << "input any number: ";
    cin >> n;
    
    while (n)
    {
        if (n % 10)
            temp = min(temp, n % 10);
            
        digit[n % 10]++;
        n /= 10;
    }

    cout << "min: ";

    if (temp < 10) {
        cout << temp;
        digit[temp]--;
    }

    for(int i = 0 ; i < 10; i++)
        for(int j = 0; j < digit[i]; j++)
            cout << i;
            
    delete[] digit;
    
    return 0;
}
