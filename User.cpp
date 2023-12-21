#include "User.h"

User::User() {
	status = 1;
	strcpy_s(username, "x");
	strcpy_s(password, "x");
	strcpy_s(first_name, "x");
	strcpy_s(last_name, "x");
}

User::User(std::string &_filename)
{
	std::fstream* file = new std::fstream;
	file->open(_filename, std::ios::binary | std::ios::in);
	if (file->is_open())
	{
		file->read((char*)&username, sizeof(username));
		file->read((char*)&password, sizeof(password));
		file->read((char*)&first_name, sizeof(first_name));
		file->read((char*)&last_name, sizeof(last_name));
		file->read((char*)&status, sizeof(status));
	}
	else {
		status = 1;
		strcpy_s(username, "x");
		strcpy_s(password, "x");
		strcpy_s(first_name, "x");
		strcpy_s(last_name, "x");
	}
	file->close();
}

void User::menu() {
	int user_choice = 0;
	while (user_choice != 6)
	{
		std::cout << "USER MENU" << std::endl;
		std::cout << "1. PROFILE" << std::endl;
		std::cout << "2. CREATE CARGO" << std::endl;
		std::cout << "3. show history" << std::endl;
		std::cout << "4. show in process" << std::endl;
		std::cout << "5. track" << std::endl;
		std::cout << "6. EXIT" << std::endl;
		std::cin >> user_choice;
		switch (user_choice)
		{
		case 1:
			profile(); break;
		case 2:
			createFreight(); break;
		case 3:
			std::cout << "(3)" << std::endl; break;
		case 4:
			std::cout << "(4)" << std::endl; break;
		case 5:
			std::cout << "(5)" << std::endl; break;
		case 6:
			std::cout << "(6)" << std::endl; break;
		default:
			std::cout << "DEFAULT" << std::endl;
		}
	}
}

void User::profile() {
	const int wid = 50;
	std::cout << "Username" << std::setw(wid - 9) << std::setfill('.') << username << std::endl;
	std::cout << "First name" << std::setw(wid - 11) << std::setfill('.') << first_name << std::endl;
	std::cout << "Last name" << std::setw(wid - 10) << std::setfill('.') << last_name << std::endl;
}

bool User::createFreight() {
	Freight fr{ 1 };
	fr.show();
	return true;
}