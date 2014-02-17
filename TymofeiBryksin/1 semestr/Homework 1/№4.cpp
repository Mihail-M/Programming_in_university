#include <iostream>

using namespace std;

int sumDigit(int n) {

    int sum = 0;

    while (n) {
       sum += n % 10;
       n /= 10;
    }

    return sum;
}

int main()
{
    int count = 0;

    for(int i = 0; i <= 999; i++)
        for(int j = 0; j <= 999; j++)
            if(sumDigit(i) == sumDigit(j))
                count++;

    cout << "answer: " << count;
    return 0;
}
