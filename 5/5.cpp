#include <iostream>
#include <string>
using namespace std;
class BASE {
private:

	double d;

protected:

	long l;

	void ff() {
		cout << "ff BASE" << endl;
	};

public:
	int i;

	BASE(int in, double doub, long lon) {
		i = in;
		d = doub;
		l = lon;
		cout << "Конструктор BASE" << endl;
	}

	//Protected — доступ открыт классам, производным от данного.
	~BASE() {
		cout << "Деструктор BASE" << endl;
	}

	//Вывод адресов
	int* getAdri(){
		return &i;
	}
	double* getAdrd() {
		return &d;
	}
	long* getAdrl() {
		return &l;
	}

	//Т.к. d - private Надо описать методы ее получения и изменения
	void setd(double value) {
		d = value;
	}
	double getd() {
		return d;
	}

	
};

class DERIVED : public BASE{
private:

	float f;

public:

	DERIVED()= default;
	DERIVED(int in, double doub, long lon, float floa): BASE(in, doub, lon){
		f = floa;
		cout << "Конструктор DERIVED" << endl;
	}

	~DERIVED() {
	cout << "Деструктор DERIVED" << endl;
	}

	//Вывод адресов
	float* getAdrf() {
		return &f;
	}
protected:
	void ff() {
		cout << "ff DERIVED" << endl;
	};
};

class DERIVED_L : public DERIVED {
public:
	DERIVED_L() = default;
	DERIVED_L(int in, double doub, long lon, float floa) : DERIVED(in, doub, lon, floa) {};

	//Сначала вывводит  DERIVED ff, но если мы там ее уберем, то выведет BASE ff. Глобал в последнюю очередь
	void foo() {
		i++;
		l += l;
		ff();
	}

};

ostream& operator << (ostream& out, DERIVED& d) {
	out << "i - " << d.getAdri() << endl;
	out << "d - " << d.getAdrd() << endl;
	out << "l - " << d.getAdrl() << endl;
	out << "f - " << d.getAdrf() << endl;

	return out;
};

ostream& operator << (ostream& out, DERIVED_L& d) {
	out << "i - " << d.getAdri() << endl;
	out << "d - " << d.getAdrd() << endl;
	out << "l - " << d.getAdrl() << endl;
	out << "f - " << d.getAdrf() << endl;

	return out;
};

void ff() {
	cout << "ff global" << endl;
};

void line() {
	cout << "________________________________" << endl;
	cout << "________________________________" << endl;
	cout << "________________________________" << endl;
};

void main() {
	setlocale(LC_ALL, "Russian");

	DERIVED first(10, 10.10, 10, 10.10);
	cout << first;

	line();

	DERIVED_L second(10, 10.10, 10, 10.10);
	cout << second;

	line();
	second.foo();
}



