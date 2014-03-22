#pragma once
#include <QtTest/QTest>
#include <QtCore/QObject>

#include "consolewriter.h"
#include "writer.h"

class TestPrinter : public QObject
{
    Q_OBJECT
public:
    explicit TestPrinter(QObject *parent = 0) : QObject(parent) {}
private:

    ConsoleWriter test;
    bool check(int *a, int *b, int n) {
        for (int i = 0; i < n; i++)
            if (a[i] != b[i])
                return false;
        return true;
    }
private slots:
    void testWalk() {
        int **a = new int*[3];
        for(int i = 0; i < 3; i++)
            a[i] = new int[3];
        a[0][0] = 1;
        a[0][1] = 2;
        a[0][2] = 3;
        a[1][0] = 1;
        a[1][1] = 2;
        a[1][2] = 3;
        a[2][0] = 1;
        a[2][1] = 2;
        a[2][2] = 3;
        int b[] = { 2, 3, 3, 2, 1, 1, 1, 2};
        QVERIFY(check(test.getAns(3 , a), b, 3*3-1));
	for (int i = 0; i < 3; i++)
	    delete[] a[i];
	delete[] a;
    }
};
