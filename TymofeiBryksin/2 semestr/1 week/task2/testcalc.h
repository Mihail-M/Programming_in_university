#pragma once

#include <QtTest/QTest>
#include <QtCore/QObject>
#include "calc.h"

class TestCalc : public QObject
{
    Q_OBJECT
public:
    explicit TestCalc(QObject *parent = 0) : QObject(parent) {}
private:
    Calc *test;
private slots:
    void testInit() {
        test = new Calc;

    }
    void testCalculate() {
        test = new Calc;
        char testExp[] = {'1','+','2','*','3','/','3'};
        QVERIFY(test->calculate(testExp) == 3);
    }
};

