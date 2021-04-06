#include <iostream>
#include <string>

class Vehicle;

class Node {
	Vehicle& vehicle;
	Node* next;
public:
	Node(Vehicle& vehicle, Node* next = nullptr) : vehicle(vehicle), next(next) {}

	Vehicle& GetVehicle() {
		return vehicle;
	}

	void SetNext(Node* next) {
		this->next = next;
	}

	Node* GetNext() {
		return next;
	}
};

class Vehicle {
protected:
	std::string name;
public:
	static int count;
	static Node* head;
	static Node* tail;
	Vehicle(std::string name) {
		this->name = name;
		Add();
	}
	virtual ~Vehicle() {
		while (head) {
			Node* temp = head;
			head = head->GetNext();
			temp->GetVehicle().Show();
			delete temp;
		}
	}
	void Add() {
		if (!head) {
			head = tail = new Node(*this);
			++count;
		}
		else {
			tail->SetNext(new Node(*this));
			tail = tail->GetNext();
			++count;
		}
	}

	static void Print();

	virtual  void Show() const = 0;

	std::string GetName() {
		return this->name;
	}

	void SetName(std::string name) {
		this->name = name;
	}
};

int Vehicle::count;
Node* Vehicle::head;
Node* Vehicle::tail;

void Vehicle::Print() {
	Node* temp = head;
	while (temp) {
		temp->GetVehicle().Show();
		temp = temp->GetNext();
	}
}

class Car : public Vehicle {
	std::string engine;
public:
	Car(std::string modeltype, std::string engine) : Vehicle(modeltype) {
		this->engine = engine;
	}

	void Show()const {
		std::cout << "Car: " << name << '\t' << engine << '\n';
	}
};

class Train :public Vehicle {
protected:
	int capacity;
public:
	Train(std::string modelType, int capacity) : Vehicle(modelType) {
		this->capacity = capacity;
	}

	void Show()const {
		std::cout << "Train: " << name << '\t' << capacity << '\n';
	}
};

class Express :public Train {
	int speed;
public:
	Express(std::string modelType, int capacity, int speed) : Train(modelType, capacity) {
		this->speed = speed;
	}

	void Show()const {
		std::cout <<"Express: " << name << '\t' << capacity << '\t' << speed<<'\n';
	}
};

int main() {
	//Car obj0("test0", "eng0");
	//obj0.Add();
	Car obj1("test1", "eng1");
	Train obj2("test2", 15);
	//obj2.Add();
	Express obj3("Test3", 20, 400);
	//Car obj4("test4", "eng4");
	//Vehicle::Print();
	return 0;
}