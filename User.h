#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

#include "Freight.h"

class User
{
protected:
	char username[11];
	char password[11];
	char first_name[21];
	char last_name[21];
	int status;
	//HASH
	//UsersHashMap *UDB;
public:
	User();
	User(std::string&);
	//bool getTrack();
	void profile();
	virtual void menu();
	//virtual void showCompleted();
private:
	bool createFreight();
	//bool updateCargo();
	//void showProcessing();
};

