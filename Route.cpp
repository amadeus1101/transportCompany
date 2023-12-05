#include "Route.h"

Route::Route()
{
	int chc;
	std::cout << "Departure country: " << std::endl;
	for (int i = 0; i < len_i; i++)
	{
		std::cout << i << ". " << countries[i] << std::endl;
	}
	std::cin >> dep_code;
	while (!valid(dep_code, 0, len_i))
		std::cin >> dep_code;
	
	std::cout << "Departure city: " << std::endl;
	for (int j = 0; j < len_j; j++)
	{
		std::cout << j << ". " << cities[dep_code][j] << std::endl;
	}
	std::cin >> chc;
	while (!valid(chc, 0, len_j))
		std::cin >> chc;
	dep_code *= 1000;
	dep_code += chc;

	std::cout << "Destination country: " << std::endl;
	for (int i = 0; i < len_i; i++)
	{
		std::cout << i << ". " << countries[i] << std::endl;
	}
	std::cin >> des_code;
	while (!valid(des_code, 0, len_i))
		std::cin >> des_code;

	std::cout << "Destination city: " << std::endl;
	for (int j = 0; j < len_j; j++)
	{
		std::cout << j << ". " << cities[des_code][j] << std::endl;
	}
	std::cin >> chc;
	while (!valid(chc, 0, len_j))
		std::cin >> chc;
	des_code *= 1000;
	des_code += chc;
}

void Route::show() {
	std::cout << "Route: " << std::endl;
	std::cout << "FROM: " << getCityName(dep_code) << " [" << getCountryName(dep_code) << "] - #" << dep_code << std::endl;
	std::cout << "TO: " << getCityName(des_code) << " [" << getCountryName(des_code) << "] - #" << des_code << std::endl;
}

bool Route::valid(int &val, int begin, int end) {
	if (val < begin || val > end - 1)
	{
		std::cout << "The number is incorrect, try again" << std::endl;
		return false;
	}
	return true;
}

std::string Route::getCountryName(int &val) {
	return countries[val / 1000];
}

std::string Route::getCityName(int& val) {
	return cities[val / 1000][val % 1000];
}