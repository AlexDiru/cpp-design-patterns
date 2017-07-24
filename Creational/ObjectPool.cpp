#include <iostream>
#include <array>
#include <string>

//This example does not actually use much memory, imagine it does
class HighMemoryObject {
	int LifeSpan = 5;
	std::string Data;
	bool InUse;
public:
	HighMemoryObject() {}
	void Initialise(const std::string& data) { Data = data; InUse = true; }
	bool IsInUse() { return InUse; }
	void Destroy() { InUse = false; }

	void Update() {
		LifeSpan--;
		if (LifeSpan == 0)
			Destroy();
	}
};

//I could template this class, but they look ugly
class ObjectPool {
	std::array<HighMemoryObject, 5> Pool;

public:
	ObjectPool() {
		Pool.fill(HighMemoryObject());
	}

	bool Create(const std::string& data) {
		for (size_t i = 0; i < Pool.size(); i++) {
			if (!Pool[i].IsInUse()) {
				Pool[i].Initialise(data);
				std::cout << "Creating object in Pool[" << i << "]" << std::endl;
				return true;
			}
		}

		std::cout << "Error: No free space" << std::endl;
		return false;
	}


	void UpdateAll() {
		for (size_t i = 0; i < Pool.size(); i++) 
			if (Pool[i].IsInUse())
				Pool[i].Update();
	}
};

int main() {
	ObjectPool pool;
	pool.Create("Hello");
	pool.Create("Hello");
	pool.UpdateAll();
	pool.Create("Hello");
	pool.UpdateAll();
	pool.Create("Hello");
	pool.UpdateAll();
	pool.Create("Hello");
	pool.UpdateAll();
	pool.Create("Hello");
	pool.UpdateAll();
	pool.Create("Hello");
	pool.UpdateAll();
	pool.Create("Hello");
	pool.UpdateAll();
	pool.Create("Hello");

	return 0;
}