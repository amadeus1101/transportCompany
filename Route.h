#pragma once

#include <iostream>
#include <string>

class Route
{
protected:
	int dep_code;
	int des_code;
	int route_ratio;
public:
	Route();
	Route(int, int, int);
	void getCountries();
	void getCities(int&);
	std::string getCountryName(int&);
	std::string getCityName(int&);
};

