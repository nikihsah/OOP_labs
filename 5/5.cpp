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
		cout << "����������� BASE" << endl;
	}

	//Protected � ������ ������ �������, ����������� �� �������.
	~BASE() {
		cout << "���������� BASE" << endl;
	}

	//����� �������
	int* getAdri(){
		return &i;
	}
	double* getAdrd() {
		return &d;
	}
	long* getAdrl() {
		return &l;
	}

	//�.�. d - private ���� ������� ������ �� ��������� � ���������
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
		cout << "����������� DERIVED" << endl;
	}

	~DERIVED() {
	cout << "���������� DERIVED" << endl;
	}

	//����� �������
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

	//������� ��������  DERIVED ff, �� ���� �� ��� �� ������, �� ������� BASE ff. ������ � ��������� �������
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



