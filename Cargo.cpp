#include "Cargo.h"

Cargo::Cargo() {
	length = 0;
	width = 0;
	height = 0;
	weight = 0;
};

Cargo::Cargo(double _length, double _width, double _height, double _weight, std::string _cargo_type, std::string _departure, std::string _destination, std::string _vehicle_type) {
	length = _length;
	width = _width;
	height = _height;
	weight = _weight;

	cargo_type = _cargo_type;
	departure = _departure;
	destination = _destination;
	vehicle_type = _vehicle_type;
}

bool Cargo::checkParams() {
	if (length > 2 || width > 2 || height > 2)
	{
		std::cout << "We are sorry, but basic cargo should be less then 2 metres in every projection;(" << std::endl;
		return false;
	}
	return true;
}

bool Cargo::checkRoute() {
	std::cout << "checking routes and vehicles FILE///" << std::endl;
	return false;
}

double Cargo::countPrice() {
	//SOME KOEFFICIENT BY ROUTES
	return (length + width + height) * weight * 0.1;
}

void Cargo::showCargo() {
	std::cout << "V  weight TYPE FROM TO VEHICLE" << std::endl;
	std::cout << length * width * height << " " << weight << " " << cargo_type << " " << departure << " " << destination << " " << vehicle_type << std::endl;
}