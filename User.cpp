#include "User.h"

User::User(int _userID, std::string _username, std::string _password, std::string _name, int _status)
{
	user_id = _userID;
	username = _username;
	password = _password;
	name = _name;
	status = _status;
}

//int User::menu() {
//	std::cout << "USER MENU" << std::endl;
//	return 4;
//}

void User::show() {
	std::cout << user_id << "+++" << username << "+++" << password << "+++" << name << "+++" << status << std::endl;
}

bool User::setStatus(int _newstatus) {
	status = _newstatus;
	return true;
}

bool User::getAccess(std::string _login = "", std::string _password = "") {
	if (_login == username && _password == password) return true;
	return false;
}

int User::getStatus() {
	return status;
}