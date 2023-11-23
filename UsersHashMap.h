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
public:
	//UsersHashMap();
	UsersHashMap(std::string, int);
	~UsersHashMap();
	//FILE
	bool write(int, std::string, std::string, std::string, int);
	//bool read();
	//SCRINE ALL BD IN NEW FILE FUNC() FOR ADMIN
	//HASH
	bool resize();
	void rehash();
	bool insert(tUser*);
	bool remove(int);
	bool remove(std::string);
	//USERS
	tUser* find(std::string);
	tUser* getAuth(std::string, std::string);
	bool insert(int, std::string, std::string, std::string, int);
	void getUsers();
;};