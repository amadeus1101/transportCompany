#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

#include "UsersHashMap.h"
#include "User.h"
#include "Employee.h"
#include "Manager.h"
#include "Admin.h"

class UsersHashMap;

class UAuthorized 
{
private:
	UsersHashMap *UObj;
	bool validate(std::string, std::string);
public:
	UAuthorized();
	bool authorization();
	//int authorization(int, std::string, std::string, std::string, int);
	bool registration();
	//PERMANENT
	void getAll();
};

