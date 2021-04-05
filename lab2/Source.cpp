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
public:
	Car(std::string modeltype) : Vehicle(modeltype) {}
	void Show()const override{
		std::cout << name<< "\n";
	}
};

int main() {
	Car obj("test");
	obj.Add();
	Car obj2("test2");
	Vehicle::Print();
	return 0;
}