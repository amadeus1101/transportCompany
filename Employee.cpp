#include "Employee.h"

Employee::Employee() {
	user_ID = -1;
	login = "undefined";
	password = "undefined";
	name = "undefined";
	role = "undefined";
}

Employee::Employee(int _user_ID, std::string _login, std::string _password, std::string _name, std::string _role)
{
	user_ID = _user_ID;
	login = _login;
	password = _password;
	name = _name;
	role = _role;

}
void Employee::menu() {
	std::cout << "this is CUSTOMER menu" << std::endl;
	std::cout << "make order" << std::endl;
	std::cout << "show profile" << std::endl;
	int choice;
	std::cin >> choice;
	switch (choice)
	{
	case 1: std::cout << "order is making..." << std::endl; break;
	case 2: std::cout << "profile is showing..." << std::endl; break;
	default:
		std::cout << "Oshibka vibora" << std::endl;
	}
}
void Employee::show() {
	std::cout << "this is EMPLOYEE SHOW()" << std::endl;
	std::cout << " &&& " << user_ID << " ";
	std::cout << login << " ";
	std::cout << password << " ";
	std::cout << name << " ";
	std::cout << role << std::endl;
	//show history + current applications
}