#pragma once

#include <QObject>
#include <QtTest/QtTest>

#include "myset.h"

class Test : public QObject
{
    Q_OBJECT
public:
    explicit Test(QObject *parent = 0){};

private slots:
    void initTestCase()
    {
        test = new MySet<int>();
    }

    void testAdd()
    {
        test->add(1);
        QVERIFY(test->exist(1));
    }

    void testDelete()
    {
        test->add(1);
        test->remove(1);
        QVERIFY(!test->exist(1));
    }

    void testUnion()
    {
        MySet<int> *temp = new MySet <int>;
        temp->add(3);
        temp->add(4);
        test->add(2);
        test->add(3);
        temp = test->merge(temp);
        QVERIFY(temp->exist(2) && temp->exist(3) && temp->exist(4));
    }

    void testIntersect()
    {
        MySet<int> *temp = new MySet <int>;
        temp->add(3);
        temp->add(4);
        test->add(3);
        temp = test->intersection(temp);
        QVERIFY(!temp->exist(2) && temp->exist(3) && !temp->exist(4));
    }

    void cleanupTestCase()
    {
        delete test;
    }

private:
    MySet<int> *test;

};
