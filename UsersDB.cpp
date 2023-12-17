#include "UsersDB.h"

UsersDB::UsersDB(std::string _path, std::string _conf, std::string _backup) : HashTable::HashTable(_path, _conf, _backup) {}

UsersDB::~UsersDB() {}

//DATABASE OPERATIONS

bool UsersDB::create(std::string _uname, std::string _pass, std::string _fname, std::string _lname, int _role) {
	std::string _flname;
	char mas16[] = { 'a', 'b', 'c', 'd', 'e', 'f' };
	int t_sym = 0;
	int len = _uname.length();
	for (int j = 0; j < len; j++)
	{
		t_sym = _uname[j];
		_flname += std::to_string(t_sym / 16);
		t_sym % 16 > 9 ? _flname += mas16[t_sym % 16 - 10] : _flname += std::to_string(t_sym % 16);
	
	}
	while (_flname.length() < 20)
		_flname = "00" + _flname;
	_flname += ".dat";
	
	file->open(PATH + _flname, std::ios::binary | std::ios::out);

	if (!file->is_open())
		return false;

	file->write((char*)&len, sizeof(len));
	for (int i = 0; i < len; i++)
	{
		file->write((char*)&_uname[i], sizeof(_uname[i]));
	}

	len = _pass.length();
	file->write((char*)&len, sizeof(len));
	for (int i = 0; i < len; i++)
	{
		file->write((char*)&_pass[i], sizeof(_pass[i]));
	}

	len = _fname.length();
	file->write((char*)&len, sizeof(len));
	for (int i = 0; i < len; i++)
	{
		file->write((char*)&_fname[i], sizeof(_fname[i]));
	}

	len = _lname.length();
	file->write((char*)&len, sizeof(len));
	for (int i = 0; i < len; i++)
	{
		file->write((char*)&_lname[i], sizeof(_lname[i]));
	}

	file->write((char*)&_role, sizeof(_role));

	file->close();

	HashNode* spt = new HashNode;
	spt->t_key = _uname;
	spt->t_value = _flname;
	if (!push(*spt)) std::cout << "ERROR in creating hash-table" << std::endl;
	if (count > size * resize_val)
		resize();
	delete spt;

	return true;
}

void UsersDB::read() {
	int len;
	std::string str;
	char sym;
	std::cout << "| " << std::setw(4) << "Num" << " | " << std::setw(10) << "Username" << " | " << std::setw(20) << "First name";
	std::cout << " | " << std::setw(20) << "Last name" << " | " << std::setw(4) << "Role" << " |" << std::endl;
	//std::cout << std::setw(74) << std::setfill('-') << "-" << std::endl;
	for (int i = 0; i < size; i++)
	{
		file->open(PATH + hashSet[i].t_value, std::ios::binary | std::ios::in);
		if (file->is_open())
		{
			//Number
			std::cout << "| " << std::setw(4) << i << " | ";
			//USERNAME
			str = "";
			file->read((char*)&len, sizeof(len));
			for (int j = 0; j < len; j++)
			{
				file->read((char*)&sym, sizeof(sym));
				str += sym;
			}
			std::cout << std::setw(10) << str << " | ";
			//PASSWORD
			file->read((char*)&len, sizeof(len));
			for (int j = 0; j < len; j++)
			{
				file->read((char*)&sym, sizeof(sym));
			}
			//FIRST NAME
			str = "";
			file->read((char*)&len, sizeof(len));
			for (int j = 0; j < len; j++)
			{
				file->read((char*)&sym, sizeof(sym));
				str += sym;
			}
			std::cout << std::setw(20) << str << " | ";
			//LAST NAME
			str = "";
			file->read((char*)&len, sizeof(len));
			for (int j = 0; j < len; j++)
			{
				file->read((char*)&sym, sizeof(sym));
				str += sym;
			}
			std::cout << std::setw(20) << str << " | ";
			//ROLE
			file->read((char*)&len, sizeof(len));
			std::cout << std::setw(4) << len << " |" << std::endl;
		}
		file->close();
	}
}

