#pragma once

#include <iostream>
#include <fstream>
#include <iomanip>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <map>
#include <ctime>

#include "Route.h"

using namespace std;

class RoutesList {
private:
	string PATH;
	string BACKUP_PATH;
	vector<Route> routes;
	map<int, string> locations;
public:
	RoutesList(string, string);
	~RoutesList();
	//DATABASE
	bool create();
	void printCountry();
	void printCity(int);
	bool remove(int);

	bool push();
	Route* read(string);
	bool pop(int);
	//update
	bool backup();
};