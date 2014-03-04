#pragma once
const int MAX = 10;

class Polynomial
{
public:
    Polynomial();
    void set_coef(int n, int k);
    long long value(long long x);
    void print();

    Polynomial operator +(Polynomial const &B);
    Polynomial operator -(Polynomial const &B);
    Polynomial operator *(Polynomial const &B);

private:
    int factor[MAX + 1];
};

