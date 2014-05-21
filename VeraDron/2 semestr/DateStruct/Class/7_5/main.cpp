#include <iostream>
#include <algorithm>

using namespace std;


class Shape {
public:
	Shape(){};
	virtual ~Shape(){};
	virtual double area() = 0;
};

class Triangle: public Shape {
public:

	Triangle(int _a, int _h): a(_a), h(_h){}
	double area() {
		return 0.5*a*h;
	}
private:
	int a,  h;
};

class Square: public Shape {
public:

	Square(int _a): Shape(), a(_a){}
	double area() {
		return a*a;
	}
private:
	int a;
};

class Restangle: public Shape {
public:
	Restangle(int _a, int _h): Shape(), a(_a), h(_h){}
	double area() {
		return a*h;
	}
private:
	int a,  h;
};


bool f(Shape *a, Shape *b) {
	return a->area() > b->area();
}

int main()
{
	Shape *a = new Triangle(42 , 23);
	Shape *b = new Square(42);
	Shape *c = new Restangle(42, 23);
	Shape **arr = new Shape*[3];

	arr[0] = a;
	arr[1] = b;
	arr[2] = c;
	sort(arr, arr+3, f);

	for(int i = 0; i < 3; i++)
		cout << arr[i]->area() << " ";

    delete[] a;
    delete[] b;
    delete[] c;
    for(int i = 0; i < 3; i++)
        delete[] arr[i];
    delete[] arr;
	return 0;
}


