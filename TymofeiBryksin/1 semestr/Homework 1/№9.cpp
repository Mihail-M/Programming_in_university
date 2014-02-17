#include <cstdio>

unsigned long long powPositive(int number, int power)
{
    unsigned long long answer = 1;

    for (int i = 0 ; i < power; i++)
        answer *= number;

    return answer;
}
double powNegative(int number, int power)
{
    double answer = 1;

    for (int i = 0 ; i > power; i--)
        answer /= number;

    return answer;
}

int main()
{
    int number = 0;
    int power = 0;
    printf("This program calculates the power of number!\nPlease enter the number and power:");
    scanf("%i%i", &number, &power);

    if (power >= 0)
        printf("Answer: %lld", powPositive(number, power));
    else
        printf("Answer: %f", powNegative(number, power));

    return 0;
}
