#include <iostream>
#include  "hashtable.h"
#include "userchoice.h"
#include "testhashtable.h"

using namespace std;

int main()
{
	HashTable b;
	TestHashTable a;
	QTest::qExec(&a);
	UserChoice c;
	c.choice(&b);
	return 0;
}

