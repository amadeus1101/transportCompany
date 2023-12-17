#pragma once

#include <iostream>
#include <fstream>
#include <string>

#include "Manager.h"

class Admin : public Manager
{
private:
	//UsersList* usersdb;
public:
	Admin(int, std::string, std::string, std::string, int);
	void menu() override;
	//void showCompleted() override;
};

