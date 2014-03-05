#include <iostream>

#include "consolewriter.h"
#include "filewriter.h"

using namespace std;


int main()
{
    int n;
    cout << "Input n(odd):";
    cin >> n;

    cout << "Input n*n array: \n";
    int **array = new int*[n];

    for(int i = 0; i < n; i++)
        array[i] = new int[n];

    for(int i = 0; i < n; i++)
        for(int j = 0 ;j < n; j++)
            cin >> array[i][j];

    enum choice { console = 1, file = 2 };
    cout << "If you want write on the console input 1 and 2 if you want write this in file:";
    int t;
    cin >> t;
    choice userChoice = static_cast<choice>(t);

    switch (userChoice) {
    case console:
    {
        ConsoleWriter writer;
        writer.print(n, array);

        break;
    }
    case file:
    {
        FileWriter writer;
        writer.print(n, array);
        break;
    }
    }

    cout <<"\nThanks for use!";
    for(int i = 0; i < n; i++)
        delete[] array[i];
    delete[] array;

}

