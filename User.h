#pragma once

#include <string>

#include "ApplicationList.h"
#include "OrderList.h"
#include "UserList.h"

class User
{
protected:
	int user_ID;
	std::string login;
	std::string password;
	std::string name;
	std::string role;
public:
	virtual void show() = 0;
	virtual void menu() = 0;
};