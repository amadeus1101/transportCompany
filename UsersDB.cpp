#include "UsersDB.h"

UsersDB::UsersDB(std::string _path, std::string _conf, std::string _backup) : HashTable::HashTable(_path, _conf, _backup) {}

UsersDB::~UsersDB() {}

//DATABASE OPERATIONS

std::string UsersDB::autharization() {
	char _login[11];
	char _password[11];
	std::cout << "AUTHORIZATION: " << std::endl;
	std::cout << "Enter yout data: " << std::endl;
	std::cout << std::endl << "login: ";
	std::cin >> _login;
	std::cout << std::endl << "password: ";
	std::cin >> _password;
	std::cout << std::endl;
	int pos = find(_login);
	if (pos > -1)
	{
		if (std::strcmp(_login, hashSet[pos].t_key.c_str()) == 0 && std::strcmp(_password, hashSet[pos].t_value.c_str()) == 0)
		{
			std::string _flname = "";
			int stlen = std::strlen(_login);
			int p = 0;
			int alen = alphabet.length();
			for (int i = 0; i < stlen; i++)
			{
				p = 0;
				while (_login[i] != alphabet[p])
					p++;
				p + 7 > alen ? _flname += alphabet[p + 7 - alen] : _flname += alphabet[p + 7];
			}
			_flname += ".dat";
			return _flname;
		}
	}
	return "null";
}

bool UsersDB::registration() {
	char _username[11];
	char _password[11];
	char _fname[21];
	char _lname[21];
	std::cout << "REGISTRATION" << std::endl;
	std::cout << "Enter yout data: " << std::endl;
	std::cout << std::endl << "Login: ";
	std::cin >> _username;
	std::cout << std::endl << "Password: ";
	std::cin >> _password;
	std::cout << std::endl << "First name: ";
	std::cin >> _fname;
	std::cout << std::endl << "Last name: ";
	std::cin >> _lname;
	for (int i = 0; i < std::strlen(_username); i++)
		_username[i] = std::tolower(_username[i]);
	for (int i = 0; i < std::strlen(_password); i++)
		_password[i] = std::tolower(_password[i]);
	if (validate(_username, _password))
	{
		create(_username, _password, _fname, _lname, 1);
		return true;
	}
	return false;		
}

bool UsersDB::validate(std::string _uname, std::string _pass)
{
	size_t unameLen = _uname.length();
	size_t passLen = _pass.length();
	bool isPassValid = false;

	if (unameLen == 0 || passLen == 0)
	{
		std::cout << "Fields cannot be empty" << std::endl;
		return false;
	}
	if (unameLen < 5 || unameLen > 11)
	{
		std::cout << "The username should be >= 6 and < 11 symbols";
		return false;
	}
	if (passLen < 5 || passLen > 13)
	{
		std::cout << "The password should be > 4 and < 13 symbols ";
		return false;
	}
	for (int j = 0; j < passLen; j++)
	{
		char c = _pass[j];
		if (c < 57)
		{
			isPassValid = true;
			break;
		}
	}
	if (!isPassValid) {
		std::cout << "The password should contain minimum 1 number" << std::endl;
		return false;
	}
	isPassValid = false;
	for (int j = 0; j < passLen; j++)
	{
		char c = _pass[j];
		if (c > 65)
		{
			isPassValid = true;
			break;
		}
	}
	if (!isPassValid) {
		std::cout << "The password should contain minimum 1 letter" << std::endl;
		return false;
	}
	if (find(_uname) != -1)
	{
		std::cout << "The username has already taken, try to create another new;(" << std::endl;
		return false;
	}
	return true;
}

bool UsersDB::create(const char* _uname, const char* _pass, const char* _fname, const char* _lname, int _role) {
	std::string _flname = "";
	int len = std::strlen(_uname);
	int p;
	int alen = alphabet.length();
	for (int j = 0; j < len; j++)
	{
		p = 0;
		while (_uname[j] != alphabet[p])
			p++;
		p + 7 > alen ? _flname += alphabet[p + 7 - alen] : _flname += alphabet[p + 7];
	}

	HashNode* spt = new HashNode;
	spt->t_key = _uname;
	spt->t_value = _pass;
	if (!push(*spt)) std::cout << "ERROR in creating hash-table" << std::endl;
	if (count > size * resize_val)
		resize();
	delete spt;
	findAll();

	_flname = PATH + _flname + ".dat";
	
	file->open(_flname, std::ios::binary | std::ios::out);

	if (!file->is_open())
		return false;

	file->write((char*)&_uname, sizeof(_uname));
	file->write((char*)&_pass, sizeof(_pass));
	file->write((char*)&_fname, sizeof(_fname));
	file->write((char*)&_lname, sizeof(_lname));
	file->write((char*)&_role, sizeof(_role));

	file->close();

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