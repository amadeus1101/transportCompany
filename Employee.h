#pragma once

#include <iostream>

#include "User.h"

class Employee : public User
{
	Employee();
	Employee(int, std::string, std::string, std::string, std::string);
	//~Employee() { delete[]orders_history; delete[]orders_processing; }
	void show() override;
	void menu() override;
};

