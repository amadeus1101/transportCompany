#pragma once

#include <iostream>
#include <string>

class Vehicle
{
protected:
	int vehicle_type;
	std::string vehicle;
public:
	Vehicle();
	//~Vehicle();
	//void show();
private:
	const int vic_arr_len = 4;
	std::string vic_arr[4] = { "Train", "Truck", "Ship", "Plane" };
};

