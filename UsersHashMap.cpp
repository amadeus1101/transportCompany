#include "UsersHashMap.h"

UsersHashMap::UsersHashMap(std::string _file_name, int _size) {
	count = 0;
	size = _size;
	file_name = _file_name;
	usersTable = new tUser * [size];

	for (int i = 0; i < size; i++)
		usersTable[i] = nullptr;

	//FILE

	fin.open(file_name, std::ios::in | std::ios::binary);
	if (!fin.is_open())
	{
		std::cout << "NET DOSTUPA K DB" << std::endl;
		return;
	}

	while (!fin.eof())
	{
		int len;
		char c;
		tUser* usr = new tUser;
		//USER_ID

		fin.read((char*)&usr->t_id, sizeof(int));

		//LOGIN

		fin.read((char*)&len, sizeof(int));

		usr->t_username = "";
		for (int i = 0; i < len; i++)
		{
			fin.read((char*)&c, sizeof(c));
			usr->t_username += c;
		}

		//PASSWORD

		fin.read((char*)&len, sizeof(int));
		usr->t_password = "";
		for (int i = 0; i < len; i++)
		{
			fin.read((char*)&c, sizeof(c));
			usr->t_password += c;
		}

		//NAME

		fin.read((char*)&len, sizeof(int));
		usr->t_name = "";
		for (int i = 0; i < len; i++)
		{
			fin.read((char*)&c, sizeof(c));
			usr->t_name += c;
		}

		//ROLE

		fin.read((char*)&usr->t_status, sizeof(int));
		int hashRes = usr->t_username.size() % size;
		
		if (usersTable[hashRes] == nullptr)
		{
			usersTable[hashRes] = usr;
			usr->next = nullptr;
		}
		else {
			usr->next = usersTable[hashRes];
			usersTable[hashRes] = usr;
		}
		count++;
		all_count++;
	}

	fin.close();
}

UsersHashMap::~UsersHashMap() {
	for (int i = 0; i < size; i++)
	{
		if (usersTable[i]) delete usersTable[i];
	}
	delete[] usersTable;
}

bool UsersHashMap::write(int _id = -1, std::string _username="", std::string _password="", std::string _name="", int _status = 1) {

	fout.open(file_name, std::ios::out | std::ios::binary | std::ios::app);
	if (!fout.is_open())
	{
		std::cout << "oshibka s failom";
		return false;
	}

	//USER_ID

	fout.write((char*)&_id, sizeof(int));

	//LOGIN

	size_t len = _username.length();
	fout.write((char*)&len, sizeof(int));
	for (int i = 0; i < len; i++)
		fout.write((char*)&_username[i], sizeof(_username[i]));

	//PASSWORD

	len = _password.length();
	fout.write((char*)&len, sizeof(int));
	for (int i = 0; i < len; i++)
		fout.write((char*)&_password[i], sizeof(_password[i]));

	//NAME

	len = _name.length();
	fout.write((char*)&len, sizeof(int));
	for (int i = 0; i < len; i++)
		fout.write((char*)&_name[i], sizeof(_name[i]));

	// ROLE

	fout.write((char*)&_status, sizeof(int));

	fout.close();
	insert(_id, _username, _password, _name, _status);

	return true;
}

//bool UsersHashMap::read() {}

int UsersHashMap::hash(std::string _login) {
	int hashRes = 0;
	int len = _login.size();
	/*for (int i = 0; i < len; i++)	
		hashRes = (hashRes + _login[i]) % size;
	hashRes = (hashRes * 2 + 1) % size;*/
	return len % size;
}

bool UsersHashMap::resize() {
	count = 0;
	all_count = 0;
	int prev_size = size;
	tUser** temp_usersTable = usersTable;
	size *= 2;

	usersTable = new tUser * [size];
	for (int i = 0; i < size; i++)
		usersTable[i] = nullptr;
	
	for (int i = 0; i < prev_size; i++)
	{
		tUser* spt = temp_usersTable[i];
		
		while (spt)
		{
			tUser* spp = spt;
			spt = spt->next;
			insert(spp);
		}
	}
	return true;
}

void UsersHashMap::rehash() {
	tUser** usersTable2 = usersTable;

	for (int i = 0; i < size; i++)
		usersTable[i] = nullptr;

	//swap spiska

	for (int i = 0; i < size; ++i)
	{
		tUser* spt = usersTable2[i];
		while (spt)
		{
			if (spt->t_status > 0)
			{
				tUser* spp = spt;
				spt = spt->next;
				insert(spp);
			}
				
		}
	}
}

bool UsersHashMap::insert(tUser *user) {
	if (count > size * rehash_val)
		resize();
	int hashRes = hash(user->t_username);
	if (usersTable[hashRes] == nullptr)
	{
		usersTable[hashRes] = user;
		user->next = nullptr;
	}
	else {
		user->next = usersTable[hashRes];
		usersTable[hashRes] = user;
	}
	all_count++;
	count++;
	//write(user->t_id, user->t_username, user->t_password, user->t_name, user->t_status);
	return true;
}

bool UsersHashMap::insert(int _userId, std::string _username, std::string _password, std::string _name, int _role=1) {
	tUser* user = new tUser;
	user->next = nullptr;
	user->t_id = _userId;
	user->t_username = _username;
	user->t_password = _password;
	user->t_name = _name;
	user->t_status = _role;

	if (count > size * rehash_val)
		resize();
	int hashRes = hash(user->t_username);
	if (usersTable[hashRes] == nullptr)
	{
		usersTable[hashRes] = user;
		user->next = nullptr;
	}
	else {
		user->next = usersTable[hashRes];
		usersTable[hashRes] = user;
	}
	all_count++;
	count++;
	//write(user->t_id, user->t_username, user->t_password, user->t_name, user->t_status);
	return true;
}

UsersHashMap::tUser* UsersHashMap::find(std::string _login) {
	int hashRes = hash(_login);
	tUser* spt = usersTable[hashRes];
	while (spt)
	{
		if (spt->t_username == _login)
			return spt;
		spt = spt->next;
	}
	return nullptr;
}

UsersHashMap::tUser* UsersHashMap::getAuth(std::string _login, std::string _password) {
	tUser* authUser = find(_login);
	if (authUser->t_password == _password)
		return authUser;
	return NULL;
}

bool UsersHashMap::remove(int _userID) {
	//O(n) like array because ID
	return false;
}

bool UsersHashMap::remove(std::string _login) {
	tUser* spt = find(_login);
	if (spt) 
	{
		spt->t_status = -1;
		count--;
		return true;
	}
	return false;
}

void UsersHashMap::getUsers() {
	for (int i = 0; i < size; i++)
	{
		tUser* spt = usersTable[i];
		while (spt)
		{
			std::cout << "#" << i << std::endl;
			std::cout << spt->t_id << "---" << spt->t_username << "---" << spt->t_password << "---" << spt->t_name << "---" << spt->t_status << std::endl;
			spt = spt->next;
		}
	}
}