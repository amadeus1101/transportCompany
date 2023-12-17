#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

class HashTable {
protected:
	std::string PATH;
	std::string BACKUP_PATH;
	std::string CONFIG_FILE;
	std::fstream* file;
	int size;
	int count;
	const double resize_val = 0.75;

	struct HashNode {
		std::string t_key;
		std::string t_value;
	};
	HashNode* hashSet;
public:
	HashTable(std::string&, std::string&, std::string&);
	~HashTable();
	//HASH-TABLE
	int hash(std::string, int);
	bool push(HashNode&);
	bool pop(std::string);
	int find(std::string);
	void findAll();
	void resize();
};