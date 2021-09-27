#include <iostream>
#include <string>
using namespace std;

class Test {
	int W = 1;
	friend void fun(Test*);

public:
	Test() = default;

	void print()
	{
		cout << "Это закрытая функция класса Test" << endl;
	}

	~Test() = default;
};

void fun(Test* ptr) {
	cout << ptr->W << endl;
	ptr->print();
};

int main() {
	Test First;
	fun(&First);
}