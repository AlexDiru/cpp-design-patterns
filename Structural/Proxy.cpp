//Modified from https://en.wikipedia.org/wiki/Proxy_pattern#C.2B.2B

#include <iostream>


class AbstractCar {
public:
	virtual void Drive() = 0;
};

class ProtectedCar : public AbstractCar {
public:
	void Drive() override { std::cout << "Drive!" << std::endl; }
};

class ProxyCar : public AbstractCar {
	ProtectedCar RealCar;
	int DriverAge;
public:
	ProxyCar(int age) { DriverAge = age; }

	void Drive() override {
		if (DriverAge >= 17)
			RealCar.Drive();
		else
			std::cout << "Too young to drive" << std::endl;
	}
};

int main() {
	ProxyCar car(16);
	car.Drive();

	ProxyCar car2(18);
	car2.Drive();
}