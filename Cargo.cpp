#include "Cargo.h"

Cargo::Cargo(double _capacity, double _weight, std::string _vehicle, std::string _from, std::string _to) : 
	Vehicle::Vehicle(_vehicle), Route::Route(_from, _to)
{
	capacity = _capacity;
	weight = _weight;
	price = 0;
}

void Cargo::show() {
	std::cout << "CARGO: " << std::endl;
	std::cout << "**CAP**" << "**WEI**" << "**VIC**" << "**FROM*" << "***TO**" << std::endl;
	std::cout << capacity << "  " << weight << "  " << vehicle_type << "  " << departure << "  " << destination << std::endl;
}