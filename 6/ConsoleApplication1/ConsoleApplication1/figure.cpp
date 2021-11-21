#include <iostream>
#include "figure.h"
using namespace std;

Rectangle::Rectangle(double widht) {
	try
	{
		if (widht < 0) {
			throw "Widht square < 0. Now the widht is 0";
		};
	}
	catch (const char* eror) {
		cout << eror << endl << endl;
		widht = 0;
	}
	_widht = widht;
	_height = widht;
	
	}

Rectangle::Rectangle(double widht, double height) {
	try
	{
		if (widht < 0) {
			throw (widht);
		}
		else if(height < 0) {
			throw (height);
		};
	}
	catch (double name) {
		cout << "Widht or height rectangle < 0. Now this side is 0" << endl << endl;
		name = 0;
	}
	_widht = widht;
	_height = height;
}

double Rectangle::Area() {
	double area = _widht * _height;
	return area;
}

double*  Rectangle::GetAdressHeight() {
	return &_height;
}

double* Rectangle::GetAdressWidht() {
	return &_widht;
}

void Rectangle::Show() {
	if (_widht = _height) {
		cout << "Square:" << endl;
	}
	else {
		cout << "Rectangle:" << endl;
	}
	cout << "Widht = "<< _widht << endl;
	cout << "Height = " << _height << endl;
	cout << "Area = " << Area() << endl;
	cout << endl << endl;
}

//---------------------Circle-------------------
Circle::Circle(double radius) {
	try
	{
		if (radius < 0) {
			throw "Radius circle < 0. Now the radius is 0";
		};
	}
	catch (const char* eror) {
		cout << eror << endl << endl;
		radius = 0;
	}
	
	_radius = radius;
}

double Circle::Area() {
	return _radius * _radius * 3.14;
}

double* Circle::GetAdress() {
	return &_radius;
}

void Circle::Show() {
	cout << "Circle:" << endl;
	cout << "Radius = " << _radius << endl;
	cout << "Area = " << Area() << endl;
	cout << endl << endl;
}