void UsersDB::read(std::string _key) {
	int pos = find(_key);
	if (pos > -1 && pos < size)
	{
		int len;
		std::string str;
		char sym;
		std::cout << "| " << std::setw(4) << "Num" << " | " << std::setw(10) << "Username" << " | " << std::setw(20) << "First name";
		std::cout << " | " << std::setw(20) << "Last name" << " | " << std::setw(4) << "Role" << " |" << std::endl;

		file->open(PATH + hashSet[pos].t_value, std::ios::binary | std::ios::in);
		if (file->is_open())
		{
			//Number
			std::cout << "| " << std::setw(4) << pos << " | ";
			//USERNAME
			str = "";
			file->read((char*)&len, sizeof(len));
			for (int j = 0; j < len; j++)
			{
				file->read((char*)&sym, sizeof(sym));
				str += sym;
			}
			std::cout << std::setw(10) << str << " | ";
			//PASSWORD
			file->read((char*)&len, sizeof(len));
			for (int j = 0; j < len; j++)
			{
				file->read((char*)&sym, sizeof(sym));
			}
			//FIRST NAME
			str = "";
			file->read((char*)&len, sizeof(len));
			for (int j = 0; j < len; j++)
			{
				file->read((char*)&sym, sizeof(sym));
				str += sym;
			}
			std::cout << std::setw(20) << str << " | ";
			//LAST NAME
			str = "";
			file->read((char*)&len, sizeof(len));
			for (int j = 0; j < len; j++)
			{
				file->read((char*)&sym, sizeof(sym));
				str += sym;
			}
			std::cout << std::setw(20) << str << " | ";
			//ROLE
			file->read((char*)&len, sizeof(len));
			std::cout << std::setw(4) << len << " |" << std::endl;
		}
		file->close();
	}
}

bool UsersDB::remove(std::string _key) {
	int pos = find(_key);
	if (pos > -1 && pos < size)
	{
		std::string _flname = PATH + hashSet[pos].t_value;
		char st[35];
		strcpy_s(st, _flname.c_str());
		if (!std::remove(st))
		{
			pop(_key);
			std::cout << "FILE: " << st << ":: was successfully deleted" << std::endl;
			return true;
		}
		else {
			std::cout << "Error in file, cannot delete" << std::endl;
			return false;
		}
	}
	return false;
}

bool UsersDB::backup() {
	int len;
	char sym;
	std::fstream* back_file = new std::fstream;
	std::ofstream ofl;
	time_t mytime = time(NULL);
	struct tm* now = localtime(&mytime);
	std::string date = "BACKED UP AT " + std::to_string(now->tm_mday) + std::to_string(now->tm_mon + 1) + std::to_string(now->tm_year + 1900) + " :: " + std::to_string(now->tm_hour) + ":" + std::to_string(now->tm_min);

	//CONFIG BACKUP
	back_file->open(BACKUP_PATH + CONFIG_FILE, std::ios::binary | std::ios::out);
	if (back_file->is_open())
	{
		for (int i = 0; i < size; i++)
		{
			if (hashSet[i].t_key != "-1")
			{
				len = hashSet[i].t_key.length();
				back_file->write((char*)&len, sizeof(len));
				for (int j = 0; j < len; j++)
					back_file->write((char*)&hashSet[i].t_key[j], sizeof(hashSet[i].t_key[j]));

				len = hashSet[i].t_value.length();
				back_file->write((char*)&len, sizeof(len));
				for (int j = 0; j < len; j++)
					back_file->write((char*)&hashSet[i].t_value[j], sizeof(hashSet[i].t_value[j]));
			}
		}
	}
	back_file->close();

	//DATABASE BACKUP
	for (int i = 0; i < size; i++)
	{
		file->open(PATH + hashSet[i].t_value, std::ios::binary | std::ios::in);
		back_file->open(BACKUP_PATH + hashSet[i].t_value, std::ios::binary | std::ios::out);
		if (file->is_open() && back_file->is_open())
		{
			//USERNAME
			file->read((char*)&len, sizeof(len));
			back_file->write((char*)&len, sizeof(len));
			for (int j = 0; j < len; j++)
			{
				file->read((char*)&sym, sizeof(sym));
				back_file->write((char*)&sym, sizeof(sym));
			}
			//PASSWORD
			file->read((char*)&len, sizeof(len));
			back_file->write((char*)&len, sizeof(len));
			for (int j = 0; j < len; j++)
			{
				file->read((char*)&sym, sizeof(sym));
				back_file->write((char*)&sym, sizeof(sym));
			}
			//FIRST NAME
			file->read((char*)&len, sizeof(len));
			back_file->write((char*)&len, sizeof(len));
			for (int j = 0; j < len; j++)
			{
				file->read((char*)&sym, sizeof(sym));
				back_file->write((char*)&sym, sizeof(sym));
			}
			//LAST NAME
			file->read((char*)&len, sizeof(len));
			back_file->write((char*)&len, sizeof(len));
			for (int j = 0; j < len; j++)
			{
				file->read((char*)&sym, sizeof(sym));
				back_file->write((char*)&sym, sizeof(sym));
			}
			//ROLE
			file->read((char*)&len, sizeof(len));
			back_file->write((char*)&len, sizeof(len));
		}
		file->close();
		back_file->close();
	}

	//BACKUP INFO
	
	ofl.open(BACKUP_PATH + "README.txt");
	if (ofl.is_open())
	{
		ofl << date << std::endl;
	}
	ofl.close();

	std::cout << std::endl << "BACKUP HAS BEEN DONE at " << date << std::endl;

	delete back_file;
	return true;
}