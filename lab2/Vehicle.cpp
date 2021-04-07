#include <string>
#include "Vehicle.h"

	Node::Node(Vehicle& vehicle, Node* next = nullptr) : vehicle(vehicle), next(next) {}

	Vehicle& Node::GetVehicle() {
		return vehicle;
	}

	void Node::SetNext(Node* next) {
		this->next = next;
	}

	Node* Node::GetNext() {
		return next;
	}


	int Vehicle::count;
	Node* Vehicle::head;
	Node* Vehicle::tail;

	Vehicle::Vehicle(std::string name) {
		this->name = name;
		Add();
	}
	Vehicle::~Vehicle() {
		while (head) {
			Node* temp = head;
			head = head->GetNext();
			--count;
			delete temp;
			/*std::cout << '\n' << Vehicle::count;*/
		}
	}
	void Vehicle::Add() {
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

	std::string Vehicle::GetName() {
		return this->name;
	}

	void Vehicle::SetName(std::string name) {
		this->name = name;
	}

	void Vehicle::Print() {
		Node* temp = head;
		while (temp) {
			temp->GetVehicle().Show();
			temp = temp->GetNext();
		}
	}