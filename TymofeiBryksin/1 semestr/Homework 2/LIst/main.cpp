#include <cstdio>
int foo(int n)
{
    int k, m;
    for (k=0, m=1; m <= n; k++, m = m * 2);
    return k-1;
}
int main ()
{
//--------------------------------------------------------34
    int t, n=3;
    scanf("%i", &n);
    t = foo(n);
    printf("%d", t);
    getchar() ;פיצ2‗Ôי  פצÿקפûצף345םדכב‏ד8

}
