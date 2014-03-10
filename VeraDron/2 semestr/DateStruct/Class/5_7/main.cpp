#include <iostream>
#include <cstdlib>

using namespace std;
int atoi(string digit, int base){
    int factor = 1, ans = 0, n = digit.size();
    for(int i = n-1; i >= 0; i--) {
        ans += ((isdigit(digit[i])? (digit[i]-'0'): (digit[i] - 'A')+10))*factor;
        factor *= base;
    }
    return ans;

}

class Int{
public:
    Int();
    Int(int _num);
    Int(string digit);
    Int(string digit, int base);
    int getNum() const;
    Int operator--(int notused);
    Int operator--();

private:
    int num;
    friend Int operator -(Int &a, Int &b);
};

Int::Int(): num(0)
{

}

Int::Int(int _num): num(_num)
{

}

Int::Int(string digit): num(atoi(digit.c_str()))
{

}

Int::Int(string digit, int base):num(atoi(digit, base))
{

}
int Int::getNum() const
{
    return num;
}

Int Int::operator--(int notused) {
    Int t(*this);
    --(*this);
    return t;
}

Int Int::operator--()
{
    num--;
    return (*this);
}

Int operator -(Int &a, Int &b)
{
    Int c(a);
    c.num -= b.num;
    return c;
}


class Double{

public:
    double getNum() const;
    Double();
    Double(double _num);
    Double operator %(int a);

private:
    double num;
};

int main()
{
    Int a;
    Int b(2);
    Int c("2");
    Int d("A", 16);
    d--;
    cout << d.getNum() << endl;
    Double D(-12.3);
    cout << (D%5).getNum();
    return 0;
}

double Double::getNum() const
{
    return num;
}

Double::Double(): num(0)
{

}

Double::Double(double _num): num(_num)
{

}

Double Double::operator %(int a)
{
    int factor = num / a;
    return num - (a*factor);
}

