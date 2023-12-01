#pragma once

#include <iostream>
#include <fstream>
#include <vector>

#include "List.h"

class ApplicationsList : public List {
private:
	struct tApp {
		int app_id;
		//ROUTE
		std::string t_dep;
		std::string t_des;
		//VIC
		std::string t_vic;
		//Cago
		std::string t_cargo;
		std::string t_package;
		double t_cap;
		double t_wei;
		double t_pri;
		//Contacts
		//sender
		std::string sender_username;
		std::string sender_name;
		std::string sender_address;
		std::string sender_email;
		std::string sender_tel;
		//reciever
		std::string reciever_username;
		std::string reciever_name;
		std::string reciever_address;
		std::string reciever_email;
		std::string reciever_tel;
	};
	tApp** appsTable;
public:
	ApplicationsList(std::string, int);
	~ApplicationsList();
	void resize() override final;
	void rehash() override final;
	int hash(std::string) override final;
	int generateId() override final;
	bool backup(std::string) override final;
	bool read(std::string) override final;
	bool remove(std::string) override final;

	bool write(std::string, std::string, std::string);
	bool insert(tApp*);
	bool insert(int, std::string, std::string, std::string, int);
	tApp* find(std::string);
	std::string* getAuth(std::string, std::string);
	void getUsers();
	;
};