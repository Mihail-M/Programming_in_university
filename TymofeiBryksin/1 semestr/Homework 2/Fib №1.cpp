#include <iostream>

using namespace std;

long long fib(int n){
    int f1 = 1;
    int f2 = 1;
    int f3 = 0;
    for (int i = 2; i < n; i++) {
        f3 = f1 + f2;
        f1 = f2;
        f2 = f3;
    }
    return f2;
}

long long fibRec(int n){
    return (n == 0 || n == 1? n : fibRec(n - 1) + fibRec(n - 2));
}
int main()
{
    int n = 0;
    cout << "This program calcululete n's element of Fibbonachi:\n Please input n: ";
    cin >> n ;

    cout << "Answer: " << fib(n) << " " << fibRec(n);

    return 0;
}
