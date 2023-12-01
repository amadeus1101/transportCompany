#pragma once

#include <iostream>
#include <fstream>
#include <vector>

#include "List.h"

class UsersList : public List {
private:
	struct tUser {
		int t_id, t_status;
		std::string t_username, t_password, t_name;
		tUser* next;
	};
	tUser** usersTable;	
public:
	UsersList(std::string, int);
	~UsersList();
	void resize() override final;
	void rehash() override final;
	int hash(std::string) override final;
	int generateId() override final;
	bool backup(std::string) override final;
	bool read(std::string) override final;
	bool remove(std::string) override final;

	bool write(std::string, std::string, std::string);
	bool insert(tUser*);
	bool insert(int, std::string, std::string, std::string, int);
	tUser* find(std::string);
	std::string* getAuth(std::string, std::string);
	void getUsers();
;};