#pragma once
#include <QtTest/QTest>
#include <QtCore/QObject>

#include "acicliclist.h"


class TestAciclicList : public QObject
{
    Q_OBJECT
public:
    explicit TestAciclicList(QObject *parent = 0) : QObject(parent) {}
private:
    AciclicList *test;
private slots:

	void init() {
        test = new AciclicList;
    }

    void testPushBack() {
        double testNum = 123;
        test->pushBack(testNum + 1);
        test->pushBack(testNum);
        QVERIFY(test->size() == 2);
        QVERIFY(test->back() == testNum);
    }

    void testPushFront() {
        double testNum = 123;
        test->pushBack(testNum + 1);
        test->pushBack(testNum);
        QVERIFY(test->size() == 2);
        QVERIFY(test->front() == testNum + 1);
    }

    void testPopFront() {
        double testNum = 123;
        test->pushBack(testNum + 1);
        test->pushBack(testNum);
        test->popFront();
        QVERIFY(test->front() == testNum);
    }


    void testPopBack() {
        double testNum = 123;
        test->pushBack(testNum + 1);
        test->pushBack(testNum);
        test->pushBack(testNum + 2);

        test->popBack();
        QVERIFY(test->back() == testNum);
    }
    void testFind() {
        double testNum = 123;
        test->pushBack(testNum);
        test->pushBack(testNum);

        QVERIFY(test->find(testNum));
        QVERIFY(!test->find(testNum + 1));
    }

    void testErase() {
        double testNum = 123;
        test->pushBack(testNum);
        test->pushBack(testNum + 1);
        test->pushBack(testNum + 2);

        test->erase(1);
        QVERIFY(!test->find(testNum + 1));
    }

    void testEraseByValue() {
        double testNum = 123;
        test->pushBack(testNum);
        test->pushBack(testNum + 1);
        test->pushBack(testNum + 2);

        test->erase(testNum + 1);
        QVERIFY(!test->find(testNum + 1));
    }

    void testAdd() {
        double testNum = 123;
        test->pushBack(testNum);
        test->pushBack(testNum + 1);
        test->pushBack(testNum + 2);
        test->add(1, testNum + 3);
        test->popBack();
        QVERIFY(test->back() == testNum + 3);
    }

    void testReverse() {

		AciclicList *tempTest = new AciclicList;
        double testNum = 1;
        test->pushBack(testNum);
        test->pushBack(testNum + 1);
        test->pushBack(testNum + 2);
        tempTest->pushFront(testNum);
        tempTest->pushFront(testNum + 1);
        tempTest->pushFront(testNum + 2);
        test->reverse();
        for(int i = 0; i < test->size(); i++)
        {
            QCOMPARE(test->front(), tempTest->front());
            test->popFront();
            tempTest->popFront();
        }
		delete tempTest;

    }

	void cleanup()
    {
        delete test;
    }

};
