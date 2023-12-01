#pragma once

#include <iostream>
#include <string>
#include <fstream>

class List {
protected:
	std::string file_name;
	std::ifstream fin;
	std::ofstream fout;
	int size;
	int count;
	int all_count;
	const double rehash_val = 0.75;

	virtual void resize() = 0;
	virtual void rehash() = 0;
	virtual int hash(std::string) = 0;
	virtual int generateId() = 0;
	virtual bool remove(std::string) = 0;
	virtual bool backup(std::string) = 0;
	virtual bool read(std::string) = 0;
};

