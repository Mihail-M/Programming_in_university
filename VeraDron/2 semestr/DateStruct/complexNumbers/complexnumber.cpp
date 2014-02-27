#include "complexnumber.h"
#include <iostream>

ComplexNumber::ComplexNumber()
{
}

ComplexNumber::ComplexNumber(double A, double B)
{
    re = A, im = B;
}

void ComplexNumber::print()
{
    std::cout << "(" <<re << ", "<< im <<")\n";
}


ComplexNumber ComplexNumber::ComplexNumber::operator +(ComplexNumber const &B)
{
    re += B.re, im += B.im;
    return (*this);
}

ComplexNumber ComplexNumber::operator -(ComplexNumber const &B)
{
    re -= B.re, im -= B.im;
    return (*this);

}

ComplexNumber ComplexNumber::operator *(ComplexNumber const &B)
{
    re = re * B.re - im * B.im, im = re * B.re + im * B.re;
    return (*this);
}

bool operator <=(ComplexNumber &A, ComplexNumber &B)
{
    return (A.re < B.re || A.re == B.re && A.im <= B.im);
}

bool operator <(ComplexNumber &A, ComplexNumber &B)
{
    return (A.re < B.re || A.re == B.re && A.im < B.im);
}

bool operator ==(ComplexNumber &A, ComplexNumber &B)
{
    return (A.re == B.re || A.im == B.im);
}

bool operator >(ComplexNumber &A, ComplexNumber &B)
{   
    return (A.re > B.re || A.re == B.re && A.im > B.im);
}

bool operator >=(ComplexNumber &A, ComplexNumber &B)
{
    return (A.re > B.re || A.re == B.re && A.im >= B.im);
}

double ComplexNumber::getImaginaryPart() const
{
    return im;
}

void ComplexNumber::setImaginaryPart(double value)
{
    im = value;
}
double ComplexNumber::getRealPart() const
{
    return re;
}

void ComplexNumber::setRealPart(double value)
{
    re = value;
}





