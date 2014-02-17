#include <cstdio>

int main()
{
    int n=0;

    printf("Enter the limit:");
    scanf("%i", &n);

    bool prime[n + 1];
    prime[0] = prime[1] = true;

    for (int i = 2; i <= n; i++)
        if (!prime[i])
            if (i * i <= n)
                for (int j = i * i; j <= n; j += i)
                    prime[j] = true;

    for (int i = 2; i <= n; i++)
        if (!prime[i])
            printf("%i ", i);

    return 0;
}
