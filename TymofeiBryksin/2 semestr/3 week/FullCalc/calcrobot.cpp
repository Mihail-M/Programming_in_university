#include "calc.h"
#include <iostream>
CalcRobot::CalcRobot(): secondNumber(false)
{
}


void CalcRobot::addOperand(int value)
{
    operand = value;
    secondNumber = true;
}

QString CalcRobot::appendDot()
{
    if (!secondNumber)
        if (a.indexOf(".") == -1)
        {
            a.append(".");
        }
    else return a;

    else if (b.indexOf(".") == -1){
        b.append(".");
        return b;
    }
    else
        return b;
}

QString CalcRobot::calculate()
{
    double ans = 0;
    double first = a.toDouble();
    double second = b.toDouble();
    if(b == ""){
        second = prevB.toDouble();
    }
    if (operand == 1){
        ans = first + second;
    }
    if (operand == 2){
        ans = first - second;
    }
    if (operand == 3)
        ans = first * second;
    if (operand == 4){
        if(second == 0)
            return "Errow";
        ans = first / second;
    }
    a = QString::number(ans);
    prevB = QString::number(second);
    b.clear();
    return QString::number(ans);

}

void CalcRobot::clear()
{
    secondNumber = false;
    a.clear();
    b.clear();
    prevB.clear();

}

QString CalcRobot::appendNumber(int number)
{
    if (!secondNumber){
        a.append(QString::number(number));
        return a;
    }
    else {
        b.append(QString::number(number));
        return b;
    }
}



