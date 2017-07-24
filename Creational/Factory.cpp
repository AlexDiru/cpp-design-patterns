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

class Dog : public IAnimal {
public:
	int GetNumberOfLegs() const override { return 4; }
	void Speak() const override { std::cout << "Woof" << std::endl; }
	static IAnimal* Create() { return new Dog(); }
};

class Fish : public IAnimal {
public:
	int GetNumberOfLegs() const override { return 0; }
	void Speak() const override { std::cout << "Glub" << std::endl; }
	static IAnimal* Create() { return new Fish(); }
};

//This is a singleton
class AnimalFactory {
private:

    std::map<std::string, std::function<IAnimal*()>> FactoryMap;

    AnimalFactory() { 
    	Register("Cat", &Cat::Create);
    	Register("Dog", &Dog::Create);
    	Register("Fish", &Fish::Create);
    };

    AnimalFactory(const AnimalFactory &) = delete;
    AnimalFactory &operator=(const AnimalFactory &) = delete;
public:
    ~AnimalFactory() { FactoryMap.clear(); }

    static AnimalFactory& GetInstance()
    {
        static AnimalFactory instance;
        return instance;
    }

    IAnimal *CreateAnimal(const std::string &animalName) {
    	auto iter = FactoryMap.find(animalName);
    	if (iter != FactoryMap.end())
    		return iter->second();
    	return nullptr;
    }

    void Register(const std::string &animalName, std::function<IAnimal*()> createFunction) {
    	FactoryMap[animalName] = createFunction;
    }
};

int main() {
	auto cat = AnimalFactory::GetInstance().CreateAnimal("Cat");
	cat->Speak();
	auto dog = AnimalFactory::GetInstance().CreateAnimal("Dog");
	dog->Speak();
	auto fish = AnimalFactory::GetInstance().CreateAnimal("Fish");
	fish->Speak();

	return 0;
}