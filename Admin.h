#pragma once

#include <iostream>
#include <fstream>
#include <string>

#include "Manager.h"

class Admin : public Manager
{
public:
	Admin(int, std::string, std::string, std::string, int);
	void menu() override;
	//void showCompleted() override;
};

