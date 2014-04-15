#pragma once

#include <QObject>
#include <QtTest/QtTest>

#include <iostream>
#include "uniquelist.h"

class Test : public QObject
{
	Q_OBJECT
public:
	explicit Test(QObject *parent = 0){}

private slots:
	void init()
	{
		test = new UniqueList();
	}

	void testEmptyUniqueList()
	{
		QVERIFY(test->size() == 0);
	}

	void testUniqueListInsert()
	{
		try
		{
			test->add('1', 0);
		}
		catch (const Exception &exec)
		{
			std::cout << exec.get() << std::endl;
		}
		QVERIFY(test->size() == 1.0);
	}

void testEmptyDelete() {
		try
		{
			test->popBack();
		}
		catch (const Exception &exec)
		{
			std::cout << exec.get() << std::endl;
		}

		QVERIFY(test->size() == 0.0);

	}

	void testAddDuplicate() {
		try
		{
			test->pushBack('1');
			test->pushBack('1');
		}
		catch (const Exception &exec)
		{
			std::cout << exec.get() << std::endl;
		}

		QVERIFY(test->size() == 1.0);

	}

	void testUniqueListDelete()
	{
		try
		{
			test->pushBack('1');
			test->pushBack('2');
			test->pushBack('3');
			test->add(1, '4');
			test->erase(2);
		}
		catch (const Exception &exec)
		{
			std::cout << exec.get() << std::endl;
		}

		QVERIFY(!test->find(4));
	}

	void cleanup()
	{
		delete test;
	}

private:
	UniqueList *test;

};
