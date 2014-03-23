#pragma once
#include <QtTest/QTTest>
#include <QtCore/QObject>

#include <fstream>
#include "treeparse.h"

class TestTreeParse : public QObject
{
     Q_OBJECT
public:
    explicit TestTreeParse(QObject *parent = 0) : QObject(parent) {}
private:
    TreeParse* testTree;
    std::ifstream test1;
    std::ifstream test2;
private slots:
    void initTestCase()
    {
        testTree = new TreeParse();
        test1.open("tests/test1.txt");
        test2.open("tests/test2.txt");
    }

    void testCalc1()
    {
        testTree->clear();
        testTree->parse(test1);
        QCOMPARE(testTree->calculate(), 4.0);
    }

    void testCalc2()
    {
        testTree->clear();
        testTree->parse(test2);
        QCOMPARE(testTree->calculate(), 30.0);
    }

    void cleanupTestCase()
    {
        delete testTree;
        test1.close();
        test2.close();
    }
};
