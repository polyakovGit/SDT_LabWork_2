#include "Express.h"

Express::Express(std::string modelType, int capacity, int speed) : Train(modelType, capacity) {
	this->speed = speed;
}

void Express::Show()const {
	std::cout << "Express: " << name << '\t' << capacity << '\t' << speed << '\n';
}
