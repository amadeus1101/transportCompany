#pragma once

#include <iostream>
#include <fstream>
#include <string>

#include "UsersHashMap.h"

class User
{
protected:
	//UsersHashMap* UDB;
	int user_id;
	std::string username;
	std::string password;
	std::string name;
	int status;
public:
	User(int, std::string, std::string, std::string, int);
	bool trackOrder();
	void show();
	virtual void menu();
	//virtual void showCompleted();
private:
	bool createCargo();
	//bool updateCargo();
	//void showProcessing();
};

