#include <iostream>

using namespace std;

class Exception
{
public:
	~Exception() {
		cout << "Exception" << endl;
	}
};

class A
{
public:
	~A() {
		cout << "destructor A" << endl;
	}
};

class B
{
public:
	~B() {
		cout << "destructor B" << endl;
	}
};


int main()
{
	try {
		A a;
		B b;
		throw Exception();
	}

	catch (Exception) {
	}
	return 0;
}
