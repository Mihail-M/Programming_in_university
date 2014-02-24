#include "complexnumber.h"
#include <iostream>

ComplexNumber::ComplexNumber()
{
}

ComplexNumber::ComplexNumber(double A, double B)
{
    a = A, b = B;
}

void ComplexNumber::print()
{
    std::cout << "(" <<a << ", "<< b <<")\n";
}


ComplexNumber ComplexNumber::ComplexNumber::operator +(ComplexNumber const &B)
{
    a += B.getRealPart(), b += B.getImaginaryPart();
    return (*this);
}

ComplexNumber ComplexNumber::operator -(ComplexNumber const &B)
{
    a -= B.getRealPart(), b -= B.getImaginaryPart();
    return (*this);

}

ComplexNumber ComplexNumber::operator *(ComplexNumber const &B)
{
    a *= B.getRealPart(), b *= B.getImaginaryPart();
    return (*this);
}

bool operator <=(ComplexNumber &A, ComplexNumber &B)
{
    double re1 = A.getRealPart();
    double im1 = A.getImaginaryPart();
    double re2 = B.getRealPart();
    double im2 = B.getImaginaryPart();


    return (re1 < re2 || (re1 == re2 && im1 <= im2));
}

bool operator <(ComplexNumber &A, ComplexNumber &B)
{
    double re1 = A.getRealPart();
    double im1 = A.getImaginaryPart();
    double re2 = B.getRealPart();
    double im2 = B.getImaginaryPart();

    return (re1 < re2 || re1 == re2 && im1 < im2);
}

bool operator ==(ComplexNumber &A, ComplexNumber &B)
{
    double re1 = A.getRealPart();
    double im1 = A.getImaginaryPart();
    double re2 = B.getRealPart();
    double im2 = B.getImaginaryPart();

    return (re1 == re2 && im1 == im2);
}
bool operator >(ComplexNumber &A, ComplexNumber &B)
{
    double re1 = A.getRealPart();
    double im1 = A.getImaginaryPart();
    double re2 = B.getRealPart();
    double im2 = B.getImaginaryPart();

    return (re1 > re2 || re1 == re2 && im1 > im2);
}
bool operator >=(ComplexNumber &A, ComplexNumber &B)
{
    double re1 = A.getRealPart();
    double im1 = A.getImaginaryPart();
    double re2 = B.getRealPart();
    double im2 = B.getImaginaryPart();

    return (re1 > re2 || re1 == re2 && im1 >= im2);
}

double ComplexNumber::getImaginaryPart() const
{
    return b;
}

void ComplexNumber::setImaginaryPart(double value)
{
    b = value;
}
double ComplexNumber::getRealPart() const
{
    return a;
}

void ComplexNumber::setRealPart(double value)
{
    a = value;
}





