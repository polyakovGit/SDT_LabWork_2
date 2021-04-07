#pragma once

#include "Vehicle.h"

class Train :public Vehicle {
protected:
	int capacity;
public:
	Train(std::string modelType, int capacity);

	void Show()const;
};