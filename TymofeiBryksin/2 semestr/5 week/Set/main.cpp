#include "myset.h"
#include "test.h"


using namespace std;

int main()
{
	Test test;
	QTest::qExec(&test);
}
