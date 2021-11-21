#include <iostream>
#include "new_fig.h"
#include <math.h>
using namespace std;

Triangle::Triangle(double a, double b, double c) {
	if (a < 0 and b < 0 and c < 0 and a+b > c and a+c > b and b+c > a) {
		throw "Triangle error. Check figure sides";
	}

	_a = a;
	_b = b;
	_c = c;
}

double Triangle::Area() {
	double p = (_a + _b + _c) / 2;
	return sqrt(p * (p - _a) * (p - _b) * (p - _c));
}

void Triangle::Show() {
	cout << "Triangle:" << endl;
	cout << "A = " << _a << endl;
	cout << "B = " << _b << endl;
	cout << "C = " << _c << endl;
	cout << "Area = " << Area() << endl;
	cout << endl << endl;
}