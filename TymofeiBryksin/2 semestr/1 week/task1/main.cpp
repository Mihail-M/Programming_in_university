#include <iostream>
#include "circulyrlist.h"
#include "acicliclist.h"
#include "testAciclicList.h"
#include "testCicrculyrList.h"

using namespace std;

int main()
{
    TestAciclicList test1;
    QTest::qExec(&test1);
    TestCirculyrList test2;
    QTest::qExec(&test2);

}

