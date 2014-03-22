#include <iostream>
#include "stringbbc.h"
using namespace std;

int main()
{

    StringBBC s, s1("NATASHA");
    cin >> s;
    cout << s << endl;

    s.push_back('1');
    cout << s << endl;
    s += "MISHA";
    cout << s << endl;
    /*s.push_back('1');
    s.push_back('a');
    s.push_back('a');
    s.push_back('a');
    s.push_back('a');
    //s.insert(0, "123424");
    cout << s << endl;
    s += s1;
    cout << s << endl;
    s.erase(4,3);
    //s.show();
    return 0;
*/

}

