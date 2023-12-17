#pragma once

#include <iostream>
#include <string>

class Route
{
protected:
	int dep_code;
	int des_code;
public:
	Route();
	Route(int, int);
	void getCountries();
	void getCities(int&);
	std::string getCountryName(int&);
	std::string getCityName(int&);
private:
	int len_i = 4;
	int len_j = 4;
};

