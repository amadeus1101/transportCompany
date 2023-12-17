#pragma once

#include <iostream>
#include <fstream>
#include <string>

class User
{
protected:
	std::string username;
	std::string password;
	std::string first_name;
	std::string last_name;
	int status;
	int user_id;
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

