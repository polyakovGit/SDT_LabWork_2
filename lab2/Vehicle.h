#pragma once
#include <string>

class Vehicle;

class Node {
	Vehicle& vehicle;
	Node* next;
public:
	Node(Vehicle& vehicle, Node* next);

	Vehicle& GetVehicle();

	void SetNext(Node* next);

	Node* GetNext();
};

class Vehicle {
protected:
	std::string name;
public:
	static int count;
	static Node* head;
	static Node* tail;
	Vehicle(std::string name);
	virtual ~Vehicle();

	void Add();

	static void Print();

	virtual  void Show() const = 0;

	std::string GetName();

	void SetName(std::string name);
};