#pragma once
#include <QtCore/QObject>
#include <QtTest/QtTest>
#include "hashTable.h"
#include <iostream>

using namespace std;

class TestHashTable : public QObject
{
    Q_OBJECT
public:
    explicit TestHashTable(QObject *parent = 0) : QObject(parent) {}
private:
    HashTable* table;
    HashFunction* simple;
    HashFunction* power;

private slots:
    void initTestCase()
    {
        table = new HashTable();
        simple = getHashFunction(1);
        power = getHashFunction(2);
    }

    void testFindSimple()
    {
        string str;
        simple = getHashFunction(1);
        table->hashFunc = simple;
        table->add(str);
        QCOMPARE(table->find(str), true);
        table->erase(str);
        QCOMPARE(table->find(str), false);
    }

    void testCheckDeg()
    {
        string str;
        power = getHashFunction(2);
        table->hashFunc = power;
        table->add(str);
        QCOMPARE(table->find(str), true);
        table->erase(str);
        QCOMPARE(table->find(str), false);
    }

    void testAddSimple()
    {
        string str = "test1";
        simple = getHashFunction(1);
        table->hashFunc = simple;
        table->add(str);
        QCOMPARE(table->find(str), true);
        str = "test4";
        table->add(str);
        QCOMPARE(table->find(str), true);
    }

    void testAddPower()
    {
        string str = "test2";
        power = getHashFunction(2);
        table->hashFunc = power;
        table->add(str);
        QCOMPARE(table->find(str), true);
        str = "test3";
        table->add(str);
        QCOMPARE(table->find(str), true);
    }

    void testEraseSimple()
    {
        string str = "wow";
        simple = getHashFunction(1);
        table->hashFunc = simple;
        table->add(str);
        table->erase(str);
        QCOMPARE(!table->find(str), true);
    }

    void testErasePower()
    {
        string str = "wow";
        power = getHashFunction(2);
        table->hashFunc = power;
        table->add(str);
        table->erase(str);
        QCOMPARE(table->find(str), false);
    }

    void cleanupTestCase()
    {
        delete table;
    }
};
//QTEST_MAIN(TestHashTable)
