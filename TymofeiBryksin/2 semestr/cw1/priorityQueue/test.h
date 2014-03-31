#pragma once

#include <QtCore/QObject>
#include <QtTest/Qtest>
#include <iostream>
#include "priorityQueue.h"

class Test : public QObject
{
     Q_OBJECT
public:
    explicit Test(QObject *parent = 0) : QObject(parent) {}

private:
    PriorityQueue <int> *test;
private slots:
    void init(){
        test = new PriorityQueue<int>;
    }

    void initTestCase() {
        test = new PriorityQueue<int>;
        QVERIFY(test->length() == 0);
    }
    void cleanup() {
        delete test;
    }
    void enqueueTest() {
        test->enqueue(3, 2);
        test->enqueue(1, 4);
        QVERIFY(test->length() == 2);
    }
    void dequeueTest() {
        test->enqueue(3, 2);
        test->enqueue(1, 4);
        test->enqueue(2, 3);

        QVERIFY(test->dequeue() == 1);
    }

    void emptyTest() {
        try {
            test->dequeue();
        }
        catch(PriorityQueue<int>::EmptyQueueException &) {
            qDebug("OK!");
        }

    }
};

