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
			createCargo(); break;
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
	std::cout << user_id << "   " << username << "   " << password << "   " << name << "   " << status << std::endl;
}

bool User::createCargo() {
	std::string countriesArr[3][4] = {
		{"Germany", "Berlin", "Frankfurt", "Munhen"},
		{"France", "Paris", "Lion", "Marcel"},
		{"Spain", "Madrid", "Barcelona", "Valencia"} };
	std::string vehiclesArr[4] = { "Truck", "Train", "Ship", "Plane" };
	std::string cargoTypes[4] = { "Glass", "Metal", "Plastic", "Wood" };
	std::string packageTypes[3] = { "Paper", "Wooden", "Polymeric" };

	int _cargo, _package;
	int vic_code = -1, dep_code = -1, des_code = -1;
	int country_choice;
	double _cap, _wei;
	std::string _vic, _dep, _des;
	std::cout << "**********Cargo menu**********" << std::endl;
	std::cout << "Enter your parameters: " << std::endl;

	std::cout << std::endl << "capacity (m3): ";
	std::cin >> _cap;

	std::cout << std::endl << "weigth (kg): ";
	std::cin >> _wei;

	std::cout << std::endl << "Cargo type: " << std::endl;
	for (int i = 0; i < 4; i++)
		std::cout << i << ". " << cargoTypes[i] << std::endl;
	std::cin >> _cargo;
	std::cout << std::endl << "Your cargo-type: " << cargoTypes[_cargo] << std::endl;

	std::cout << std::endl << "Package type: " << std::endl;
	for (int i = 0; i < 3; i++)
		std::cout << i << ". " << packageTypes[i] << std::endl;
	std::cin >> _package;
	std::cout << std::endl << "Your package-type: " << packageTypes[_package] << std::endl;

	std::cout << std::endl << "Vehicle: " << std::endl;
	for (int i = 0; i < 4; i++)
		std::cout << i << ". " << vehiclesArr[i] << std::endl;
	std::cin >> vic_code;
	_vic = vehiclesArr[vic_code];

	std::cout << std::endl << "Country of departure: " << std::endl;
	for (int i = 0; i < 3; i++)
		std::cout << i << ". " << countriesArr[i][0] << std::endl;
	std::cin >> country_choice;
	std::cout << std::endl << "Your country: " << countriesArr[country_choice][0] << ". Now choose the city" << std::endl;
	for (int i = 1; i < 4; i++)
		std::cout << i << ". " << countriesArr[country_choice][i] << std::endl;
	std::cin >> dep_code;
	_dep = countriesArr[country_choice][dep_code];

	std::cout << std::endl << "Country of destination: " << std::endl;
	for (int i = 0; i < 3; i++)
		std::cout << i << ". " << countriesArr[i][0] << std::endl;
	std::cin >> country_choice;
	std::cout << std::endl << "Your country: " << countriesArr[country_choice][0] << ". Now choose the city" << std::endl;
	for (int i = 1; i < 4; i++)
		std::cout << i << ". " << countriesArr[country_choice][i] << std::endl;
	std::cin >> des_code;
	_des = countriesArr[country_choice][des_code];

	//Cargo* ncargo = new Cargo(_cargo, _package, _cap, _wei, _vic, _dep, _des);
	//ncargo->show();
	std::cout << "Norm ili ne? (Y/N)" << std::endl;
	char ch;
	std::cin >> ch;

	switch (ch)
	{
	case 'Y':
		//std::cout << ncargo->calculateCargo() << std::endl;
		break;
	case 'N':
		std::cout << "MENYAI DANNIE TOGDA" << std::endl;
		break;
	default:
		std::cout << "Y/N chego slojnogo 2 letters vibrat??" << std::endl;
		break;
	}

	return true;
}