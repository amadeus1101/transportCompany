#pragma once

#include <iostream>
#include <fstream>
#include <string>

class User
{
protected:
	int user_id;
	std::string username;
	std::string password;
	std::string name;
	int status;
	//int* orders_history = new int[10];
	//int* orders_processing = new int[10];
public:
	User(int, std::string, std::string, std::string, int);
	//virtual void menu();
	int getStatus();
	void show();
	bool setStatus(int);
	bool getAccess(std::string, std::string);
	
	//~Customer() { delete[]orders_history; delete[]orders_processing; }
};

