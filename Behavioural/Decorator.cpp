#include <iostream>
#include <vector>
#include <string>

class AbstractCoffee {
public:
	virtual int GetCost() = 0;
	virtual std::vector<std::string> GetIngredients() = 0;
};


class Coffee : public AbstractCoffee {
protected:
	int Cost;
	std::vector<std::string> Ingredients;
public:
	Coffee() {
		Ingredients.push_back("Coffee");
		Cost = 200;
	}

	int GetCost() {
		return Cost;
	}

	std::vector<std::string> GetIngredients() {
		return Ingredients;
	}
};

class ICoffeeDecorator : public Coffee {
protected:
	AbstractCoffee *DecoratedCoffee;
public:
	ICoffeeDecorator(AbstractCoffee *coffee) {
		DecoratedCoffee = coffee;
	}

	int GetCost()  {
		return DecoratedCoffee->GetCost();
	}

	std::vector<std::string> GetIngredients()  {
		return DecoratedCoffee->GetIngredients();
	}
};

class WithMilk : public ICoffeeDecorator {
public:
	WithMilk(AbstractCoffee *coffee) : ICoffeeDecorator(coffee) {
	}

	int GetCost() {
		return ICoffeeDecorator::GetCost() + 50;
	}

	std::vector<std::string> GetIngredients() {
		auto i = ICoffeeDecorator::GetIngredients();
		i.push_back("Milk");
		return i;
	}
};

class WithChocolate : public ICoffeeDecorator {
public:
	WithChocolate(AbstractCoffee *coffee) : ICoffeeDecorator(coffee) {
	}

	int GetCost() {
		return ICoffeeDecorator::GetCost() + 20;
	}

	std::vector<std::string> GetIngredients() {
		auto i = ICoffeeDecorator::GetIngredients();
		i.push_back("Chocolate");
		return i;
	}
};

class WithSugar : public ICoffeeDecorator {
public:
	WithSugar(AbstractCoffee *coffee) : ICoffeeDecorator(coffee) {
	}

	int GetCost() {
		return ICoffeeDecorator::GetCost() + 10;
	}

	std::vector<std::string> GetIngredients() {
		auto i = ICoffeeDecorator::GetIngredients();
		i.push_back("Sugar");
		return i;
	}
};

void Print(AbstractCoffee& c) {
	for (size_t i = 0; i < c.GetIngredients().size(); i++)
		std::cout << c.GetIngredients()[i] << ", ";
	std::cout << "(" << c.GetCost() << ")" << std::endl;
}

int main() {

	AbstractCoffee *c = new Coffee();
	Print(*c);
	
	c = new WithMilk(c);
	Print(*c);

	AbstractCoffee *complex = new WithSugar(new WithChocolate(new WithMilk(new Coffee())));
	Print(*complex);
}