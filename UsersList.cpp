#include "UsersList.h"

UsersList::UsersList(string _path, string _backup) {
	file = new fstream();
	PATH = _path;
	BACKUP_PATH = _backup;
	char _key[11];
	char _value[11];

	file->open(PATH + "config.dat", ios::binary | ios::in);
	if (!file->is_open())
	{
		std::cout << "!!!" << std::setw(22) << " [503] SERVER ERROR " << "!!!" << std::endl;
		std::cout << "***" << std::setw(22) << " PLEASE RECONNECT " << "***" << std::endl;
	}
	else {
		while (!file->eof()) {
			file->read((char*)&_key, sizeof(_key));
			file->read((char*)&_value, sizeof(_value));
			users[_key] = _value;
		}
	}
	file->close();
}

UsersList::~UsersList() {
	file->open(PATH + "config.dat", std::ios::binary | std::ios::out);
	if (file->is_open())
	{
		char t_key[11];
		char t_val[11];
		for (const auto& obj : users)
		{
			strcpy_s(t_key, obj.first.c_str());
			strcpy_s(t_val, obj.second.c_str());
			file->write((char*)&t_key, sizeof(t_key));
			file->write((char*)&t_val, sizeof(t_val));
		}
	}
	else {
		cout << "Unexpected error, DB destructor collapse!!!" << endl;
	}
	file->close();
	delete file;
}

//HASH OPERATIONS

//DATABASE OPERATIONS

string UsersList::autharization() {
	string t_key;
	string t_val;
	cout << "AUTHORIZATION: " << std::endl;
	cout << "Enter yout data: " << std::endl;
	cout << endl << "login: ";
	cin >> t_key;
	cout << endl << "password: ";
	cin >> t_val;
	cout << endl;
	if (users.count(t_key) && users[t_key] == t_val)
		return (t_key + ".dat");
	return "null";
}

bool UsersList::registration() {
	UserTemp* usrtemp = new UserTemp;
	cout << "REGISTRATION" << std::endl;
	cout << "Enter yout data: " << std::endl;
	cout << std::endl << "Login: ";
	cin >> usrtemp->_username;
	cout << std::endl << "Password: ";
	cin >> usrtemp->_password;
	cout << std::endl << "First name: ";
	cin >> usrtemp->_fname;
	cout << std::endl << "Last name: ";
	cin >> usrtemp->_lname;
	size_t loglen = strlen(usrtemp->_username);
	size_t paslen = strlen(usrtemp->_password);
	for (int i = 0; i < loglen; i++)
		usrtemp->_username[i] = tolower(usrtemp->_username[i]);
	for (int i = 0; i < paslen; i++)
		usrtemp->_password[i] = tolower(usrtemp->_password[i]);
	usrtemp->_role = 1;
	if (validation(usrtemp->_username, usrtemp->_password))
	{
		if (!create(*usrtemp)) {
			delete usrtemp;
			return false;
		}
		delete usrtemp;
		return true;
	}
	delete usrtemp;
	return false;		
}

bool UsersList::validation(char _uname[], char _pass[])
{
	size_t loglen = strlen(_uname);
	size_t paslen = strlen(_pass);

	if (loglen == 0 || paslen == 0)
	{
		std::cout << "Fields cannot be empty" << std::endl;
		return false;
	}
	if (loglen < 6 || loglen > 11)
	{
		std::cout << "The username should be from 6 to 10 symbols";
		return false;
	}
	if (paslen < 5 || paslen > 11)
	{
		std::cout << "The password should be from 5 to 10 symbols";
		return false;
	}
	/*for (int j = 0; j < loglen; j++)
	{
		if (!isalnum(_uname[j]));
		{
			cout << "!!!The username should contain only 0-9 or a-z[lower]!!! Your symbol <" << _uname[j] << ">" << endl;
			return false;
		}
	}*/
	return true;
}

