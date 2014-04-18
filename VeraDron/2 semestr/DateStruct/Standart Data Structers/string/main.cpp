#include <iostream>
#include "stringbbc.h"
using namespace std;

int main()
{

	StringBBC s("MishA");
	cout << s.size() << " " << s.capacity() << endl;
	cout << s;
	s.insert(2, "Masha");
	cout << s;
	cout << s.size() << " " << s.capacity() << endl;
	s.insert(2, "Natasha");
	cout << s.size() << " " << s.capacity() << endl;
	s.erase(2, 10);
	cout << s;
	cout << s.size() << " " << s.capacity() << endl;
	StringBBC h("veronikka");
	cout << h << endl;
	h += s;
	cout << h << endl;
	cout << (h + s).size() << " " << (h + s).capacity() << endl;
}
