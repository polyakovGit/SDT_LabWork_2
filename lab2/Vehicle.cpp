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
Node* Vehicle::begin;
Node* Vehicle::end;

Vehicle::Vehicle(std::string name) {
	this->name = name;
	Add();
}
Vehicle::~Vehicle() {
	while (begin) {
		Node* temp = begin;
		begin = begin->GetNext();
		delete temp;
		/*std::cout << '\n' << Vehicle::count;*/
	}
	begin = end = NULL;
	count = 0;
}

void Vehicle::Add() {
	if (!begin) {
		begin = end = new Node(*this);
		++count;
	}
	else {
		end->SetNext(new Node(*this));
		end = end->GetNext();
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
	Node* temp = begin;
	while (temp) {
		temp->GetVehicle().Show();
		temp = temp->GetNext();
	}
}