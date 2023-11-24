#pragma once

#include <iostream>
#include <string>

#include "Vehicle.h"
#include "Route.h"

class Cargo : public Vehicle, public Route {
protected:
	double capacity;
	double weight;
	double price;
public:
	Cargo(double, double, std::string, std::string, std::string);
	virtual void show();
};