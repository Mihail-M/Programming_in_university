#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
    int n=0;
    int m=0;

    printf("Enter the size of string:");
    scanf("%i", &n);
    printf("Enter the size of substring:");
    scanf("%i", &m);

    char string[n];
    char substring[m];

    printf("Enter the string:");
    scanf("%s", &string);
    printf("Enter the substring:");
    scanf("%s", &substring);

    int lengtString = strlen(string);
    int lengthSubstring = strlen(substring);

    int count = 0;

    for (int i = 0; i < lengtString - lengthSubstring + 1; i++)
    {
        bool toVerify = false;
        for (int j = 0; j < lengthSubstring; j++)
            if (string[i + j] != substring[j])
                toVerify = true;

        if (!toVerify)
            count++;
    }

    printf("Answer is: %i", count);
    return 0;
}
