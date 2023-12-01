#pragma once

#include <iostream>
#include <string>

class Vehicle
{
protected:
	int vehicle_id;
	std::string vehicle_type;
public:
	Vehicle();
	Vehicle(std::string);
	//~Vehicle();
	//void show();
};

