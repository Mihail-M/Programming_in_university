#include <cstdio>
#include <cstring>

int main()
{
    int n = 0;
    printf("Enter size of string: ");
    scanf("%i", &n);
    char str[n]; 

    printf("Enter string: ");
    scanf("%s", &str);

    for (int i = 0; i < n/2; i++)
        if (str[n - i - 1] != str[i])
        {
            printf("No. It is not palindrome");
            return 0;
        }

    printf("YES. It is palindrome");
    return 0;
}
