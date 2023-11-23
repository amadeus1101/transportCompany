#pragma once

#include <iostream>
#include <fstream>
#include <string>

#include "User.h"

class Employee : public User
{
public:
	Employee(int, std::string, std::string, std::string, int);
	void menu() override;
	//void showCompleted() override;
};

