#include "Vehicle.h"

Vehicle::Vehicle()
{
	std::cout << "Choose preferred vehicle: " << std::endl;
	for (int i = 0; i < vic_arr_len; i++)
	{
		std::cout << i << ". " << vic_arr[i] << std::endl;
	}
	std::cin >> vehicle_type;

	while (vehicle_type < 0 || vehicle_type > vic_arr_len - 1)
	{
		std::cout << "Vehicle is incorrect, try again" << std::endl;
		std::cin >> vehicle_type;
	}

	vehicle = vic_arr[vehicle_type];
}

//void Vehicle::show() {
//	std::cout << "VEHICLE: " << std::endl;
//	std::cout << vehicle_id << "   " << vehicle_type << std::endl;
//}
