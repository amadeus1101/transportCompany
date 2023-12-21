#include "Admin.h"

//Admin::Admin(int _id, std::string _username, std::string _password, std::string _name, int _status) : Manager::Manager(_id, _username, _password, _name, _status)

void Admin::menu() {
	int user_choice = 0;
	while (user_choice != 3)
	{
		std::cout << "ADMIN MENU" << std::endl;
		std::cout << "1. PROFILE" << std::endl;
		std::cout << "2. GET USER..." << std::endl;
		std::cout << "3. EXIT" << std::endl;
		std::cin >> user_choice;
		/*switch (user_choice)
		{
		case 1:
			std::cout << "(1)" << std::endl; break;
		case 2:
			usersdb->getUsers(); break;
		case 3:
			std::cout << "(3)" << std::endl; break;
		default:
			std::cout << "DEFAULT" << std::endl;
		}*/
	}
}