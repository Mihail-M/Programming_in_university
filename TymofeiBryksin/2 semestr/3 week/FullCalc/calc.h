#pragma once
#include <QSignalMapper>
#include <QWidget>
#include "calcrobot.h"

namespace Ui {
/**
 *@Class Calc
 * отвечает за вывод на виджет информации, используя класс для вычисления ClassRobot
 */
class Calc;
}

class Calc : public QWidget
{
    Q_OBJECT

public:
    explicit Calc(QWidget *parent = 0);
    ~Calc();

private slots:
    ///метод, обрабатывающий нажание на кнопку с цифрой
    void numberPressed(int const number);
    ///метод, обрабатывающий нажание на кнопку с точкой
    void dotPressed();
    ///метод, обрабатывающий нажатие на кнопку равно
    void equalPressed();
    ///метод, обрабатывающий нажатие на кнопку +,-,*,/
    void operandPressed(int operand);
    ///Очищает поле результата и CalcRobot
    void clearCalc();

private:
    Ui::Calc *ui;
    QSignalMapper *numbersMapper;
    QSignalMapper *operationMapper;
    ///отвечает за вычисления
    CalcRobot calcRobot;





};


