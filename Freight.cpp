#include "Freight.h"

Freight::Freight(int _num) {
	const int bufSize = 75;
	price = 0;

	std::cout << std::setw(bufSize / 2 - 2) << std::setfill('-') << "-" << std::endl;
	std::cout << std::setw(bufSize / 2 - 12) << std::setfill(' ') << " F R E I G H T " << std::endl;
	std::cout << std::setw(bufSize / 2 - 2) << std::setfill('-') << "-" << std::endl;

	std::cout << std::endl << "Capacity (cm3): ";
	std::cin >> capacity;
	while (!valid(capacity, 1, 201))
		std::cin >> capacity;

	std::cout << std::endl << "Weight (kg): ";
	std::cin >> weight;
	while (!valid(weight, 0.1, 51))
		std::cin >> weight;

	std::cout << std::endl << "Freight type: " << std::endl;
	getFreightList();
	std::cin >> freight_type;
	while (!valid(freight_type, 0, 6))
		std::cin >> freight_type;

	std::cout << std::endl << "Package type: " << std::endl;
	getPackageList();
	std::cin >> package_type;
	while (!valid(package_type, 0, 4))
		std::cin >> package_type;

	int chc;
	int len_i = 4;
	int len_j = 4;
	std::cout << "Departure country: " << std::endl;
	getCountries();
	std::cin >> dep_code;
	while (!valid(dep_code, 0, len_i))
		std::cin >> dep_code;

	std::cout << "Departure city: " << std::endl;
	getCities(dep_code);
	std::cin >> chc;
	while (!valid(chc, 1, len_j))
		std::cin >> chc;
	dep_code *= 1000;
	dep_code += chc;

	std::cout << "Destination country: " << std::endl;
	getCountries();
	std::cin >> des_code;
	while (!valid(des_code, 0, len_i))
		std::cin >> des_code;

	std::cout << "Destination city: " << std::endl;
	getCities(des_code);
	std::cin >> chc;
	while (!valid(chc, 1, len_j))
		std::cin >> chc;
	des_code *= 1000;
	des_code += chc;

	std::cout << std::endl << "Transport type: " << std::endl;
	getVicList();
	std::cin >> vehicle_type;
	while (!valid(vehicle_type, 0, 4))
		std::cin >> vehicle_type;
}

Freight::Freight()
{
	freight_type = -1;
	package_type = -1;
	capacity = 0;
	weight = 0;
	price = 0;
}

void Freight::show() {
	//system("CLS");
	const int bufSize = 75;

	std::cout << std::setw(bufSize) << std::setfill('-') << "-" << std::endl;
	std::cout << "| " << std::setw(bufSize / 2 - 2) << std::setfill(' ') << " F R E I G H T ";
	std::cout << std::setw((bufSize - 14) / 2 - 1) << std::setfill(' ') << " |" << std::endl;
	std::cout << std::setw(bufSize) << std::setfill('-') << "-" << std::endl;

	std::cout << "| Params: " << std::setw(bufSize - 16) << std::setfill('.') << capacity << " cm3 |" << std::endl;
	std::cout << "| Weigth: " << std::setw(bufSize - 15) << std::setfill('.') << weight << " kg |" << std::endl;
	std::cout << "| Cargo type: " << std::setw(bufSize - 4 - 12) << std::setfill('.') << getFreightName(freight_type) << " |" << std::endl;
	std::cout << "| Package type: " << std::setw(bufSize - 4 - 14) << std::setfill('.') << getPackageName(package_type) << " |" << std::endl;
	std::cout << "| " << getCityName(dep_code) << " [" << getCountryName(dep_code) << "] --> " << getCityName(des_code) << " [" << getCountryName(des_code) << "]   BY   { " << getVehicleName() << " }" << std::endl;

	std::cout << std::setw(bufSize) << std::setfill('-') << "-" << std::endl;
	std::cout << "| T O T A L  P R I C E : " << std::setw(bufSize - 9 - 21) << std::setfill('.') << getPrice() << " $ |" << std::endl;
	std::cout << std::setw(bufSize) << std::setfill('-') << "-" << std::endl;
}

double Freight::getPrice() {
	return capacity / (weight * 100) + freight_type * package_type;
}

bool Freight::valid(double val, double begin, double end) {
	if (val < begin || val >= end) {
		std::cout << "The value should be correct in range from " << begin << " to " << end - 1 << std::endl;
		return false;
	}
	return true;
}

void Freight::getFreightList() {
	std::string fr_types[6] = { "Glass", "Furniture", "Exterior", "Stone/Granite", "Metal", "Etc" };
	for (int i = 0; i < 6; i++)
		std::cout << i << ". " << fr_types[i] << std::endl;
}

void Freight::getPackageList() {
	std::string pc_types[4] = { "Paper", "Wooden", "Plastic", "Polymeric" };
	for (int i = 0; i < 4; i++)
		std::cout << i << ". " << pc_types[i] << std::endl;
}

std::string Freight::getFreightName(int &_id) {
	std::string fr_types[6] = { "Glass", "Furniture", "Exterior", "Stone/Granite", "Metal", "Etc" };
	if(_id >= 0) return fr_types[_id];
	return "Undefined";
}

std::string Freight::getPackageName(int &_id) {
	std::string pc_types[4] = { "Paper", "Wooden", "Plastic", "Polymeric" };
	if(_id >= 0) return pc_types[_id];
	return "Undefined";
}