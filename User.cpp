#include "User.h"

User::User(int _userID, std::string _username, std::string _password, std::string _name, int _status)
{
	//UDB = new UsersHashMap("USERS.dat", 10);
	user_id = _userID;
	username = _username;
	password = _password;
	name = _name;
	status = _status;
}

void User::menu() {
	int user_choice = 0;
	while (user_choice != 3)
	{
		std::cout << "USER MENU" << std::endl;
		std::cout << "1. PROFILE" << std::endl;
		std::cout << "2. CREATE CARGO" << std::endl;
		std::cout << "3. EXIT" << std::endl;
		std::cin >> user_choice;
		switch (user_choice)
		{
		case 1:
			show(); break;
		case 2:
			createCargo(); break;
		case 3:
			std::cout << "(3)" << std::endl; break;
		default:
			std::cout << "DEFAULT" << std::endl;
		}
	}
}

void User::show() {
	std::cout << user_id << "+++" << username << "+++" << password << "+++" << name << "+++" << status << std::endl;
}

bool User::createCargo() {
	std::cout << "CARGOOOOOOOOOOOO" << std::endl;
	return false;
}