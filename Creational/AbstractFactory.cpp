//Modfied from https://www.codeproject.com/Articles/363338/Factory-Pattern-in-Cplusplus
#include <iostream>
#include <string>
#include <map>


class IAnimal
{
public:
    virtual int GetNumberOfLegs() const = 0;
    virtual void Speak() const = 0;
}; 

class Cat : public IAnimal {
public:
	int GetNumberOfLegs() const override { return 4; }
	void Speak() const override { std::cout << "Meow" << std::endl; }
	static IAnimal* Create() { return new Cat(); }
};

class Panda : public IAnimal {
public:
	int GetNumberOfLegs() const override { return 4; }
	void Speak() const override { std::cout << "Chomp" << std::endl; }
	static IAnimal* Create() { return new Panda(); }
};

class Spider : public IAnimal {
public:
	int GetNumberOfLegs() const override { return 8; }
	void Speak() const override { std::cout << "I'm going to eat your soul" << std::endl; }
	static IAnimal* Create() { return new Spider(); }
};

class Bear : public IAnimal {
public:
	int GetNumberOfLegs() const override { return 4; }
	void Speak() const override { std::cout << "Roar" << std::endl; }
	static IAnimal* Create() { return new Bear(); }
};

class IFactory {
public:
	virtual IAnimal* CreateSmallAnimal() const = 0;
	virtual IAnimal* CreateBigAnimal() const = 0;
	virtual ~IFactory() {}
};

class ScaryAnimalFactory : public IFactory {
public:
	IAnimal* CreateSmallAnimal() const override { return new Spider; }
	IAnimal* CreateBigAnimal() const override { return new Bear;}
	~ScaryAnimalFactory() override {}
};

class FriendlyAnimalFactory : public IFactory {
public:
	IAnimal* CreateSmallAnimal() const override { return new Cat; }
	IAnimal* CreateBigAnimal() const override { return new Bear; }
	~FriendlyAnimalFactory() override {}
};

#define SCARY 1

int main() {
	#ifdef SCARY
		IFactory *factory = new ScaryAnimalFactory();
	#else
		IFactory *factory = new FriendlyAnimalFactory();
	#endif

	factory->CreateSmallAnimal()->Speak();
	factory->CreateBigAnimal()->Speak();

	delete factory;

	return 0;
}