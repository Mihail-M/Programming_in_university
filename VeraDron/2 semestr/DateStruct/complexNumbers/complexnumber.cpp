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
    ComplexNumber result;
    result.re = re + B.re, result.im = im + B.im;
    return result;
}

ComplexNumber ComplexNumber::operator -(ComplexNumber const &B)
{
    ComplexNumber result;
    result.re = re - B.re, result.im = im - B.im;
    return result;

}

ComplexNumber ComplexNumber::operator *(ComplexNumber const &B)
{
    ComplexNumber result;
    result.re = re * B.re - im * B.im, result.im = re * B.im + im * B.re;
    return result;
}

ComplexNumber ComplexNumber::operator ~()
{
    ComplexNumber c;
    c.re = re, c.im = -im;

    return c;
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





