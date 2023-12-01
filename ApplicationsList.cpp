//#include "UsersList.h"
//
//UsersList::UsersList(std::string _file_name, int _size = 10) {
//	count = 0;
//	size = _size;
//	file_name = _file_name;
//	usersTable = new tUser * [size];
//
//	for (int i = 0; i < size; i++)
//		usersTable[i] = nullptr;
//
//	//FILE
//
//	fin.open(file_name, std::ios::in | std::ios::binary);
//	if (!fin.is_open())
//	{
//		std::cout << "NET DOSTUPA K DB" << std::endl;
//		return;
//	}
//
//	while (!fin.eof())
//	{
//		int len;
//		char c;
//		tUser* usr = new tUser;
//		//USER_ID
//
//		fin.read((char*)&usr->t_id, sizeof(int));
//
//		//LOGIN
//
//		fin.read((char*)&len, sizeof(int));
//
//		usr->t_username = "";
//		for (int i = 0; i < len; i++)
//		{
//			fin.read((char*)&c, sizeof(c));
//			usr->t_username += c;
//		}
//
//		//PASSWORD
//
//		fin.read((char*)&len, sizeof(int));
//		usr->t_password = "";
//		for (int i = 0; i < len; i++)
//		{
//			fin.read((char*)&c, sizeof(c));
//			usr->t_password += c;
//		}
//
//		//NAME
//
//		fin.read((char*)&len, sizeof(int));
//		usr->t_name = "";
//		for (int i = 0; i < len; i++)
//		{
//			fin.read((char*)&c, sizeof(c));
//			usr->t_name += c;
//		}
//
//		//ROLE
//
//		fin.read((char*)&usr->t_status, sizeof(int));
//
//		insert(usr);
//	}
//
//	fin.close();
//}
//
//UsersList::~UsersList() {
//	tUser* spt, * sp;
//	for (int i = 0; i < size; i++)
//	{
//		sp = usersTable[i];
//		while (sp)
//		{
//			spt = sp;
//			sp = sp->next;
//			delete spt;
//		}
//	}
//	delete[] usersTable;
//}
//
//int UsersList::generateId() {
//	return all_count;
//}
//
//bool UsersList::write(std::string _username = "", std::string _password = "", std::string _name = "") {
//	int _status = 1;
//	int _id = generateId();
//
//	fout.open(file_name, std::ios::out | std::ios::binary | std::ios::app);
//	if (!fout.is_open())
//	{
//		std::cout << "oshibka s failom";
//		return false;
//	}
//
//	//USER_ID
//
//	fout.write((char*)&_id, sizeof(int));
//
//	//LOGIN
//
//	size_t len = _username.length();
//	fout.write((char*)&len, sizeof(int));
//	for (int i = 0; i < len; i++)
//		fout.write((char*)&_username[i], sizeof(_username[i]));
//
//	//PASSWORD
//
//	len = _password.length();
//	fout.write((char*)&len, sizeof(int));
//	for (int i = 0; i < len; i++)
//		fout.write((char*)&_password[i], sizeof(_password[i]));
//
//	//NAME
//
//	len = _name.length();
//	fout.write((char*)&len, sizeof(int));
//	for (int i = 0; i < len; i++)
//		fout.write((char*)&_name[i], sizeof(_name[i]));
//
//	// ROLE
//
//	fout.write((char*)&_status, sizeof(int));
//
//	fout.close();
//	insert(_id, _username, _password, _name, _status);
//
//	return true;
//}
//
//int UsersList::hash(std::string _login) {
//	int hashRes = 0;
//	int len = _login.length();
//	for (int j = 0; j < len; j++)
//	{
//		hashRes += _login[j];
//	}
//	return hashRes % size;
//}
//
//void UsersList::resize() {
//	count = 0;
//	all_count = 0;
//	int prev_size = size;
//	tUser** temp_usersTable = usersTable;
//	size *= 2;
//
//	usersTable = new tUser * [size];
//	for (int i = 0; i < size; i++)
//		usersTable[i] = nullptr;
//
//	for (int i = 0; i < prev_size; i++)
//	{
//		tUser* spt = temp_usersTable[i];
//
//		while (spt)
//		{
//			tUser* spp = spt;
//			spt = spt->next;
//			insert(spp);
//		}
//	}
//	/*tUser* spt, * sp;
//	for (int i = 0; i < size; i++)
//	{
//		sp = temp_usersTable[i];
//		while (sp)
//		{
//			spt = sp;
//			if(sp->next)
//				sp = sp->next;
//			delete spt;
//		}
//	}
//	delete[] temp_usersTable;*/
//}
//
//void UsersList::rehash() {
//	all_count = 0;
//	count = 0;
//	tUser** temp_usersTable = usersTable;
//
//	for (int i = 0; i < size; i++)
//		usersTable[i] = nullptr;
//
//	tUser* spt, * sp;
//
//	for (int i = 0; i < size; ++i)
//	{
//		spt = temp_usersTable[i];
//		while (spt)
//		{
//			if (spt->t_status > 0)
//			{
//				sp = spt;
//				spt = spt->next;
//				insert(sp);
//			}
//		}
//	}
//	for (int i = 0; i < size; i++)
//	{
//		sp = temp_usersTable[i];
//		while (sp)
//		{
//			spt = sp;
//			sp = sp->next;
//			delete spt;
//		}
//	}
//	delete[] temp_usersTable;
//}
//
//bool UsersList::insert(tUser* user) {
//	if (user->t_status < -2 || user->t_status > 5) return false;
//	if (count > size * 0.75)
//		resize();
//	if (all_count * 0.5 > count)
//		rehash();
//	int hashRes = hash(user->t_username);
//	if (usersTable[hashRes] == nullptr)
//	{
//		usersTable[hashRes] = user;
//		user->next = nullptr;
//	}
//	else {
//		user->next = usersTable[hashRes];
//		usersTable[hashRes] = user;
//	}
//	all_count++;
//	count++;
//	return true;
//}
//
//bool UsersList::insert(int _userId, std::string _username, std::string _password, std::string _name, int _role = 1) {
//	if (_role < -2 || _role > 5) return false;
//	tUser* user = new tUser;
//	user->next = nullptr;
//	user->t_id = _userId;
//	user->t_username = _username;
//	user->t_password = _password;
//	user->t_name = _name;
//	user->t_status = _role;
//
//	if (count > size * 0.75)
//		resize();
//	if (all_count * 0.5 > count)
//		rehash();
//	int hashRes = hash(user->t_username);
//	if (usersTable[hashRes] == nullptr)
//	{
//		usersTable[hashRes] = user;
//		user->next = nullptr;
//	}
//	else {
//		user->next = usersTable[hashRes];
//		usersTable[hashRes] = user;
//	}
//	all_count++;
//	count++;
//	//write(user->t_id, user->t_username, user->t_password, user->t_name, user->t_status);
//	return true;
//}
//
//UsersList::tUser* UsersList::find(std::string _login) {
//	int hashRes = hash(_login);
//	tUser* spt = usersTable[hashRes];
//	while (spt)
//	{
//		if (spt->t_username == _login)
//			return spt;
//		spt = spt->next;
//	}
//	return nullptr;
//}
//
//std::string* UsersList::getAuth(std::string _login, std::string _password) {
//	tUser* authUser = find(_login);
//	if (!authUser) return NULL;
//	if (authUser->t_password == _password)
//	{
//		std::string* ud = new std::string[5];
//		ud[0] = std::to_string(authUser->t_id);
//		ud[1] = authUser->t_username;
//		ud[2] = authUser->t_password;
//		ud[3] = authUser->t_name;
//		ud[4] = std::to_string(authUser->t_status);
//		return ud;
//	}
//	return NULL;
//}
//
//bool UsersList::remove(std::string _login) {
//	tUser* spt = find(_login);
//	if (spt)
//	{
//		spt->t_status = -1;
//		count--;
//		return true;
//	}
//	return false;
//}
//
//void UsersList::getUsers() {
//	for (int i = 0; i < size; i++)
//	{
//		tUser* spt = usersTable[i];
//		while (spt)
//		{
//			std::cout << "#" << i << std::endl;
//			std::cout << spt->t_id << "---" << spt->t_username << "---" << spt->t_password << "---" << spt->t_name << "---" << spt->t_status << std::endl;
//			spt = spt->next;
//		}
//	}
//}
//
//bool UsersList::backup(std::string _filename) {
//
//	fout.open(_filename, std::ios::out | std::ios::binary | std::ios::app);
//	if (!fout.is_open())
//	{
//		std::cout << "oshibka s failom";
//		return false;
//	}
//
//	for (int i = 0; i < size; i++)
//	{
//		tUser* spt = usersTable[i];
//		while (spt)
//		{
//			//USER_ID
//
//			fout.write((char*)&spt->t_id, sizeof(int));
//
//			//LOGIN
//
//			size_t len = spt->t_username.length();
//			fout.write((char*)&len, sizeof(int));
//			for (int i = 0; i < len; i++)
//				fout.write((char*)&spt->t_username[i], sizeof(spt->t_username[i]));
//
//			//PASSWORD
//
//			len = spt->t_password.length();
//			fout.write((char*)&len, sizeof(int));
//			for (int i = 0; i < len; i++)
//				fout.write((char*)&spt->t_password[i], sizeof(spt->t_password[i]));
//
//			//NAME
//
//			len = spt->t_name.length();
//			fout.write((char*)&len, sizeof(int));
//			for (int i = 0; i < len; i++)
//				fout.write((char*)&spt->t_name[i], sizeof(spt->t_name[i]));
//
//			// ROLE
//
//			fout.write((char*)&spt->t_status, sizeof(int));
//
//			spt = spt->next;
//		}
//
//	}
//	fout.close();
//	return true;
//}
//
//bool UsersList::read(std::string _filename) {
//	count = 0;
//	all_count = 0;
//	file_name = _filename;
//	tUser** temp_usersTable = usersTable;
//	usersTable = new tUser * [size];
//
//	for (int i = 0; i < size; i++)
//		usersTable[i] = nullptr;
//	//FILE
//
//	fin.open(file_name, std::ios::in | std::ios::binary);
//	if (!fin.is_open())
//	{
//		std::cout << "NET DOSTUPA K DB" << std::endl;
//		return false;
//	}
//
//	while (!fin.eof())
//	{
//		int len = 0;
//		char c;
//		tUser* new_usr = new tUser;
//		//USER_ID
//
//		fin.read((char*)&new_usr->t_id, sizeof(int));
//
//		//LOGIN
//
//		fin.read((char*)&len, sizeof(int));
//
//		new_usr->t_username = "";
//		for (int i = 0; i < len; i++)
//		{
//			fin.read((char*)&c, sizeof(c));
//			new_usr->t_username += c;
//		}
//
//		//PASSWORD
//
//		fin.read((char*)&len, sizeof(int));
//		new_usr->t_password = "";
//		for (int i = 0; i < len; i++)
//		{
//			fin.read((char*)&c, sizeof(c));
//			new_usr->t_password += c;
//		}
//
//		//NAME
//
//		fin.read((char*)&len, sizeof(int));
//		new_usr->t_name = "";
//		for (int i = 0; i < len; i++)
//		{
//			fin.read((char*)&c, sizeof(c));
//			new_usr->t_name += c;
//		}
//
//		//ROLE
//
//		fin.read((char*)&new_usr->t_status, sizeof(int));
//
//		insert(new_usr);
//	}
//
//	fin.close();
//
//	tUser* spt, * sp;
//	for (int i = 0; i < size; i++)
//	{
//		sp = temp_usersTable[i];
//		while (sp)
//		{
//			spt = sp;
//			sp = sp->next;
//			delete spt;
//		}
//	}
//	delete[] temp_usersTable;
//	return true;
//}