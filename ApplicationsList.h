#pragma once

#include <iostream>
#include <fstream>
#include <iomanip>
#include <stdlib.h>
#include <stdio.h>
#include <map>
#include <ctime>

#include "Application.h"

using namespace std;

class ApplicationsList {
private:
	string PATH;
	string BACKUP_PATH;
	fstream* file;
	map<string, string> applications;
public:
	ApplicationsList(string, string);
	~ApplicationsList();
	//DATABASE
	bool create(string);
	Application* read(string);
	void print(string);
	void print();
	//update
	bool remove(string);
	bool backup();
};