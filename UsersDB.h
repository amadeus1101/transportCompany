#pragma once

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <fstream>
#include <iomanip>

#include <stdlib.h>
#include <stdio.h>
#include <ctime>
#include <algorithm>

#include "HashTable.h"

class UsersDB {
private:
	std::string alphabet = "abcdefghijklmnopqrstuvwxyz0123456789";
public:
	UsersDB(std::string, std::string, std::string);
	~UsersDB();
	//Hash


	//DATABASE
	bool validate(std::string, std::string);
	std::string autharization();
	bool registration();

	bool create(const char*, const char*, const char*, const char*, int);
	void read();
	void read(std::string);
	bool remove(std::string);
	bool backup();
};