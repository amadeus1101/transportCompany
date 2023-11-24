#include "Vehicle.h"

Vehicle::Vehicle(std::string _vehicleType)
{
	vehicle_id = -1;
	vehicle_type = _vehicleType;

	if (vehicle_type == "TRUCK")
		vehicle_id = 0;
	if (vehicle_type == "TRAIN")
		vehicle_id = 1;
	if (vehicle_type == "SHIP")
		vehicle_id = 2;
	if (vehicle_type == "PLANE")
		vehicle_id = 3;
}

//void Vehicle::show() {
//	std::cout << "VEHICLE: " << std::endl;
//	std::cout << vehicle_id << "   " << vehicle_type << std::endl;
//}
