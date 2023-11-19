#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <fstream>
#include <string>

#include "User.h"
#include "Cargo.h"

class Customer : public User
{
protected:
	//int* orders_history = new int[10];
	//int* orders_processing = new int[10];
public:
	Customer();
	Customer(int, std::string, std::string, std::string, std::string);
	void createCargo();
	void createApplication();
	//~Customer() { delete[]orders_history; delete[]orders_processing; }
	void show() override;
	void menu() override;
	
};

