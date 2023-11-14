#pragma once

#include <string>

#include "Menu.h"
#include "User.h"
#include "ApplicationsList.h"
#include "CargoList.h"

class Customer : public User, public ApplicationsList, public CargoList, public Menu
{
public:
	//stack MYordersInProcess
	//stack MYordersCompleted
	//override show profile
	//override menu
	//override logout
	//override change password
	//peregruz+perenaznach roditelei
	
};