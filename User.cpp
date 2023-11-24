#include "User.h"

User::User(int _userID, std::string _username, std::string _password, std::string _name, int _status)
{
	user_id = _userID;
	username = _username;
	password = _password;
	name = _name;
	status = _status;

	std::string _filename = "USERS.dat";
	int _size = 10;
	//HASH
	//UDB = new UsersHashMap(_filename, _size);
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
			profile(); break;
		case 2:
			createCargo(); break;
		case 3:
			std::cout << "(3)" << std::endl; break;
		default:
			std::cout << "DEFAULT" << std::endl;
		}
	}
}

void User::profile() {
	std::cout << user_id << "+++" << username << "+++" << password << "+++" << name << "+++" << status << std::endl;
}

bool User::createCargo() {
	double a, b;
	std::string c, d, e;
	std::cout << "VVEDITE CARGO: (V3, M, Transport, FROM, TO): " << std::endl;
	std::cin >> a >> b >> c >> d >> e;
	Cargo* ncargo = new Cargo(a, b, c, d, e);
	ncargo->show();
	return false;
}