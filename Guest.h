#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

#include "UsersDB.h"
#include "User.h"
#include "Employee.h"
#include "Manager.h"
#include "Admin.h"

class Guest 
{
private:
	bool validate(std::string, std::string);
public:
	Guest();
	bool authorization();
	//int authorization(int, std::string, std::string, std::string, int);
	bool registration();
	bool createCargo();
	//PERMANENT
	void getAll();
};

