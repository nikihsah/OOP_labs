#include <iostream>
#include <string>
using namespace std;

class Abonent {

	int id;
	string second_name, number;
	friend class Notebook;

public:

	Abonent(int Id, string Second_name, string Number) {
		id = Id;
		second_name = Second_name;
		number = Number;
	}

	~Abonent() = default;
};

class Notebook {

public:
	void change(Abonent* str,int id, string numb) {
		if (str->id == id)
		{	
			str->number = numb;
			cout << "������!" << endl;
			cout << endl;
		}
	}

	void Show(Abonent* str) {
		cout << "|\t" << str->id << "\t|\t" << str->second_name << "\t|\t" << str->number << "\t|" << endl;
	}
};

int main() {

	setlocale(LC_ALL, "Russian");

	Abonent People[8] = {
		Abonent(
			0,
			"��������",
			"5664646464"
		),
		Abonent(
			1,
			"������������",
			"46546546584"
		),
		Abonent(
			2,
			"�����������",
			"1561516514"
		),
		Abonent(
			3,
			"��������",
			"45456456455"
		),
		Abonent(
			4,
			"������� ",
			"1231231231"
		),
		Abonent(
			5,
			"��������",
			"546456456456"
		),
		Abonent(
			6,
			"��������",
			"45645456"
		),
		Abonent(
			7,
			"���������",
			"456456456"
		)
	};

	int id;
	string numb;
	cout << "������� id: ";
	cin >> id;
	cout << endl;
	cout << "������� ����� �����: ";
	cin >> numb;

	Notebook note;

	for (auto peoples : People)
	{
		note.change(&peoples, id, numb);
		note.Show(&peoples);
	}
	cout << endl;
	cout << endl;
	for (auto peoples : People)
	{
		note.Show(&peoples);
	}
}