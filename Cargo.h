#pragma once

#include <iostream>
#include <string>

class Cargo
{
protected:
	double length;
	double width;
	double height;
	double weight;

	std::string cargo_type;
	std::string departure;
	std::string destination;
	std::string vehicle_type;

public:
	Cargo();
	Cargo(double, double, double, double, std::string, std::string, std::string, std::string);

	void showCargo();
	void updateCargo();
	bool checkParams();
	bool checkRoute();
	double countPrice();
};

