#pragma once

#include <iostream>
#include <fstream>
#include <string>

#include "UsersHashMap.h"
#include "User.h"

class UsersHashMap;

class UAuthorized 
{
private:
	UsersHashMap *UObj;
	bool validate(std::string, std::string);
public:
	UAuthorized();
	int authorization();
	//int authorization(int, std::string, std::string, std::string, int);
	bool registration();
};

