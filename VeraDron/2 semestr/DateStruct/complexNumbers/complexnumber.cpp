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
    result.re += B.re, result.im += B.im;
    return result;
}

ComplexNumber ComplexNumber::operator -(ComplexNumber const &B)
{
    ComplexNumber result;
    result.re -= B.re, result.im -= B.im;
    return result;

}

ComplexNumber ComplexNumber::operator *(ComplexNumber const &B)
{
    ComplexNumber result;
    result.re = re * B.re - im * B.im, result.im = re * B.re + im * B.re;
    return result;
}

ComplexNumber ComplexNumber::operator ~()
{
    im = -im;
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





