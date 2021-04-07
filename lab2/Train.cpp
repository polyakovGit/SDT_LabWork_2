#include "Train.h"

Train::Train(std::string modelType, int capacity) : Vehicle(modelType) {
	this->capacity = capacity;
}

void Train::Show()const {
	std::cout << "Train: " << name << '\t' << capacity << '\n';
}
