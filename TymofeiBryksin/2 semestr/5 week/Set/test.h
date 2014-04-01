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
        delete test;
    }

    void testAdd()
    {
        test = new MySet<int>();
        test->add(1);
        QVERIFY(test->exist(1));
        delete test;
    }
    void testAddSame()
    {
        test = new MySet<int>();
        test->add(1);
        test->add(1);
        QVERIFY(test->size() == 1);
        delete test;
    }


    void testDelete()
    {
        MySet<int> *test = new MySet <int>;
        test = new MySet<int>();
        test->add(1);
        test->remove(1);
        QVERIFY(!test->exist(1));
        delete test;

    }

    void testUnion()
    {
        MySet<int> *test = new MySet <int>;
        MySet<int> *temp = new MySet <int>;
        temp->add(3);
        temp->add(4);
        test->add(2);
        test->add(3);
        temp = test->merge(temp);
        QVERIFY(temp->exist(2) && temp->exist(3) && temp->exist(4));
        delete temp;
        delete test;

    }

    void testIntersect()
    {
        MySet<int> *test = new MySet <int>;
        MySet<int> *temp = new MySet <int>;
        temp->add(3);
        temp->add(4);
        test->add(3);
        temp = test->intersection(temp);
        QVERIFY(!temp->exist(2) && temp->exist(3) && !temp->exist(4));
        delete temp;
        delete test;
    }

private:
    MySet<int> *test;

};
