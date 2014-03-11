#pragma once
#include "calc.h"
/**
 * @CalcRobot
 * Отвечает за вычисление выражения
 *
*/
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
    ///очищает калькулятор и подготавливает к новому вычислению
    void clear();

private:
    ///первое число
    QString a;
    ///второе число
    QString b;
    ///число, прибавляемое к первому, если не задано второе(после вычисления операции)
    QString prevB;
    ///номер операции
    int operand;
    ///флаг, редактировать ли первое или второе число
    bool secondNumber;
 };

