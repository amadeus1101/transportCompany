#pragma once

#include <iostream>
#include <string>

#include "Cargo.h"

class Application : public Cargo {
protected:
	int app_id;
	int user_id;
	int employee_id;
	bool app_status;
	std::string user_name;
	std::string user_contact;
	std::string employee_name;
public:
	Application(double, double, std::string, std::string, std::string, std::string, std::string);
	void show() override;
};
