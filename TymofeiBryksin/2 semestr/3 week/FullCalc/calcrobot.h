#pragma once
#include "calc.h"

class CalcRobot
{
public:
    CalcRobot();
    ///Устанавливает операцию
    void addOperand(int value);
    ///Добавляет цифру к текущему числу
    QString appendNumber(int number);
    ///Добавляет точку к текущему числу
    QString appendDot();
    ///Вычисляет выражение
    QString calculate();
    void clear();

private:
    QString a;
    QString b;
    QString prevB;
    int operand;
    ///флаг, редактировать ли первое или второе число
    bool secondNumber;
 };

