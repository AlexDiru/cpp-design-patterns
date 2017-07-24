#include <iostream>

class Number {

	class Memento {
		int Value;
	public:
		Memento(int value) { Value = value; }
		friend class Number;
	};

	int Value;

public:
	Number(int value) { Value = value; }

	Memento SaveState() {
		return Memento(Value);
	}

	void LoadState(const Memento& m) {
		Value = m.Value;
	}

	Number& Double() {
		Value *= 2;
		return *this;
	}

	Number& Add() {
		Value += 1;
		return *this;
	}

	void Print() {
		std::cout << Value << std::endl;
	}
};

int main() {

	Number number(3);
	auto save1 = number.SaveState();
	number.Print();
	number.Double();
	number.Add();
	number.Print();
	auto save2 = number.SaveState();
	number.LoadState(save1);
	number.Print();
	number.LoadState(save2);
	number.Print();

	return 0;
}