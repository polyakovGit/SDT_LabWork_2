#pragma once

#include "Train.h"

class Express :public Train {
	int speed;
public:
	Express(std::string modelType, int capacity, int speed);

	void Show()const;
};