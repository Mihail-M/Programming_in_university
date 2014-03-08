#pragma once
#include <QSignalMapper>
#include <QWidget>
#include "calcrobot.h"

namespace Ui {
class Calc;
}

class Calc : public QWidget
{
    Q_OBJECT

public:
    explicit Calc(QWidget *parent = 0);
    ~Calc();
    CalcRobot calcRobot;
private:
    Ui::Calc *ui;
    QSignalMapper *numbersMapper;
    QSignalMapper *operationMapper;

private slots:
    void numberPressed(int const number);
    void dotPressed();
    void equalPressed();
    void operandPressed(int operand);
    void clearCalc();


};


