#include <iostream>
#include <string>
using namespace std;
// Задание 1.1 - 1.4 = создание класса и вывода
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
		cout << "Конструктоор" << endl;
		cout << endl;
	}

	~Goods(){
		cout << "Деструктор" << endl;
		cout << endl;
	};

	void Set_Good(string name, string date, int price, int count, string number) {
		_price = price;
		_count = count;
		_name = name;
		_date = date;
		_number = number;
		cout << "Изменение" << endl;
		cout << endl;
	}

	void show() {
		cout << "Ценна = " <<_price << endl;
		cout << "Кол-во = " << _count << endl;
		cout << "Имя = " << _name << endl;
		cout << "Дата = " << _date << endl;
		cout << "Номер = " << _number << endl;
		cout << endl;
	}

	int get_all_price() {
		return _price * _count;
	}

	// Задание 1.5 = создание конструктора копирование
	Goods(const Goods & obj) {
		_price = obj._price;
		_count = obj._count;
		_name = obj._name;
		_date = obj._date;
		_number = obj._number;
		cout << "Копирование" << endl;
		cout << endl;
	}

};

Goods tovar(Goods &tovar) {
	cout << "Вызов функции tovar" << endl;
	return tovar;
};

int main() {

	setlocale(LC_ALL, "Russian");
	cout << "Вход в функцию main()" << endl;
	cout << endl;

	Goods cream;

	cream.Set_Good("Крем", "03-12-1555", 100, 10, "2654452565562");
	cout << cream.get_all_price() << endl;
	cream.show();
	
	// Задание 1.5.1 = инициализация через конструктор копирования
	Goods cream_cop(cream);
	cream_cop.show();

	//Функция tovar
	cout << "Функция товар" << endl;
	tovar(cream);

	cout << "Выход из функции main()" << endl;
	cout << endl;
}