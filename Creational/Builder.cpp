//Adapted from https://en.wikipedia.org/wiki/Builder_pattern
#include <string>
#include <iostream>

class Car {
	int Wheels;
	std::string Colour;
	std::string Brand;

public:
	Car(int wheels, const std::string& colour, const std::string& brand) {
		Wheels = wheels;
		Colour = colour;
		Brand = brand;
	}

	void Print() {
		std::cout << "Wheels: " << Wheels << " | Colour: " << Colour << " | Brand: " << Brand << std::endl;
	}
};

class Builder {
	int Wheels = 4;
	std::string Colour = "Red";
	std::string Brand = "Ford";
public:
	Builder& SetWheels(int wheels) { Wheels = wheels; return *this; }
	Builder& SetColour(const std::string& colour) { Colour = colour; return *this; }
	Builder& SetBrand(const std::string& brand) { Brand = brand; return *this; }

	Car Build() { return Car(Wheels, Colour, Brand); }

};

int main() {
	Builder builder;
	builder.Build().Print();

	builder.SetWheels(3).SetColour("Blue").SetBrand("Lexus");
	auto car = builder.Build();
	car.Print();

	return 0;
}