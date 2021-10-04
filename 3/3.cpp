#include <iostream>
#include <string>
using namespace std;
// ������� 1.1 - 1.4 = �������� ������ � ������
class Goods {

	int _price, _count;
	string _name, _date, _number;

public:

	Goods() {
		_price = 0;
		_count = 0;
		_name = "Null";
		_date = "10-10-2001";
		_number = "121321321";
		cout << "������������" << endl;
		cout << endl;
	}

	~Goods(){
		cout << "����������" << endl;
		cout << endl;
	};

	void Set_Good(string name, string date, int price, int count, string number) {
		_price = price;
		_count = count;
		_name = name;
		_date = date;
		_number = number;
		cout << "���������" << endl;
		cout << endl;
	}

	void show() {
		cout << "����� = " <<_price << endl;
		cout << "���-�� = " << _count << endl;
		cout << "��� = " << _name << endl;
		cout << "���� = " << _date << endl;
		cout << "����� = " << _number << endl;
		cout << endl;
	}

	int get_all_price() {
		return _price * _count;
	}

	// ������� 1.5 = �������� ������������ �����������
	Goods(const Goods & obj) {
		_price = obj._price;
		_count = obj._count;
		_name = obj._name;
		_date = obj._date;
		_number = obj._number;
		cout << "�����������" << endl;
		cout << endl;
	}

};

Goods tovar(Goods &tovar) {
	cout << "����� ������� tovar" << endl;
	return tovar;
};

int main() {

	setlocale(LC_ALL, "Russian");
	cout << "���� � ������� main()" << endl;
	cout << endl;

	Goods cream;

	cream.Set_Good("����", "03-12-1555", 100, 10, "2654452565562");
	cout << cream.get_all_price() << endl;
	cream.show();
	
	// ������� 1.5.1 = ������������� ����� ����������� �����������
	Goods cream_cop(cream);
	cream_cop.show();

	//������� tovar
	cout << "������� �����" << endl;
	tovar(cream);

	cout << "����� �� ������� main()" << endl;
	cout << endl;
}