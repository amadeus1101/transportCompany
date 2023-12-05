#pragma once

#include <iostream>
#include <string>
#include <iomanip>

#include "Vehicle.h"
#include "Route.h"

class Freight : public Route, public Vehicle {
protected:
	int freight_type, package_type;
	int len, wid, hei;
	double wei;
	double price;
	std::string freight, package;
public:
	Freight();
	//Cargo(std::string, std::string, std::string);
	void show() override;
	double getPrice();
private:
	const int fr_types_len = 6, pc_types_len = 4;
	std::string fr_types[6] = { "Glass", "Furniture", "Exterior", "Stone/Granite", "Metal", "Etc" };
	std::string pc_types[4] = { "Paper", "Wooden", "Plastic", "Polymeric" };
};