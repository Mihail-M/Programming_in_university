#pragma once

#include <QtTest/QTest>
#include <QtCore/QObject>

#include "stackpointer.h"

class TestStack : public QObject
{
    Q_OBJECT
public:
    explicit TestStack(QObject *parent = 0) : QObject(parent) {}
private:
    Stack *test;

private slots:
    void testInit() {
        test = new StackPointer;
        QVERIFY(test->size() == 0);
    }

    void testPush() {
        test = new StackPointer;
        double testNum = 1;
        test->push(testNum);
        QVERIFY(test->size() == 1);
        QVERIFY(test->top() == 1);
    }
    void testPop() {
        test = new StackPointer;
        double testNum = 1;
        test->push(testNum);
        test->pop();
        QVERIFY(test->size() == 0);
    }

    void testClear() {
        test = new StackPointer;
        double testNum = 1;
        test->push(testNum);
        test->push(testNum);
        test->push(testNum);
        test->push(testNum);

        test->clear();
        QVERIFY(test->size() == 0);
    }

    void cleanupTestCase()
    {
        delete test;
    }

};
