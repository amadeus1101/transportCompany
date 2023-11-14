#pragma once

#include <string>

#include "Menu.h"
#include "User.h"
#include "UsersList.h"
#include "ApplicationsList.h"
#include "CargoList.h"

class Employee : public User, public UsersList, public ApplicationsList, public CargoList, public Menu
{
public:
	//stack UsersOrdersInProcess file OrdersInProcess
	//override show profile
	//override menu
	//override logout
	//override change password
	//peregruzka/perenaznach ot roditelei
	
};
