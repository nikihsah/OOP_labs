#pragma once
#include "figure.h"

class Triangle : public Figure {

	double _a;
	double _b;
	double _c;

public:

	Triangle(double a, double b, double c);

	double Area();
	void Show();
	double* GetAddressA();
	double* GetAddressB();
	double* GetAddressC();

};