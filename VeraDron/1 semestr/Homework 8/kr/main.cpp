#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;
const int w =70;
const int h = 30;
double fact(int x)
{
    double ans= 1;
    for(int i = 1; i<=x; i++)
        ans*=i;
    return ans;
}
double F1(double x)
{
    return 30*cos(x/4);
}
double F2(double x)
{
    if (abs(x)<10e-8)return 50*1/2;
    return (50*sin(x/2)/x);
}
double F3(double x)
{
    x = x / 4;
    double sum = 0;
    for(int i = 0; i <= 15; i++)
        sum += (pow(-1, i)*pow(x, 2*i+1))/fact(2*i+1);
    return 30*sum;

}
void plot(double (*F)(double),double eps)
{
    for(int y = -5; y <= h+5; y++,cout << endl)
        for(int x = -3; x < w; x++)
            if(fabs(F(x- w/2) - (y-h/2)) <= eps)
                cout <<  '*';
            else cout << ' ';
}
int main()
{
// plot(&F1, 10);
    plot(&F2, 1);
    plot(&F3, 5);

    return 0;
}
