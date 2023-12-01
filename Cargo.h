#pragma once

#include <iostream>
#include <string>
#include <iomanip>

#include "Vehicle.h"
#include "Route.h"

class Cargo {
protected:
	int cargo_type;
	int package_type;
	double cargo_params[4];
	double price;
public:
	Cargo();
	//Cargo(std::string, std::string, std::string);
	virtual void show();
	double getPrice();
};