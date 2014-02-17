#include <cstdio>

int partialQuotient(int number, int divisor)
{

    int answer = 0;

    while (number >= divisor)
    {
        number -= divisor;
        answer++;
    }

    return answer;
}

int main()
{
    int number=0;
    int divisor=0;
    printf("Please, enter number: ");
    scanf("%i", &number);
    printf("Please, enter divisor: ");
    scanf("%i", &divisor);
    printf("Partial quotient: %i", partialQuotient(number, divisor));

    return 0;
}
