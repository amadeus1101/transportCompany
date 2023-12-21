#include "Guest.h"

bool Guest::authorization() {
	std::string _cusernm;
	std::string _cpass;

	std::cout << "AUTHORIZATION: " << std::endl;
	std::cout << "Enter yout data: " << std::endl;
	std::cout << std::endl << "login: ";
	std::cin >> _cusernm;
	std::cout << std::endl << "password: ";
	std::cin >> _cpass;
	return true;
}

bool Guest::registration() {
	
	//UObj->write(_username, _password, _name);
	return true;
}

bool Guest::validate(std::string _uname, std::string _pass) {
	return true;
}

bool Guest::createCargo() {
	return true;
}