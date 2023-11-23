#pragma once

#include <iostream>
#include <fstream>
#include <string>

#include "Employee.h"

class Manager : public Employee
{
public:
	Manager(int, std::string, std::string, std::string, int);
	void menu() override;
	//void showCompleted() override;
};

