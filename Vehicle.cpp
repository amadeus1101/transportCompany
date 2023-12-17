#include "Vehicle.h"

Vehicle::Vehicle() {
	vehicle_type = -1;
}

std::string Vehicle::getVehicleName() {
	std::string vic_arr[4] = { "Train", "Truck", "Ship", "Plane" };
	if(vehicle_type >= 0) return vic_arr[vehicle_type];
	return "Undefined";
}

void Vehicle::getVicList() {
	const int vic_arr_len = 4;
	std::string vic_arr[4] = { "Train", "Truck", "Ship", "Plane" };
	for (int i = 0; i < vic_arr_len; i++)
		std::cout << i << ". " << vic_arr[i] << std::endl;
}
