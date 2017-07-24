#include <iostream>

class AbstractObject {
public:
	virtual void Compute() const = 0;
	virtual ~AbstractObject() {}
};

class Object : public AbstractObject {
	void Compute() const override { std::cout << "Computing..." << std::endl << "Done!" << std::endl; }
};

class NullObject : public AbstractObject {
	void Compute() const override {}
};

void Run(const AbstractObject& object) {
	object.Compute();
}

int main() {
	AbstractObject *object = new Object();
	Run(*object);
	delete object;

	object = new NullObject();
	Run(*object);
	delete object;

	return 0;
}