#pragma once

#include <iostream>
#include <fstream>
#include <vector>

#include "User.h"

class UsersHashMap {
private:
	struct tUser {
		int t_id, t_status;
		std::string t_username, t_password, t_name;
		tUser* next;
	};
	tUser** usersTable;
	std::string file_name;
	std::ifstream fin;
	std::ofstream fout;
	int size;
	int count;
	int all_count;
	static const int rehash_val = 0.75;

	//METHODS

	int hash(std::string);
	bool doBackUp(std::string); //FOR ADMIN
	bool readOtherDB(std::string); //FOR ADMIN
public:
	UsersHashMap(std::string, int);
	~UsersHashMap();
	int generateId();
	bool write(std::string, std::string, std::string);
	bool resize();
	bool insert(tUser*);
	bool remove(int);
	bool remove(std::string);
	bool insert(int, std::string, std::string, std::string, int);
	tUser* find(std::string);
	std::string* getAuth(std::string, std::string);
	void rehash();
	void getUsers();
;};