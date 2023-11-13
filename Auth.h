#pragma once
#include <string>

class Auth {
protected:
	std::string username;
	std::string password;
public:
	void startMenu();
	void validator(std::string, std::string);
	void signUp();
	//signUp for admin with peregruzka
	void signIn();
	void logOut();
};
