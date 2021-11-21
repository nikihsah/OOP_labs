#include <iostream>
#include "figure.h"
#include "new_fig.h"

//=============================================== 1.1 ЗАДАНИЕ =========================
class Base1
{
	int i;
public:
	Base1()
	{
		i = 0;
		cout << "void constructor Base1. i = 0" << endl;
	};

	Base1(int in)
	{
		i = in;

		cout << "Constructor Base1 with params" << endl;
	}

	~Base1()
	{
		cout << "Destructor Base1" << endl;
	}

	void PutI(int in)
	{
		i = in;
	}

	int GetI()
	{
		return i;
	}
};

class Base2
{
	string name;
	int count = 0;

public:
	Base2()
	{
		name = "Empty";
		cout << "Void constructor Base2" << endl;
	};

	Base2(string names)
	{
		name = names;

		cout << "Constructor Base2 with params" << endl;
	}

	~Base2()
	{
		cout << "Destructor Base2" << endl;
	}

	void PutStr(string names)
	{
		name = names;
	}

	string GetStr()
	{
		return name;
	}
};

class Derived : public Base1, public Base2
{
	char ch;
public:
	Derived()
	{
		ch = 'V';
	};

	Derived(char cha, string name, int i) : Base1(i), Base2(name)
	{
		ch = cha;
	}

	~Derived()
	{
		cout << "Destructor Derived" << endl;
	}

	void putCh(char cha)
	{
		ch = cha;
	}

	char getCh()
	{
		return ch;
	}
};

ostream& operator << (ostream& out, Derived& derived)
{
	out << "Ch:  " << derived.getCh() << endl;
	out << "i: " << derived.GetI() << endl;
	out << "Names: " << derived.GetStr() << endl;

	return out;
}

class DomesticAnimal
{

protected:

	double _weight;
	double _price;
	string _color;

public:

	DomesticAnimal() = default;

	DomesticAnimal(double weight, double price, string color)
	{
		_weight = weight;
		_price = price;
		_color = color;
	}

	void print()
	{
		cout << "Class DomesticAnimal" << endl;
		cout << "Weight: " << _weight << endl;
		cout << "Price: " << _price << endl;
		cout << "Color: " << _color << endl;
	}
};


class Cow : virtual public DomesticAnimal
{
public:

	void print()
	{
		cout << "Class Cow" << endl;
		cout << "Weight: " << _weight << endl;
		cout << "Price: " << _price << endl;
		cout << "Color: " << _color << endl;
	}
};

class Buffalo : virtual public DomesticAnimal
{
public:
	Buffalo() = default;

	Buffalo(double weight, double price, string color) : DomesticAnimal(weight, price, color)
	{

	}

	void print()
	{
		cout << "Class Buffalo" << endl;
		cout << "Weight: " << _weight << endl;
		cout << "Price: " << _price << endl;
		cout << "Color: " << _color << endl;
	}
};

class Beefalo : public Buffalo, public Cow
{
public:
	Beefalo() = default;

	Beefalo(double weight, double price, string color)
	{
		_weight = weight;
		_price = price;
		_color = color;
	}

	void print()
	{
		cout << "Class Buffalo" << endl;
		cout << "Weight: " << _weight << endl;
		cout << "Price: " << _price << endl;
		cout << "Color: " << _color << endl;
	}
};

int main()
{

    Circle circle(-1);
    Rectangle rect(-2.0, 3.0);
    circle.Show();
    rect.Show();
    Triangle trian(2.0, 3.0, 4.0);
    trian.Show();
}
