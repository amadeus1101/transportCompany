#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

#include "UsersDB.h"

class Guest 
{
private:
	UsersDB UDB{"/db/_users/", "uconfig.dat", "/db/backups/_users/"};
	//Guest();
	bool authorization();
	bool registration();
	bool createCargo();
	bool validate(std::string, std::string);
public:
	//void menu();
};

