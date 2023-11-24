#pragma once

#include <iostream>
#include <fstream>
#include <string>

#include "UsersHashMap.h"
#include "Cargo.h"

class User
{
protected:
	int user_id;
	std::string username;
	std::string password;
	std::string name;
	int status;
	//HASH
	//UsersHashMap *UDB;
public:
	User(int, std::string, std::string, std::string, int);
	bool getTrack();
	void profile();
	virtual void menu();
	//virtual void showCompleted();
private:
	bool createCargo();
	//bool updateCargo();
	//void showProcessing();
};

