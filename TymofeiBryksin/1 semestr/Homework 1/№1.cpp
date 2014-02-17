#include <cstdio>

int main()
{
    int x = 0;

    printf ("Enter any number:");
    scanf("%x", &x);

    int temp = x * x;

    printf("\nAnswer is: %i", (temp + x) * (temp + 1));

    return 0;
}
