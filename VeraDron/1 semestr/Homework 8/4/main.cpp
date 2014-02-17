#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

int main()
{
	double a,b;
	char c;
	cin >> a;
	cin >> c;
	while(c!='$'){
        cin >> b;
        if(c == '+')a = a+b;
        if(c == '-')a = a-b;
        if(c == '*')a= a*b;
        if(c=='/') a = a/b;
        cin >> c;
	}
    cout   << a;
	return 0;
}
