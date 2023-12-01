#pragma once

#include <iostream>
#include <string>

class Route
{
protected:
	int route_id;
	int dep_code;
	int des_code;
	std::string dep_country;
	std::string dep_city;
	std::string des_country;
	std::string des_city;
public:
	Route();
	Route(std::string, std::string);
	//~Route();
	//void show();
};

