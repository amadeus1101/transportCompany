#pragma once

#include <iostream>
#include <string>
#include <iomanip>

#include "Vehicle.h"
#include "Route.h"

class Freight {
protected:
	int cargo_type;
	int package_type;
	double cargo_params[4];
	double price;
public:
	Freight();
	//Cargo(std::string, std::string, std::string);
	virtual void show();
	double getPrice();
};