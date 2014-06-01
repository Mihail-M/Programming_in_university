#include "point.h"
using namespace std;

point::point()
{
}


point::~point()
{
}

ostream & operator<<(ostream & stream, const point & a)
{
	cout << "(" << a.x << "; " << a.y << ")";
	return stream;
}

istream & operator>>(istream & stream, point & a)
{
	cin >> a.x >> a.y;
	return stream;
}

bool operator<(const point & a, const point & b)
{
	if (a.x < b.x || (abs(a.x - b.x) < 1e-7 &&	a.y < b.y))
		return true;
	return false;
}
