#pragma once

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>

#include "Customer.h"

class Auth
{
protected:
	User* user;
	struct AuthUser
	{
		int _user_ID = -1;
		std::string _login = "";
		std::string _password = "";
		std::string _name = "";
		std::string _role = "USER";
	} UObj;
	std::vector<AuthUser> UVector;
public:
	void authMenu();
	bool authorization();
	bool registration();
};

