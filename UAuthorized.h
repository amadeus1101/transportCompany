#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

#include "UsersList.h"
#include "Cargo.h"
#include "User.h"
#include "Employee.h"
#include "Manager.h"
#include "Admin.h"

class UAuthorized 
{
private:
	UsersList*UObj;
	bool validate(std::string, std::string);
public:
	UAuthorized();
	bool authorization();
	//int authorization(int, std::string, std::string, std::string, int);
	bool registration();
	bool createCargo();
	//PERMANENT
	void getAll();
};

