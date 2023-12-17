#pragma once

#include <iostream>
#include <string>
#include <iomanip>

#include "Vehicle.h"
#include "Route.h"

class Freight : public Route, public Vehicle {
protected:
	int freight_type, package_type;
	double capacity, weight;
	double price;
public:
	Freight();
	Freight(int);
	void show();
	bool valid(double, double, double);
	double getPrice();
	void getFreightList();
	void getPackageList();
	std::string getFreightName(int&);
	std::string getPackageName(int&);
};