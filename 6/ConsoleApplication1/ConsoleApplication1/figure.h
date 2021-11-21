#pragma once
#include <iostream>
using namespace std;

class Figure
{
	virtual double Area() = 0;
	virtual void Show() = 0;
};

class Rectangle : public Figure
{
	double _widht;
	double _height;

public:
	Rectangle(double widht);

	Rectangle(double widht, double height);

	double Area();

	void Show();

	double* GetAdressWidht();

	double* GetAdressHeight();
};

class Circle : public Figure
{
	double _radius;

public:
	Circle(double radius);

	double Area();

	void Show();

	double* GetAdress();
};
