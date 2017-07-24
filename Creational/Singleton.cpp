#include <iostream>


class Singleton {

private:
	Singleton() {}
	int Count {0};

public:
	Singleton(const Singleton&) = delete;
	void operator=(const Singleton&) = delete;	

	static Singleton& GetInstance() {
		static Singleton singleton;
		return singleton;
	}

	void IncreaseCount() {
		Count++;
	}

	void DecreaseCount() {
		Count--;
	}

	int GetCount() {
		return Count;
	}

	void Log() {
		std::cout << "Count: " << Count << std::endl;
	}
};

void Foo() {
	Singleton::GetInstance().IncreaseCount();
}

int main() {
	Singleton::GetInstance().Log();
	Singleton::GetInstance().IncreaseCount();
	Singleton::GetInstance().Log();
	Foo();
	Singleton::GetInstance().Log();
}