#pragma once

class ComplexNumber
{
public:
    ComplexNumber();
    ComplexNumber(double A, double B);

    void print();


    ComplexNumber operator +(ComplexNumber const &B);
    ComplexNumber operator -(ComplexNumber const &B);
    ComplexNumber operator *(ComplexNumber const &B);
    ComplexNumber operator ~();

    double getImaginaryPart() const;
    void setImaginaryPart(double value);

    double getRealPart() const;
    void setRealPart(double value);

private:
    double re; // действительная часть
    double im; // мнимая часть

    friend bool operator <(ComplexNumber &A, ComplexNumber &B);
    friend bool operator <= (ComplexNumber &A, ComplexNumber &B);
    friend bool operator == (ComplexNumber &A, ComplexNumber &B);
    friend bool operator >= (ComplexNumber &A, ComplexNumber &B);
    friend bool operator > (ComplexNumber &A, ComplexNumber &B);


};

