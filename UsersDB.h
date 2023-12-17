#pragma once

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <fstream>
#include <iomanip>

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "HashTable.h"


class UsersDB : public HashTable {
public:
	UsersDB(std::string, std::string, std::string);
	~UsersDB();
	//DATABASE
	bool create(std::string, std::string, std::string, std::string, int);
	void read();
	void read(std::string);
	bool update(std::string);
	bool remove(std::string);
	bool backup();
;};