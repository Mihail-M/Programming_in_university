#include "polynomial.h"
#include <iostream>
Polynomial::Polynomial()
{
    for(int i = 0; i <= MAX; i++){
        factor[i] = 0;
    }
}

void Polynomial::set_coef(int n, int k)
{
    factor[n] = k;
}

long long Polynomial::value(long long x)
{
    long long _x = x;
    int ans = factor[0] * 1;
    for(int i = 1; i <= MAX; i++) {
        ans += x*factor[i];
        x*=_x;
    }
    return ans;
}

void Polynomial::print()
{
    for(int i = MAX; i >= 1; i--){
        if(factor[i])
            std::cout << factor[i] << "*x^" <<i << " + ";
    }
    if(factor[0])
        std::cout << factor[0];
    std::cout << std::endl;
}

Polynomial Polynomial::operator +(const Polynomial &B)
{
    Polynomial C;
    for(int i = 0; i <= MAX; i++)
        C.factor[i] = factor[i] + B.factor[i];
    return C;

}

Polynomial Polynomial::operator -(const Polynomial &B)
{
    Polynomial C;
    for(int i = 0; i <= MAX; i++)
        C.factor[i] = factor[i] + B.factor[i];
    return C;

}

Polynomial Polynomial::operator *(const Polynomial &B)
{
    Polynomial C;
    for(int i = 0; i <= MAX; i++){
        for(int j = 0; j <= MAX; j++){
            if(B.factor[j] && i+j <= MAX)
                C.factor[i+j] += factor[i]*B.factor[j];
        }
    }
    return C;
}
