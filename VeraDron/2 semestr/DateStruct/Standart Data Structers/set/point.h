#pragma once
#include <iostream>

using namespace std;

class point
{
public:
	point();
	~point();

	friend bool operator<(const point & p1, const point & p2);
	friend ostream & operator<<(ostream & stream, const point & p);
	friend istream & operator>>(istream & stream, point & p);


private:
	double x, y;
};

