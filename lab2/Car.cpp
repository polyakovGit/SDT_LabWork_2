#include "Car.h"

Car::Car(std::string modeltype, std::string engine) : Vehicle(modeltype) {
	this->engine = engine;
}

	void Car::Show()const {
		std::cout << "Car: " << name << '\t' << engine << '\n';
	}
