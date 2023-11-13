#pragma once
#include <string>
#include "RoutesList.h"

class Route : public RoutesList
{
protected:
	std::string departure;
	std::string destination;
	double route_price;
};