bool UsersList::create(UserTemp& utemp) {
	if (users.count(utemp._username))
		return false;
	file->open((PATH + utemp._username + ".dat"), ios::binary | ios::out);
	if (!file->is_open())
		return false;
	file->write((char*)&utemp, sizeof(UserTemp));
	file->close();
	users[utemp._username] = utemp._password;
	return true;
}

UsersList::UserTemp* UsersList::read(string _key) {
	if (!users.count(_key))
		return nullptr;
	file->open((PATH + _key + ".dat"), ios::binary | ios::in);
	if (!file->is_open())
		return nullptr;
	UserTemp* obj = new UserTemp;
	file->read((char*)&(*obj), sizeof(UserTemp));
	file->close();
	return obj;
}

void UsersList::print(string _key) {
	UserTemp* obj = read(_key);
	cout << "| " << setw(10) << "Username" << " | " << setw(20) << "First name";
	cout << " | " << setw(20) << "Last name" << " | " << setw(4) << "Role" << " |" << endl;
	if (obj)
	{
		cout << "| " << setw(10) << obj->_username << " | ";
		cout << setw(20) << obj->_fname << " | ";
		cout << setw(20) << obj->_lname << " | ";
		cout << setw(4) << obj->_role << " |" << endl;
	}
	delete obj;
}

void UsersList::print() {
	char t_key[11];
	cout << "| " << setw(10) << "Username" << " | " << setw(20) << "First name";
	cout << " | " << setw(20) << "Last name" << " | " << setw(4) << "Role" << " |" << endl;
	for (const auto& elem : users)
	{
		strcpy_s(t_key, elem.first.c_str());
		UserTemp* obj = read(t_key);
		if (obj)
		{
			cout << "| " << setw(10) << obj->_username << " | ";
			cout << setw(20) << obj->_fname << " | ";
			cout << setw(20) << obj->_lname << " | ";
			cout << setw(4) << obj->_role << " |" << endl;
		}
		delete obj;
	}	
}

bool UsersList::remove(string _key) {
	if (!users.count(_key))
		return false;
	string _fname = PATH + _key + ".dat";
	if (!std::remove(_fname.c_str()))
	{
		users.erase(_key);
		std::cout << "FILE: " << _fname << ":: was successfully deleted" << std::endl;
		return true;
	}
	else {
		std::cout << "Error in file, cannot delete" << std::endl;
		return false;
	}
}

bool UsersList::backup() {
	fstream* back_file = new fstream;
	//time_t mytime = time(NULL);
	//struct tm* now = localtime(&mytime);
	string date = "BACKED UP AT 00.00.0000::00-00 [00 objects]";
	//+to_string(now->tm_mday) + to_string(now->tm_mon + 1) + to_string(now->tm_year + 1900) + " :: " + to_string(now->tm_hour) + ":" + to_string(now->tm_min);

	//CONFIG BACKUP
	back_file->open(BACKUP_PATH + "config.dat", ios::binary | ios::out);
	if (back_file->is_open())
	{
		char t_key[11];
		char t_val[11];
		for (const auto& elem : users)
		{
			strcpy_s(t_key, elem.first.c_str());
			strcpy_s(t_val, elem.second.c_str());
			file->write((char*)&t_key, sizeof(t_key));
			file->write((char*)&t_val, sizeof(t_val));
		}
	}
	back_file->close();

	//DATABASE BACKUP
	UserTemp obj;
	for (const auto& elem : users)
	{
		file->open((PATH + elem.first + ".dat"), ios::binary | ios::in);
		back_file->open((BACKUP_PATH + elem.first + ".dat"), ios::binary | ios::out);
		if (file->is_open() && back_file->is_open())
		{
			file->read((char*)&obj, sizeof(UserTemp));
			back_file->write((char*)&obj, sizeof(UserTemp));
		}
		file->close();
		back_file->close();
	}
	//BACKUP INFO
	ofstream ofl;
	ofl.open(BACKUP_PATH + "README.txt");
	if (ofl.is_open())
	{
		ofl << date << std::endl;
	}
	ofl.close();
	//cout << endl << "BACKUP HAS BEEN DONE at " << date << endl;
	delete back_file;
	return true;
}