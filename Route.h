#pragma once

#include <iostream>
#include <string>

class Route
{
protected:
	int route_id;
	int dep_id;
	int des_id;
	std::string departure;
	std::string destination;
public:
	Route(std::string, std::string);
	//~Route();
	//void show();
};

