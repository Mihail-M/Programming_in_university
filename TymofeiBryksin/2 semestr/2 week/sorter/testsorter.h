#pragma once
#include <QtTest/QTest>
#include <QtCore/QObject>

#include "mergesorter.h"
#include "bubblesorter.h"


class TestSorter: public QObject
{
    Q_OBJECT
public:
    explicit TestSorter(QObject *parent = 0) : QObject(parent) {}
private:

    MergeSorter a;
    BubbleSorter b;
    bool check(int *a, int *b, int n) {
        for (int i = 0; i < n; i++)
            if (a[i] != b[i])
                return false;
        return true;
    }



private slots:
    void sortMerge() {
        int q[] = {1, 3 , 2, 4};
        int b[] = {1, 2, 3, 4};
        a.sort(q, 0, 3);
        QVERIFY(check(q, b, 4));
    }

    void sortBubble() {
        int q[] = {1, 3 , 2, 4};
        int e[] = {1, 2, 3, 4};
        b.sort(q, 0, 3);
        QVERIFY(check(q, e, 4));
    }


};

