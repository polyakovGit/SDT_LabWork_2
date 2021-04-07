#pragma once

#include <iostream>
#include "Vehicle.h"

class Car : public Vehicle {
	std::string engine;
public:
	Car(std::string modeltype, std::string engine);

	void Show()const;
};
