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

    bool operator <(ComplexNumber &B);
    bool operator <= (ComplexNumber &B);
    bool operator == (ComplexNumber &B);
    bool operator >= (ComplexNumber &B);
    bool operator > (ComplexNumber &B);


    double getImaginaryPart() const;
    void setImaginaryPart(double value);

    double getRealPart() const;
    void setRealPart(double value);

private:
    double a; // действительная часть
    double b; // мнимая часть
};

