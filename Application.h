#pragma once
#include <string>
#include "Customer.h"
#include "Cargo.h"
#include "Vehicle.h"
#include "Route.h"


class Application : public Customer, public Cargo, public Vehicle, public Route
{
protected:
	std::string manager_ID;
	bool application_status;
};