#pragma once
#include <QtTest/QTest>
#include <QtCore/QObject>
#include "bubblesorter.h"


class TestSorter: public QObject
{
    Q_OBJECT
public:
    explicit TestSorter(QObject *parent = 0) : QObject(parent) {}
private:

    BubbleSorter b;
    bool check(int **a, int **b, int n) {
        for (int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
            if (a[i][j] != b[i][j])
                return false;
        return true;
    }
    void transposeMatrix1(int **&arr, int n, int m) {

        int **b = new int*[m];
        for(int i = 0; i < m; i++)
            b[i] = new int[n];

        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                b[j][i] = arr[i][j];

        for(int i = 0; i < n; i++)
            delete[] arr[i];
        delete[] arr;
        arr = b;
    int c = n;
    n = m;
    m = c;
    }



private slots:
    void sortBubble() {
        int **test = new int*[2];
        test[0] = new int[2];
        test[1] = new int[2];
        test[0][0] = 2;
        test[0][1] = 1;
        test[1][0] = 1;
        test[1][1] = 2;
        int **ans = new int*[2];
        ans[0] = new int[2];
        ans[1] = new int[2];
        ans[0][0] = 1;
        ans[0][1] = 2;
        ans[1][0] = 2;
        ans[1][1] = 1;
        transposeMatrix1(test, 2, 2);
        b.sort(test, 0, 1);
        QVERIFY(check(test, ans, 2));
        for(int i = 0; i < 2; i++){
            delete[] test[i];
            delete[] ans[i];
        }
        delete[] test;
        delete[] ans;
    }


};

