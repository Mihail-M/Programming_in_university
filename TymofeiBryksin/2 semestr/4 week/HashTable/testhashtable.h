#pragma once
#include <QtCore/QObject>
#include <QtTest/QtTest>
#include "hashtable.h"
#include <iostream>

using namespace std;

class TestHashTable : public QObject
{
	Q_OBJECT
public:
	explicit TestHashTable(QObject *parent = 0) : QObject(parent) {}
private:
	HashTable* table;
	HashFunction* hashFunction;

private slots:
	void init()
	{
		table = new HashTable();
	}

	void testFindSimple()
	{
		string str;
		hashFunction = getHashFunction(1);
		table->setHashFunction(hashFunction);
		table->add(str);
		QCOMPARE(table->find(str), true);
		table->erase(str);
		QCOMPARE(table->find(str), false);
	}

	void testCheckDeg()
	{
		string str;
		hashFunction = getHashFunction(2);
		table->setHashFunction(hashFunction);
		table->add(str);
		QCOMPARE(table->find(str), true);
		table->erase(str);
		QCOMPARE(table->find(str), false);
	}

	void testAddSimple()
	{
		string str = "test1";
		hashFunction = getHashFunction(1);
		table->setHashFunction(hashFunction);
		table->add(str);
		QCOMPARE(table->find(str), true);
		str = "test4";
		table->add(str);
		QCOMPARE(table->find(str), true);
	}

	void testAddPower()
	{
		string str = "test2";
		hashFunction = getHashFunction(2);
		table->setHashFunction(hashFunction);
		table->add(str);
		QCOMPARE(table->find(str), true);
		str = "test3";
		table->add(str);
		QCOMPARE(table->find(str), true);
	}

	void testEraseSimple()
	{
		string str = "wow";
		hashFunction = getHashFunction(1);
		table->setHashFunction(hashFunction);
		table->add(str);
		table->erase(str);
		QCOMPARE(!table->find(str), true);
	}

	void testErasePower()
	{
		string str = "wow";
		hashFunction = getHashFunction(2);
		table->setHashFunction(hashFunction);
		table->add(str);
		table->erase(str);
		QCOMPARE(table->find(str), false);
	}

	void cleanup()
	{
		delete table;
	}
};
//QTEST_MAIN(TestHashTable)
