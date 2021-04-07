#include <iostream>
#include "Car.h"
#include "Train.h"
#include "Express.h"


int main() {
	Car obj0("test0", "eng0");
	obj0.Add();
	Car obj1("test1", "eng1");
	Train obj2("test2", 15);
	obj2.Add();
	Express* obj3=new Express("Test3", 20, 400);
	Car obj4("test4", "eng4");
	obj3->Add();
	
	Vehicle::Print();
	return 0;
}