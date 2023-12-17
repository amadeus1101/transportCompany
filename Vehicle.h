#pragma once

#include <iostream>
#include <string>

class Vehicle
{
protected:
	int vehicle_type;
public:
	Vehicle();
	std::string getVehicleName();
	void getVicList();
};

