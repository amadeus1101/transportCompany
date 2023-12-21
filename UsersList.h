#pragma once

#include <iostream>
#include <fstream>
#include <iomanip>

#include <stdlib.h>
#include <stdio.h>
#include <ctime>
#include <algorithm>
#include <map>

using namespace std;

class UsersList {
private:
	string alphabet = "abcdefghijklmnopqrstuvwxyz0123456789";
	string PATH;
	string BACKUP_PATH;
	fstream* file;
	int size;
	int count;
	const double resize_val = 0.75;

	map<string, string> users;
	struct UserTemp {
		char _username[11];
		char _password[11];
		char _fname[21];
		char _lname[21];
		int _role;
	};
public:
	UsersList(string, string);
	~UsersList();
	//DATABASE
	bool validation(char[], char[]);
	string autharization();
	bool registration();

	bool create(UserTemp&);
	UserTemp* read(string);
	void print(string);
	void print();
	//update
	bool remove(string);
	bool backup();
};